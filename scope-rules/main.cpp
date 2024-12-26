#include <iostream>

using namespace std;
const float PI = 3.14589;
int a = 10;
int add(int x,int y);
int main() {
    cout<<"upon entering in function scope global a = "<<a<<endl;
    int a = 4;
    int b = 6;
    int c = 0;
    cout<<"After creation of a in function scope local a = "<<a<<endl;
    cout<<"global a in function scope a = "<<::a<<endl;
    {
        cout<<"Upon entering local  scope a = "<<a<<endl;
        int a = 8;
        cout<<"after creation of a in local  scope a = "<<a<<endl;
        cout<<"global a in function scope a = "<<::a<<endl;
    }
    cout<<"function scope a = "<<a<<endl;


    return 0;
}
int add(int x,int y){
    cout<<PI;
    return x+y;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.