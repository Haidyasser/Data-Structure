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
            Node* temp = p -> next;
            delete p;
            p = temp;
        }
        head = NULL;
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
        Node* p = head;
        if(!p) return;
        while(p -> next){
            p = p ->next;
        }
        p -> next = new Node(data);
    }
    bool findNode(int value){
        if(isEmpty())
            return 0;
        Node* p = head;
        while(p && p ->data != value)
            p = p -> next;
        if(!p) {
            return 0;
        }
        return 1;
    }
    // count Length
    int Length(){
        Node* p = head;
        int cnt = 0;
        while(p){
            cnt++;
            p = p->next;
        }
        return cnt;
    }

    int DeleteFromHead(){
        if (isEmpty()) {
            cout << "List is empty";
            exit(1);
        }
        Node* p = head;
        head = head -> next;
        int data = p -> data;
        delete p;
        return data;
    }
    int DeleteFromTail(){
        if (isEmpty()) {
            cout << "List is empty";
            return -1;
        }
        int data = 0;
        Node* p = head;
        if(!p -> next){
            data = p -> data;
            head = NULL;
            delete p;
            return data;
        }
        while(p -> next -> next != NULL)
            p = p -> next;
        Node* q = p -> next;
        p -> next = NULL;
        data = q -> data;
        delete q;
        return data;
    }


    void DelAtpos(int position){
        if (position < 0 or position >= Length()) {
            cout << "Index out of bound" << "\n";
            return;
        }
        if(position == 0)
            DeleteFromHead();
        else if(position == Length() - 1)
            DeleteFromTail();
        else{
            Node *p = head;
            for (int i = 1; i < position; i++)
                p = p -> next;
            Node *q = p -> next;
            p -> next = q -> next;
            delete q;
        }
    }
// delete the node that after a node that has the specified value
    void DelAfter(int val){
        Node *p = head;
        if(!findNode(val)){
            cout << "there is no node having this value\n";
            return;
        }
        while(p -> data != val){
            p = p -> next;
        }
        Node* q = p -> next;
        p -> next = NULL;
        while(q){
            p = q -> next;
            delete q;
            q = p;
        }
    }
// update the node at position to the new value
    void Update(int position , int newvalue){
        if (position < 0 or position >= Length()) {
            cout << "Index out of bound" << "\n";
            return;
        }
        Node* p = head;
        for(int i = 0; i < position; i++){
            p = p -> next;
        }
        p -> data = newvalue;
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
    int getMinimum(){
        if(isEmpty()){
            cout << "Empty List" << endl;
            return -1;
        }
        Node* p = head;
        int mn = p -> data;
        while(p){
            mn = min(mn, p -> data);
            p = p -> next;
        }
        return mn;
    }
    int sumOdd(){
        if(isEmpty())
            return 0;
        Node* p = head;
        int sum = 0;
        while(p){
            if(p -> data % 2 == 1)
                sum += p -> data;
            p = p -> next;
        }
        return sum;
    }
    void copyList(LinkedList& NewList){
        Node *p = head, *q = NewList.head;
        while(p){
            if(q == NULL){
                NewList.head = new Node(p -> data);
                q = NewList.head;
            }else {
                q -> next = new Node(p -> data);
                q = q -> next;
            }
            p = p -> next;
        }
    }
};

int main()
{
    freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
    LinkedList l1;
    l1.print();
    l1.AddToHead(3);
    l1.AddToHead(5);
    l1.print();
    l1.DelAfter(5);
    l1.AddToTail(4);
    l1.AddToTail(1);
    l1.print();
    cout << l1.Length() << endl;
    cout << l1.getMinimum() << endl;
    cout << l1.sumOdd() << endl;
    LinkedList l2;
    l1.copyList(l2);
    l2.print();
    return 0;
}
