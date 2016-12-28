#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack> 
using namespace std;

// Ternary expression is right-bind, 
// So we scan from back to front to evaluate each meta expression.
// We recognize the expression with the '?'.


// Solution 1 : stack
class Solution {
public:
    string parseTernary(string expression) {
        int n = expression.size();
        stack<char> st;
        for (int i = n-1; i >= 0; --i) {
            char c = expression[i];
            if (!st.empty() && st.top() == '?') {
                st.pop(); // pop '?'
                char left = st.top(); st.pop(); // get left value
                st.pop(); // pop ':'
                char right = st.top(); st.pop(); // get right value
                st.push(c == 'T' ? left : right); // push the value of current single ternary expression
            } else st.push(c);
        }
        return string(1, st.top());
    }
};


// Solution 2 : brute-force evaluate
class Solution_2 {
public:
    string parseTernary(string expression) {
        while ((int)expression.size() > 1) {
            auto pos = expression.find_last_of('?');
            expression = expression.substr(0, pos-1) + (expression[pos-1] == 'T' ? expression[pos+1] : expression[pos+3]) + expression.substr(pos+4);
        }
        return string(1, expression[0]);
    }
};


int main() {
    Solution_2 s;
    cout << s.parseTernary("T?2:3") << endl;
    cout << s.parseTernary("F?1:T?4:5") << endl;
    cout << s.parseTernary("T?T?F:5:3") << endl;
    cout << s.parseTernary("T?T:F?T?1:2:F?3:4") << endl;
    return 0;
}
