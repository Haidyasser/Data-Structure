#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *next;
    Node *prev;
    Node(int data = 0, Node *next = NULL, Node *prev = NULL) : data(data), next(next), prev(prev) {}
};

class DoubleList {
private:
    Node *head;
    Node *tail;
    int size;
public:
    DoubleList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    ~DoubleList() {
        Node *temp = head;
        while (temp != NULL) {
            Node *temp2 = temp;
            temp = temp->next;
            delete temp2;
        }
    }
    bool isEmpty();
    void AddToHead(int data);
    void AddToTail(int data);
    void AddToPos(int data, int pos);
    void DeleteFromHead();
    void DeleteFromTail();
    void DeleteFromPos(int pos);
    bool Find(int data);
    void PrintList();
    int GetSize();
};

bool DoubleList::isEmpty() {
    return head == NULL;
}

void DoubleList::AddToHead(int data) {
    Node *temp = new Node(data, head, NULL);
    if (head != NULL) {
        head->prev = temp;
    }
    head = temp;
    if (tail == NULL) {
        tail = temp;
    }
    size++;
}

void DoubleList::AddToTail(int data) {
    Node *temp = new Node(data, NULL, tail);
    if (tail != NULL) {
        tail->next = temp;
    }
    tail = temp;
    if (head == NULL) {
        head = temp;
    }
    size++;
}
void DoubleList::AddToPos(int data, int pos) {
    if (pos < 0 || pos > size) {
        cout << "Invalid position" << endl;
        return;
    }
    if (pos == 0) {
        AddToHead(data);
        return;
    }
    if (pos == size) {
        AddToTail(data);
        return;
    }
    Node *temp = new Node(data);
    Node *temp2 = head;
    for (int i = 0; i < pos - 1; i++) {
        temp2 = temp2->next;
    }
    temp->next = temp2->next;
    temp->prev = temp2;
    temp2->next->prev = temp;
    temp2->next = temp;
    size++;
}

void DoubleList::DeleteFromHead() {
    if (isEmpty()) {
        cout << "List is empty" << endl;
        return;
    }
    Node *temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    delete temp;
    size--;
}

void DoubleList::DeleteFromTail() {
    if (isEmpty()) {
        cout << "List is empty" << endl;
        return;
    }
    Node *temp = tail;
    tail = tail->prev;
    if (tail != NULL) {
        tail->next = NULL;
    }
    delete temp;
    size--;
}

void DoubleList::DeleteFromPos(int pos) {
    if (pos < 0 || pos >= size) {
        cout << "Invalid position" << endl;
        return;
    }
    if (pos == 0) {
        DeleteFromHead();
        return;
    }
    if (pos == size - 1) {
        DeleteFromTail();
        return;
    }
    Node *temp = head;
    for (int i = 0; i < pos; i++) {
        temp = temp->next;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
    size--;
}

bool DoubleList::Find(int data) {
    Node *temp = head;
    while (temp != NULL) {
        if (temp->data == data) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void DoubleList::PrintList() {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

}

int DoubleList::GetSize() {
    return size;
}
int main() {
    DoubleList list;
    for(int i = 1; i < 5; i++) {
        list.AddToHead(i);
    }
    for (int i = 5; i < 10; ++i) {
        list.AddToTail(i);
    }
    list.AddToPos(10, 5);
    list.AddToPos(12, 10);
    list.AddToPos(13, 15);
    list.DeleteFromHead();
    list.DeleteFromTail();
    list.DeleteFromPos(5);
    list.DeleteFromPos(10);
    list.DeleteFromPos(15);
    list.PrintList();
    cout << list.Find(1) << endl;
    cout << list.Find(11) << endl;
    cout << list.Find(13) << endl;
    cout << list.GetSize() << endl;
    return 0;
}


