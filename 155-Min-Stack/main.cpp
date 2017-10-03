#include <iostream>
#include <stack>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        dataStack.push(x);
        if(minStack.empty() || (dataStack.top()<=minStack.top())) {
            minStack.push(x);
        }
    }

    void pop() {
        if(dataStack.top()==minStack.top()) {
            minStack.pop();
        }

        dataStack.pop();
    }

    int top() {
        return dataStack.top();
    }

    int getMin() {
        return minStack.top();
    }

private:
    stack<int> dataStack;
    stack<int> minStack;
};

int main() {
    MinStack minStack;

    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);

    cout << minStack.getMin()<<endl;

    minStack.pop();
    cout << minStack.top()<<endl;
    cout << minStack.getMin() << endl;

    return 0;
}