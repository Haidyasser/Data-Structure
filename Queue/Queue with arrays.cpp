#include <bits/stdc++.h>
using namespace std;

#define cin(v, n)       for (int cn = 0; cn < n; cn++) cin >> v[cn];
#define cout(v)         for(auto&cnt:v) cout << cnt << " ";
#define ll long long

const int siz = 10;

class Queue{
private:
    int data[siz];
    int front, rear;
public:
    Queue(){
        front = rear = 0;
    }
    int Length();
    void push(int item);
    int pop();
    int Front();
    vector <int> dequeueN(int n);
    int searchqueue(int target);
    void enqueueN(int arr[], int n);
    void display();
};

int Queue::Length() {
    return rear - front;
}

int Queue::Front() {
    return data[front];
}
void Queue::push(int item) {
    if(rear + 1 == siz)
        return void(cout << "stack overflow\n");
    data[rear++] = item;
}

int Queue::pop() {
    if(Length() == 0) {
        cout << "satck underflow\n";
        exit(1);
    }
    return data[front++];
}
// enqueue n elements
void Queue::enqueueN(int *arr, int n) {
    int idx = 0;
    while(rear < siz && idx < n){
        data[rear++] = arr[idx++];
    }
    if(idx < n)
        return void(cout << "stack overflow\n");
}
// dequeue n elements
vector<int> Queue::dequeueN(int n) {
    vector < int > ans;
    if(n == 0)
        return ans;
    while(front < rear && --n){
        ans.push_back(data[front++]);
    }
    if(n){
        front = rear = 0;
        cout << "satck underflow\n";
        exit(1);
    }
    return ans;
}

int Queue::searchqueue(int target) {
    int idx = 1;
    for(int i = front; i < rear; i++){
        if(data[i] == target)
            return idx;
        idx++;
    }
    return -1;
}

void Queue::display() {
    if(Length() == 0){
        cout << "the queue is empty\n";
        return;
    }
    for(int i = front; i < rear; i++)
        cout << data[i] << " ";
    cout << '\n';
}
int main()
{
    Queue q;
    q.push(5);
    q.push(8);
    cout << q.pop() << '\n';
    q.push(9);
    int arr[] = {1,2, 3, 4, 5};
    q.enqueueN(arr, 5);
    cout << q.searchqueue(8) << '\n';
    q.display();
    cout(q.dequeueN(4));
    cout << q.pop();
    return 0;
}
