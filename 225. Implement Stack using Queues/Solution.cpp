#include <bits/stdc++.h>
using namespace std;

class MyStack {
public:
    queue <int>* q;

    MyStack() {
        q = new queue <int>;
    }
    
    void push(int x) {
        int n = q -> size();
        q -> push(x);

        for(int i = 0; i < n; ++i){
            q -> push(q -> front());
            q -> pop();
        }
    }
    
    int pop() {
        int x = q -> front();
        q -> pop();
        return x;
    }
    
    int top() {
        return q -> front();
    }
    
    bool empty() {
        return q -> empty();
    }

    ~MyStack() {
        delete q;
    }
};