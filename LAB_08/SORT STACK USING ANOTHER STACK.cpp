#include <iostream>
#include <stack>
using namespace std;

void sortStack(stack<int> &st){
    stack<int> temp;

    while(!st.empty()){
        int x = st.top();
        st.pop();

        while(!temp.empty() && temp.top() > x){
            st.push(temp.top());
            temp.pop();
        }
        temp.push(x);
    }

    while(!temp.empty()){
        st.push(temp.top());
        temp.pop();
    }
}

int main(){
    stack<int> st;
    st.push(40);
    st.push(10);
    st.push(30);
    st.push(20);

    sortStack(st);

    cout<<"\nSorted Stack (top ? bottom): ";
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}

