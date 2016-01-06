/*

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.

*/

#include <vector>
#include <iostream>

namespace
{

using std::pair;
using std::vector;
using std::cout;
using std::endl;

typedef pair<int, int>   PairType;
typedef vector<PairType> StackType;

class MinStack {
public:
    MinStack(int cap = 100) {
        _stack_internal.reserve(cap);
    }

    void push(int x) {
        auto prev_min = getMin();
        if(x < prev_min) {
            auto new_idx = _stack_internal.size();
            _stack_internal.push_back(pair<int, int>(x, new_idx));
        }
        else {
            PairType &pt = _stack_internal.back();
            _stack_internal.push_back(pair<int, int>(x, pt.second));
        }
    }

    void pop() {
        _stack_internal.pop_back();
    }

    int top() {
        if(_stack_internal.empty()) return -1;
        return _stack_internal.back().first;
    }

    int getMin() {
        if(_stack_internal.empty()) return -1;
        PairType &pt = _stack_internal.back();
        return _stack_internal[pt.second].first;
    }


private:
    // first int is the value, second int is the idx of this vector.
    // which indicate the mininum number in the vector.
    // e.g. stack: {2:0, 1:1, 3:1}
    StackType _stack_internal;
};


} //namespace



int main() {
    auto ms = MinStack();
    cout << "MinStack top: " << ms.top() << endl;
    ms.push(0);
    cout << "MinStack top: " << ms.top() << endl;
    ms.push(2);
    cout << "MinStack top: " << ms.top() << endl;
    ms.push(1);
    cout << "MinStack top: " << ms.top() << endl;
    cout << "MinStack getMin: " << ms.getMin() << endl;

    return 0;
}