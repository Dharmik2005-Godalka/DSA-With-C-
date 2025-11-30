#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

string postfixToInfix(string exp){
    stack<string> st;

    for(char ch: exp){
        if(isalnum(ch)){
            st.push(string(1,ch));
        } else {
            string b = st.top(); st.pop();
            string a = st.top(); st.pop();
            st.push("(" + a + ch + b + ")");
        }
    }
    return st.top();
}

int main(){
    string postfix;
    cout<<"\nEnter Postfix Expression: ";
    cin>>postfix;
    cout<<"Infix Expression: "<<postfixToInfix(postfix);
    return 0;
}

