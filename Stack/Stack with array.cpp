#include <bits/stdc++.h>
using namespace std;
#define cin(v, n)       for (int cn = 0; cn < n; cn++) cin >> v[cn];
#define cout(v)         for(auto&cnt:v) cout << cnt << " ";
#define ll long long

const int siz = 10;
class Stack{
private:
    int data[siz];
    int top;
public:
    Stack(){
        top = 0;
    }
    bool isEmpty();
    bool isFull();
    void push(int);
    int pop();
    int searchstack(int);
    bool isPalindrome();
};

bool Stack::isEmpty() {
    return top == 0;
}

bool Stack::isFull() {
    return top == siz;
}

void Stack::push(int item) {
    if(isFull())
       return void(cout << "Stack overflow");
    data[top++] = item;
}

int Stack::pop() {
    if(isEmpty()){
        cout << "Stack underflow";
        exit(2);
    }
    return data[--top];
}

int Stack::searchstack(int item) {
    int cnt = 0;
    for(int i = 0; i < top; i++)
        if(data[i] == item)
            return i + 1;
    return -1;
}

bool Stack::isPalindrome() {
    int i = 0, j = top - 1;
    while(i < j){
        if(data[i++] != data[j--])
            return 0;
    }
    return 1;
}
int main()
{
    Haidy();
    Stack s;
    for(int i = 0; i < 5; i++)
        s.push(i + 1);
    cout << s.searchstack(3) << " ";
    while(!s.isEmpty()){
        cout << s.pop() << " ";
    }
    cout << s.isPalindrome();
    return 0;
}
