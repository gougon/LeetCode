#include <iostream>
#include <bits/stdc++.h>
#include "../utils/Utils.cpp"

using namespace std;

class MinStack {
public:
    MinStack() {}
    
    void push(int val) {
        if (_s.empty()) {
            _s.push(0);
            _min = val;
        }
        else {
            _s.push(val - _min);
            _min = min(_min, long(val));
        }
    }
    
    void pop() {
        if (_s.top() < 0)
            _min = _min - _s.top();
        _s.pop();
    }
    
    int top() {
        if (_s.top() < 0) 
            return _min;
        else 
            return _min + _s.top();
    }
    
    int getMin() {
        return _min;
    }
private:
    long _min = INT_MIN;
    stack<long> _s;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main(int argc, char *argv[]) {
    MinStack* obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    cout << obj->getMin() << endl;
    obj->pop();
    cout << obj->top() << endl;
    cout << obj->getMin() << endl;
    return 0;
}
