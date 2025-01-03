#pragma once

#include <JuceHeader.h>
#include "PlaylistPanel.h"
#include <fstream>
#include <cmath>

PlaylistPanel::PlaylistPanel(AudioBox* _player1, AudioBox* _player2, AudioFormatManager& _formatManagerToUse, AudioThumbnailCache& cacheToUse) : player1(_player1), player2(_player2), waveformDisplayLeftDeck(_formatManagerToUse, cacheToUse/*, 1*/), waveformDisplayRightDeck(_formatManagerToUse, cacheToUse/*, 2*/) {

    if (File::getCurrentWorkingDirectory().getChildFile("database.json").existsAsFile()) {
        database = File::getCurrentWorkingDirectory().getChildFile("database.json");

        parsedJsonDatabase = juce::JSON::parse(database);
        if (parsedJsonDatabase.isArray()) {
            for (auto item : *parsedJsonDatabase.getArray()) {
                if (auto object = item.getDynamicObject()) {
                    std::string parsedTrackTitle = object->getProperties().getValueAt(0).toString().toStdString();
                    songTitles.push_back(parsedTrackTitle);
                    userFilteredTrackTitles.push_back(parsedTrackTitle);
                    trackTitlesToDuration[parsedTrackTitle] = object->getProperties().getValueAt(1).toString().toStdString();
                    trackTitlesToURLs[parsedTrackTitle] = URL{ object->getProperties().getValueAt(2).toString() };

                }
            }
        }
    }
    else {
        database = File::getCurrentWorkingDirectory().getChildFile("database.json");
        parsedJsonDatabase = juce::JSON::parse(database);
    }

    formatManager.registerBasicFormats();

    addAndMakeVisible(waveformDisplayLeftDeck);
    addAndMakeVisible(waveformDisplayRightDeck);

    playlistWidth = 1280;

    addAndMakeVisible(searchBox);
    addAndMakeVisible(nowPlayingLeftDeckLabel);
    addAndMakeVisible(nowPlayingRightDeckLabel);
    addAndMakeVisible(trackCurrentTimeLeftDeckLabel);
    addAndMakeVisible(trackCurrentTimeRighttDeckLabel);
    addAndMakeVisible(tableComponent);
    addAndMakeVisible(addSongToMyLibraryButton);

    tableComponent.getHeader().addColumn("Track title", 1, playlistWidth / 2 / 2);
    tableComponent.getHeader().addColumn("Duration", 2, playlistWidth / 2 / 2);
    tableComponent.getHeader().addColumn("Play on left deck", 3, playlistWidth / 2 / 3);
    tableComponent.getHeader().addColumn("Play on right deck", 4, playlistWidth / 2 / 3);
    tableComponent.getHeader().addColumn("Remove", 5, playlistWidth / 2 / 3);
    tableComponent.setModel(this);

    nowPlayingRightDeckLabel.setFont(juce::Font(18.0f, juce::Font::bold));
    nowPlayingRightDeckLabel.setText("Now playing: " + rightDeckNowPlaying, juce::dontSendNotification);
    nowPlayingRightDeckLabel.setColour(juce::Label::textColourId, juce::Colours::orange);
    nowPlayingRightDeckLabel.setColour(juce::Label::backgroundColourId, Colours::black);
    nowPlayingRightDeckLabel.setJustificationType(juce::Justification::topLeft);

    nowPlayingLeftDeckLabel.setColour(juce::Label::textColourId, juce::Colours::green);
    nowPlayingLeftDeckLabel.setColour(juce::Label::backgroundColourId, Colours::white);
    nowPlayingLeftDeckLabel.setFont(juce::Font(18.0f, juce::Font::bold));
    nowPlayingLeftDeckLabel.setText("Now playing: " + leftDeckNowPlaying, juce::dontSendNotification);
    nowPlayingLeftDeckLabel.setJustificationType(juce::Justification::topLeft);

    trackCurrentTimeRighttDeckLabel.setFont(Font(18.0f));
    trackCurrentTimeRighttDeckLabel.setText("", juce::dontSendNotification);
    trackCurrentTimeRighttDeckLabel.setColour(juce::Label::textColourId, juce::Colours::orange);
    trackCurrentTimeRighttDeckLabel.setColour(juce::Label::backgroundColourId, Colours::black);
    trackCurrentTimeRighttDeckLabel.setJustificationType(juce::Justification::bottomLeft);

    trackCurrentTimeLeftDeckLabel.setFont(Font(18.0f));
    trackCurrentTimeLeftDeckLabel.setText("", juce::dontSendNotification);
    trackCurrentTimeLeftDeckLabel.setColour(Label::textColourId, juce::Colours::green);
    trackCurrentTimeLeftDeckLabel.setColour(Label::backgroundColourId, Colours::white);
    trackCurrentTimeLeftDeckLabel.setJustificationType(juce::Justification::bottomLeft);

    addSongToMyLibraryButton.setButtonText("Click to add a new file to my library!");
    addSongToMyLibraryButton.setColour(TextButton::buttonColourId, Colours::aquamarine);
    addSongToMyLibraryButton.setColour(TextButton::textColourOnId, Colours::black);
    addSongToMyLibraryButton.setColour(TextButton::textColourOffId, Colours::black);
    addSongToMyLibraryButton.addListener(this);

    searchBox.addListener(this);
    searchBox.setTextToShowWhenEmpty(String{ "Search the library by Typing here...." }, Colours::black);
    searchBox.setColour(TextEditor::textColourId, Colours::black);
    searchBox.setColour(TextEditor::backgroundColourId, Colours::aquamarine);
    searchBox.setFont(juce::Font(15.0f));
    searchBox.setJustification(Justification::centred);

    startTimer(500);
}

PlaylistPanel::~PlaylistPanel()
{
    stopTimer();
}

void PlaylistPanel::paint(juce::Graphics& g)
{
    g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));   // clear the background

    g.setColour(juce::Colours::white);
    g.drawRect(getLocalBounds(), 1);   // draw an outline around the component

    g.setColour(juce::Colours::white);
    g.setFont(14.0f);
}

void PlaylistPanel::resized()
{
    float heightTenth = getHeight() / 10;
    float widthTenth = 1280 / 10;

    tableComponent.setBounds(0, 0, getWidth(), heightTenth * 3);
    searchBox.setBounds(0, heightTenth * 3, getWidth(), 30);
    addSongToMyLibraryButton.setBounds(0, heightTenth * 3 + 30, getWidth(), 30);
    nowPlayingLeftDeckLabel.setBounds(0, heightTenth * 3 + 60, getWidth() / 2, 18);
    nowPlayingRightDeckLabel.setBounds(getWidth() / 2, heightTenth * 3 + 60, getWidth() / 2, 18);
    trackCurrentTimeLeftDeckLabel.setBounds(0, heightTenth * 3 + 78, getWidth() / 2, 20);
    trackCurrentTimeRighttDeckLabel.setBounds(getWidth() / 2, heightTenth * 3 + 78, getWidth() / 2, 20);
    waveformDisplayLeftDeck.setBounds(0, (heightTenth * 3) + 98, getWidth() / 2, (heightTenth * 5) - 27);
    waveformDisplayRightDeck.setBounds(getWidth() / 2, (heightTenth * 3) + 98, getWidth() / 2, (heightTenth * 5) - 27);

    tableComponent.autoSizeAllColumns();
}

int PlaylistPanel::getNumRows() {
    return userFilteredTrackTitles.size();
};

void PlaylistPanel::paintRowBackground(Graphics& g, int rowNumber, int width, int height, bool rowIsSelected) {
    if (rowIsSelected) {
        g.fillAll(Colours::orange);
    }
    else {
        g.fillAll(Colours::lightskyblue);
    }
};

void PlaylistPanel::paintCell(Graphics& g, int rowNumber, int columnId, int width, int height, bool rowIsSelected) {

    if (columnId == 1) {
        g.drawText(userFilteredTrackTitles[rowNumber], 2, 0, width - 4, height, Justification::centredLeft, false);
    };

    if (columnId == 2) {
        g.drawText(trackTitlesToDuration[userFilteredTrackTitles[rowNumber]], 2, 0, width - 4, height, Justification::centredLeft, false);
    };

};

Component* PlaylistPanel::refreshComponentForCell(int rowNumber, int columnId, bool isRowSelected, Component* existingComponentToUpdate) {

    if (columnId == 3) {
        if (existingComponentToUpdate == nullptr) {
            TextButton* button = new TextButton{ "Play on white deck" };
            button->addListener(this);
            button->setColour(TextButton::buttonColourId, Colours::white);
            button->setColour(TextButton::textColourOnId, Colours::black);
            button->setColour(TextButton::textColourOffId, Colours::black);
            button->setComponentID("1" + userFilteredTrackTitles[rowNumber]);
            existingComponentToUpdate = button;
        }
        else {
            TextButton* button = new TextButton{ "Play on white deck" };
            button->addListener(this);
            button->setColour(TextButton::buttonColourId, Colours::white);
            button->setColour(TextButton::textColourOnId, Colours::black);
            button->setColour(TextButton::textColourOffId, Colours::black);
            button->setComponentID("1" + userFilteredTrackTitles[rowNumber]);
            existingComponentToUpdate = button;
        }
    }
    if (columnId == 4) {
        if (existingComponentToUpdate == nullptr) {

            TextButton* button = new TextButton{ "Play on black deck" };
            button->addListener(this);
            button->setColour(TextButton::buttonColourId, Colours::black);
            button->setColour(TextButton::textColourOnId, Colours::white);
            button->setColour(TextButton::textColourOffId, Colours::white);
            button->setComponentID("2" + userFilteredTrackTitles[rowNumber]);
            existingComponentToUpdate = button;
        }
        else {
            TextButton* button = new TextButton{ "Play on black deck" };
            button->addListener(this);
            button->setColour(TextButton::buttonColourId, Colours::black);
            button->setComponentID("2" + userFilteredTrackTitles[rowNumber]);
            existingComponentToUpdate = button;
        }
    }
    if (columnId == 5) {
        if (existingComponentToUpdate == nullptr) {

            TextButton* button = new TextButton{ "Remove from my library" };
            button->addListener(this);
            button->setColour(TextButton::buttonColourId, Colours::red);
            button->setColour(TextButton::textColourOnId, Colours::black);
            button->setColour(TextButton::textColourOffId, Colours::black);
            button->setComponentID(userFilteredTrackTitles[rowNumber]);
            existingComponentToUpdate = button;
        }
        else {
            TextButton* button = new TextButton{ "Remove from my library" };
            button->addListener(this);
            button->setColour(TextButton::buttonColourId, Colours::red);
            button->setColour(TextButton::textColourOnId, Colours::black);
            button->setColour(TextButton::textColourOffId, Colours::black);
            button->setComponentID(userFilteredTrackTitles[rowNumber]);
            existingComponentToUpdate = button;
        }
    }
    return existingComponentToUpdate;
}

void PlaylistPanel::textEditorTextChanged(TextEditor&) {

    std::string searchTerm = searchBox.getText().toStdString();
    std::vector<std::string> auxiliaryCopy;
    std::copy_if(songTitles.begin(), songTitles.end(), std::back_inserter(auxiliaryCopy), [searchTerm](std::string song) {return song.rfind(searchTerm, 0) == 0; });
    userFilteredTrackTitles = auxiliaryCopy;
    tableComponent.updateContent();

};

void PlaylistPanel::buttonClicked(Button* button) {
    if (button == &addSongToMyLibraryButton)
    {
        FileChooser chooser{ "Select a file..." };
        if (chooser.browseForFileToOpen())
        {
            persistentSaveToJsonDatabase(&chooser.getResult());
        }
    }
    else {
        if (button->getComponentID().toStdString().substr(0, 1).compare("1") == 0) {
            //The user wants to play on the white deck

            leftDeckNowPlaying = button->getComponentID().toStdString().substr(1);
            nowPlayingLeftDeckLabel.setText("Now playing:   " + leftDeckNowPlaying, juce::dontSendNotification);

            auto minutes = (int)floor(player1->getPositionRelative() * transportSource.getLengthInSeconds() / 60);
            auto seconds = (int)floor(std::fmod(player1->getPositionRelative() * transportSource.getLengthInSeconds(), 60));
            auto minutesAndSecondsString = std::to_string(minutes) + ":" + std::to_string(seconds);
            trackCurrentTimeLeftDeckLabel.setText(minutesAndSecondsString, juce::dontSendNotification);

            URL url = trackTitlesToURLs[button->getComponentID().toStdString().substr(1)];
            player1->loadURL(url);
            waveformDisplayLeftDeck.loadURL(url);
        }
        else if (button->getComponentID().toStdString().substr(0, 1).compare("2") == 0) {
            //The user wants to play on the black deck

            rightDeckNowPlaying = button->getComponentID().toStdString().substr(1);
            nowPlayingRightDeckLabel.setText("Now playing:  " + rightDeckNowPlaying, juce::dontSendNotification);

            auto minutes = (int)floor(player2->getPositionRelative() * transportSource.getLengthInSeconds() / 60);
            auto seconds = (int)floor(std::fmod(player2->getPositionRelative() * transportSource.getLengthInSeconds(), 60));
            auto minutesAndSecondsString = std::to_string(minutes) + ":" + std::to_string(seconds);
            trackCurrentTimeRighttDeckLabel.setText(minutesAndSecondsString, juce::dontSendNotification);

            URL url = trackTitlesToURLs[button->getComponentID().toStdString().substr(1)];
            player2->loadURL(url);
            waveformDisplayRightDeck.loadURL(url);
        }
        else {
            //The user wants to remove the song from the playlist

            std::vector<std::string> auxiliaryCopyOne;
            std::vector<std::string> auxiliaryCopyTwo;
            std::string songToRemove = button->getComponentID().toStdString();

            std::copy_if(songTitles.begin(), songTitles.end(), std::back_inserter(auxiliaryCopyOne), [songToRemove](std::string song) {return song.compare(songToRemove) != 0; });
            std::copy_if(userFilteredTrackTitles.begin(), userFilteredTrackTitles.end(), std::back_inserter(auxiliaryCopyTwo), [songToRemove](std::string song) {return song.compare(songToRemove) != 0; });
            songTitles = auxiliaryCopyOne;
            userFilteredTrackTitles = auxiliaryCopyTwo;

            trackTitlesToURLs.erase(button->getComponentID().toStdString());
            trackTitlesToDuration.erase(button->getComponentID().toStdString());

            tableComponent.updateContent();

            //remove from parsed db

            database.deleteFile();
            database = File::getCurrentWorkingDirectory().getChildFile("database.json");
            parsedJsonDatabase = JSON::parse(database);

            for (size_t i = 0; i < songTitles.size(); i++)
            {
                auto dinamicObject = std::make_unique<DynamicObject>();
                dinamicObject->setProperty("name", String{ songTitles[i] });

                String savedTrackDurationString = trackTitlesToDuration[songTitles[i]];
                dinamicObject->setProperty("duration", savedTrackDurationString);

                URL savedTrackUrl = trackTitlesToURLs[songTitles[i]];
                dinamicObject->setProperty("url", savedTrackUrl.toString(false));

                auto jsonObject = juce::var(dinamicObject.release());

                parsedJsonDatabase.append(jsonObject);
            }

            ////write the changes in the file            
            FileOutputStream outputFile(database);
            JSON::writeToStream(outputFile, parsedJsonDatabase);

        }
    }

}

bool PlaylistPanel::isInterestedInFileDrag(const StringArray& files) {
    return true;
};

void PlaylistPanel::filesDropped(const StringArray& files, int x, int y) {
    if (files.size() == 1)
    {
        persistentSaveToJsonDatabase(&File{ files[0] });
    }
    else {
        moreThanOnceSongDragAndDroppedAlertWindow.showMessageBox(MessageBoxIconType::InfoIcon, "Operation not permitted", "You can not drag and drop more than one song at a time", String("OK"), nullptr);
    }
};

void PlaylistPanel::persistentSaveToJsonDatabase(File* fileToSave) {

    auto* readFile = formatManager.createReaderFor(URL{ *fileToSave }.createInputStream(false));

    if (readFile != nullptr) {
        std::unique_ptr<AudioFormatReaderSource> newSource(new AudioFormatReaderSource(readFile,
            true));
        transportSource.setSource(newSource.get(), 0, nullptr, readFile->sampleRate);
        readerSource.reset(newSource.release());
    };

    if (!(std::find(songTitles.begin(), songTitles.end(), fileToSave->getFileName().toStdString()) != songTitles.end())) {

        auto minutes = (int)floor(transportSource.getLengthInSeconds() / 60);
        auto seconds = (int)floor(std::fmod(transportSource.getLengthInSeconds(), 60));
        auto minutesAndSecondsString = std::to_string(minutes) + ":" + std::to_string(seconds);

        auto songName = fileToSave->getFileName().toStdString();
        userFilteredTrackTitles.push_back(fileToSave->getFileName().toStdString());
        songTitles.push_back(fileToSave->getFileName().toStdString());

        trackTitlesToDuration[fileToSave->getFileName().toStdString()] = minutesAndSecondsString;
        trackTitlesToURLs[fileToSave->getFileName().toStdString()] = URL{ *fileToSave };


        auto dinamicObject = std::make_unique<DynamicObject>();
        dinamicObject->setProperty("name", fileToSave->getFileName());
        String savedTrackDurationString = minutesAndSecondsString;
        dinamicObject->setProperty("duration", savedTrackDurationString);
        URL savedTrackUrl = URL{ *fileToSave };
        dinamicObject->setProperty("url", savedTrackUrl.toString(false));

        auto jsonObject = juce::var(dinamicObject.release());

        parsedJsonDatabase.append(jsonObject);

        database.deleteFile();
        database = File::getCurrentWorkingDirectory().getChildFile("database.json");

        FileOutputStream outputFile(database);
        JSON::writeToStream(outputFile, parsedJsonDatabase);

        tableComponent.updateContent();
    }
    else {
        songAlreadyAddedAlertWindow.showMessageBox(MessageBoxIconType::InfoIcon, "Operation not permitted", "You can not add a song with the same name of a song that is already in your playlist", String("OK"), nullptr);
    }
}

void PlaylistPanel::timerCallback()
{
    waveformDisplayLeftDeck.setPositionRelative(player1->getPositionRelative() / 100);
    waveformDisplayRightDeck.setPositionRelative(player2->getPositionRelative() / 100);

    auto currentMinutes = (int)floor(player1->getPositionRelative() / 100 * player1->getLengthInSeconds() / 60);
    auto currentSeconds = (int)floor(std::fmod(player1->getPositionRelative() / 100 * player1->getLengthInSeconds(), 60));
    auto totalMinutesDuration = (int)floor(player1->getLengthInSeconds() / 60);
    auto totalSecondsDuration = (int)floor(std::fmod(player1->getLengthInSeconds(), 60));
    auto minutesAndSecondsString = std::to_string(currentMinutes) + ":" + std::to_string(currentSeconds) + " / " + std::to_string(totalMinutesDuration) + ":" + std::to_string(totalSecondsDuration);

    trackCurrentTimeLeftDeckLabel.setText(minutesAndSecondsString, juce::dontSendNotification);

    currentMinutes = (int)floor(player2->getPositionRelative() / 100 * player2->getLengthInSeconds() / 60);
    currentSeconds = (int)floor(std::fmod(player2->getPositionRelative() / 100 * player2->getLengthInSeconds(), 60));
    totalMinutesDuration = (int)floor(player2->getLengthInSeconds() / 60);
    totalSecondsDuration = (int)floor(std::fmod(player2->getLengthInSeconds(), 60));
    minutesAndSecondsString = std::to_string(currentMinutes) + ":" + std::to_string(currentSeconds) + " / " + std::to_string(totalMinutesDuration) + ":" + std::to_string(totalSecondsDuration);
    trackCurrentTimeRighttDeckLabel.setText(minutesAndSecondsString, juce::dontSendNotification);
}
