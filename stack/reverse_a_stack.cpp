#include<iostream>
#include<stack>
using namespace std;
void pushAtBottom(stack<int>&s,int val){
    if(s.empty()){
        s.push(val);
        return;
    }
    int topVal=s.top();
    s.pop();
    pushAtBottom(s,val);
    s.push(topVal);
}
void reverseStack(stack<int>&s){
    if(s.empty()){
        return;
    }
    int topVal=s.top();
    s.pop();
    reverseStack(s);
    pushAtBottom(s,topVal);
}
void printStack(stack<int>s){
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
}
int main(){
    stack<int>s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout<<"Original Stack: "<<endl;
    printStack(s);
    reverseStack(s);
    cout<<"Reversed Stack: "<<endl;
    printStack(s);
}