#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

string prefixToInfix(string exp){
    stack<string> st;

    for(int i=exp.length()-1; i>=0; i--){
        char ch = exp[i];

        if(isalnum(ch)){
            st.push(string(1,ch));
        } else {
            string a = st.top(); st.pop();
            string b = st.top(); st.pop();
            st.push("(" + a + ch + b + ")");
        }
    }

    return st.top();
}

int main(){
    string prefix;
    cout<<"\nEnter Prefix Expression: ";
    cin>>prefix;
    cout<<"Infix Expression: "<<prefixToInfix(prefix);
    return 0;
}

