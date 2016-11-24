#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack> 
using namespace std;

// Solution 1 : two stacks
class MinStack_2 {
private:
    stack<int> num_st;
    stack<int> min_st;

public:
    MinStack_2() { }
    
    void push(int x) {
        num_st.push(x);
        if (min_st.empty() || x <= min_st.top()) min_st.push(x);
    }
    
    void pop() {
        if (num_st.top() == min_st.top()) min_st.pop();
        num_st.pop();
    }
    
    int top() {
        return num_st.top();
    }
    
    int getMin() {
        return min_st.top();
    }
};


// Solution 2 : one stack, billiant
class MinStack {
private:
    stack<int> st;
    int min = INT_MAX;

public:
    MinStack() { }
    
    void push(int x) {
        if (x <= min) {
            st.push(min); // push old min
            min = x;
        }
        st.push(x);
    }
    
    void pop() {
        int x = st.top(); st.pop();
        if (x == min) {
            min = st.top();
            st.pop();
        }
    }
    
    int top() {
        return st.top(); 
    }
    
    int getMin() {
        return min;
    }
};


int main() {
    return 0;
}

