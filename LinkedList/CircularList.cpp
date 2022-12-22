#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
class Node{
public:
    int data;
    Node* next;

    Node(int _data = 0, Node* _next = NULL){
        data = _data;
        next = _next;
    }

};
class CircularList{
private:
    Node* head;
public:
    CircularList(){
        head = NULL;
    }
    ~CircularList(){
        Node* p = head;
        while(p){
            Node* temp = p -> next;
            delete p;
            p = temp;
        }
        head = NULL;
        cout << "List Deleted" << endl;
    }
    bool isEmpty();
    void AddToHead(int data);
    void AddToTail(int data);
    bool findNode(int value);
    int Length();
    void printList();
    void DeleteNode(int value);
    void DeleteHead();
    void DeleteTail();

};

bool CircularList::isEmpty() {
    return head == NULL;
}
void CircularList::AddToHead(int data) {
    Node* newNode = new Node(data);
    if(!head){
        head = newNode;
        head -> next = head;
        return;
    }
    Node* p = head;
    while(p -> next != head)
        p = p -> next;
    p -> next = newNode;
    newNode -> next = head;
    head = newNode;
}
void CircularList::AddToTail(int data) {
    Node* newNode = new Node(data);
    if(!head){
        head = newNode;
        head -> next = head;
        return;
    }
    Node* p = head;
    while(p -> next != head)
        p = p -> next;
    p -> next = newNode;
    newNode -> next = head;
}
bool CircularList::findNode(int value) {
    if(isEmpty())
        return -1;
    Node* p = head;
    while(p && p ->data != value)
        p = p -> next;
    if(!p) {
        return -1;
    }
    return 1;
}
int CircularList::Length() {
    if(isEmpty())
        return 0;
    Node* p = head;
    int count = 0;
    while(p -> next != head){
        count++;
        p = p -> next;
    }
    return count + 1;
}
void CircularList::printList() {
    if(isEmpty())
        return;
    Node* p = head;
    while(p -> next != head){
        cout << p -> data << " ";
        p = p -> next;
    }
    cout << p -> data << endl;
}
void CircularList::DeleteNode(int value) {
    if(isEmpty())
        return;
    Node* p = head;
    Node* prev = NULL;
    while(p -> next != head && p -> data != value){
        prev = p;
        p = p -> next;
    }
    if(p -> data != value)
        return;
    if(p == head){
        DeleteHead();
        return;
    }
    if(p -> next == head){
        DeleteTail();
        return;
    }
    prev -> next = p -> next;
    delete p;
}
void CircularList::DeleteHead() {
    if(isEmpty())
        return;
    Node* p = head;
    while(p -> next != head)
        p = p -> next;
    p -> next = head -> next;
    delete head;
    head = p -> next;
}
void CircularList::DeleteTail() {
    if(isEmpty())
        return;
    Node* p = head;
    Node* prev = NULL;
    while(p -> next != head){
        prev = p;
        p = p -> next;
    }
    prev -> next = head;
    delete p;
}
int main()
{
    CircularList list;
    for(int i = 1; i <= 10; i++){
        list.AddToHead(i);
    }
    list.printList();
    list.DeleteNode(1);
    list.printList();
    list.DeleteNode(10);
    list.printList();
    list.DeleteNode(5);
    list.printList();
    return 0;
}
