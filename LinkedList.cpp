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
class LinkedList{
    private:
    Node* head;
    public:
    LinkedList(){
        head = NULL;
    }
    ~LinkedList(){
        Node* p = head;
        while(p){
            p = p->next;
            delete head;
            head = p;
        }
        cout << "List Deleted" << endl;
    }
    bool isEmpty(){
        return head == NULL;
    }
    void AddToHead(int data){
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
    void AddToTail(int data){
        Node* NewNode = new Node(data);
        Node* p = head;
        if(!p) return;
        while(p -> next){  
            p = p ->next;
        }
        p -> next = NewNode;
    }
    void findNode(int value){
        Node* p = head;
        while(p ->data != value && p -> next)
            p = p -> next;
        if(!p -> next)
            cout << "there is no node having this value\n";
        else    
            cout << value << '\n';
    }
    int DeleteFromHead(){
        Node* p = head;
        head = head -> next;
        int data = p -> data;
        delete p;
        return data;
    }
    int DeleteFromTail(){
        Node* p = head;
        while(p -> next -> next != NULL)
            p = p -> next;
        Node* q = p -> next;
        p -> next = NULL;
        int data = q -> data;
        delete q;
        return data;
    }
    void print(){
        Node* p = head;
        if(isEmpty()){
            cout << "Empty List" << endl;
            return;
        }
        while(p){
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
    int countList(){
        Node* p = head;
        int cnt = 0;
        while(p){
            cnt++;
            p = p->next;
        }
        return cnt;
    }
    int getMinimum(){
        Node* p = head;
        int mn = p -> data;
        while(p){
            mn = min(mn, p -> data);
            p = p -> next;
        }
        return mn;
    }
    int sumOdd(){
        Node* p = head;
        int sum = 0;
        while(p){
            if(p -> data % 2 == 1)
                sum += p -> data;
            p = p -> next;
        }
        return sum;
    }
    LinkedList copyList(){
        Node* p = head;
        LinkedList* NewList = new LinkedList();
        while(p){
            NewList -> AddToTail(p -> data);
            p = p -> next;
        }
        return *NewList;
    }

};

int main()    
{
    LinkedList l1;
    l1.print();
    l1.AddToHead(3);
    l1.AddToHead(5);
    l1.AddToTail(4);
    l1.AddToTail(1);
    l1.print();
    l1.DeleteFromHead();
    l1.DeleteFromTail();
    l1.print();
    cout << l1.countList() << endl;
    cout << l1.getMinimum() << endl;
    cout << l1.sumOdd() << endl;
    l1.copyList();
    return 0;           
}
