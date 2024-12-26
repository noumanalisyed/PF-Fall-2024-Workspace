#include <iostream>

class Node{
public:
        Node() = default;
        Node(int d):data(d){
            next = NULL;
        }
        int getData(){
            return data;
        }
        Node * getNext(){
            return next;
        }
        void setNext(Node *n){
            next = n;
        }
        void setData(int d){
            data = d;
        }
        int getIndex(){
            return index;
        }
        void setIndex(int d){
            index = d;
        }
        void display(){
            std::cout<<"Index = "<<index<<" , data = "<<data<<"  ";
        }

private:
    int index {0};
    int data {0};
    Node * next {NULL};
};

class List{
public:
    List() = default;
    void insertAtStart(int d){
        Node * n = new Node(d);
        if(head == NULL){
            head = n;
        } else{
            n->setNext(head);
            head = n;
        }
        size++;
        applyIndex();
    }
    void applyIndex(){
        int index = 1;
        Node * temp = head;
        while (temp != NULL){
            temp->setIndex(index++);
            temp = temp->getNext();
        }
    }
    void insertAtEnd(int d){
        Node * n = new Node(d);
        if(head == NULL){
            head = n;
        } else{
            Node * temp = head;
            while (temp->getNext() != NULL){
                temp = temp->getNext();
            }
            temp->setNext(n);
        }
        size++;
        applyIndex();
    }
    void display(){
        Node * temp = head;
        while (temp != NULL){
            temp->display();
            temp = temp->getNext();
        }
        std::cout<<"Size = "<<size<<std::endl;
    }
private:
    Node * head {NULL};
    int size {0};
};
int main() {
List list;
list.insertAtEnd(10);
list.insertAtEnd(20);
list.insertAtEnd(30);
list.display();
std::cout<<std::endl;
list.insertAtEnd(40);
list.insertAtEnd(50);
list.display();
std::cout<<std::endl;
list.insertAtStart(5);
list.display();
return 0;
}
