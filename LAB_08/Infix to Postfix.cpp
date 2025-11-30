#include <iostream>
#include <algorithm>
#include <stack>
#include <cctype>
using namespace std;

int precedence(char c){
    if(c=='^') return 3;
    if(c=='*' || c=='/') return 2;
    if(c=='+' || c=='-') return 1;
    return -1;
}

string infixToPostfix(string s){
    stack<char> st;
    string res="";
    for(char ch:s){
        if(isalnum(ch))
            res+=ch;
        else if(ch=='(')
            st.push(ch);
        else if(ch==')'){
            while(st.top()!='('){
                res+=st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty() && precedence(ch)<=precedence(st.top())){
                res+=st.top();
                st.pop();
            }
            st.push(ch);
        }
    }
    while(!st.empty()){
        res+=st.top();
        st.pop();
    }
    return res;
}

string infixToPrefix(string exp){
    reverse(exp.begin(), exp.end());

    for(char &c: exp){
        if(c=='(') c=')';
        else if(c==')') c='(';
    }

    string result=infixToPostfix(exp);
    reverse(result.begin(), result.end());
    return result;
}

int main(){
    string exp;
    cout<<"\nEnter Infix Expression: ";
    cin>>exp;

    cout<<"Prefix Expression: "<<infixToPrefix(exp);
    return 0;
}

