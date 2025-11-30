#include <iostream>
#include <stack>
using namespace std;

string reverseString(string str) {
    stack<char> st;
    for(char ch : str)
        st.push(ch);

    string rev = "";
    while(!st.empty()) {
        rev += st.top();
        st.pop();
    }
    return rev;
}

int main() {
    string s = "Hello";
    cout << "Reversed: " << reverseString(s) << endl;
    return 0;
}

