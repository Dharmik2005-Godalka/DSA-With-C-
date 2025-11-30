#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(string exp) {
    stack<char> st;
    
    for(char ch : exp) {
        if (ch == '(' || ch == '{' || ch == '[')
            st.push(ch);
        else {
            if (st.empty()) return false;
            char top = st.top();
            if ((ch == ')' && top == '(') ||
                (ch == '}' && top == '{') ||
                (ch == ']' && top == '['))
                st.pop();
            else
                return false;
        }
    }
    return st.empty();
}

int main() {
    string s = "{[(())]}";
    cout << (isBalanced(s) ? "Balanced" : "Not Balanced") << endl;
    return 0;
}

