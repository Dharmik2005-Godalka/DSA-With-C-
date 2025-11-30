#include <iostream>
#include <stack>
using namespace std;

string reverseWords(string sentence) {
    stack<string> st;
    string word = "";

    for(char ch : sentence) {
        if (ch == ' ') {
            st.push(word);
            word = "";
        } else {
            word += ch;
        }
    }
    st.push(word);

    string reversed = "";
    while(!st.empty()) {
        reversed += st.top();
        st.pop();
        if (!st.empty()) reversed += " ";
    }
    return reversed;
}

int main() {
    string sentence = "I love icecream";
    cout << "Reversed Sentence: " << reverseWords(sentence) << endl;
    return 0;
}

