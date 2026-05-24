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
int main(){
    stack<int>s;
    s.push(10);
    s.push(20);
    s.push(30);
    pushAtBottom(s,5);
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
}