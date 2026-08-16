#include <limits.h>

class MinStack {
private:
    vector<int> _stack;
    vector<int> _minstack;
    int min;
public:
    MinStack(){
        min = INT_MIN;
    }
    
    void push(int val) {
         _stack.push_back(val);
        if (_minstack.empty())
            _minstack.push_back(val);
        else if (_minstack[_minstack.size() - 1] > val)
            _minstack.push_back(val);
        else
            _minstack.push_back(_minstack[_minstack.size() - 1]);
    }
    
    void pop() {
        _stack.pop_back();
        _minstack.pop_back();
    }
    
    int top() {
        return (_stack[_stack.size() - 1]);
    }
    
    int getMin() {
        return (_minstack[_minstack.size() - 1]);
    }
};
