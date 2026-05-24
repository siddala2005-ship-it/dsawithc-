#include<iostream>
#include<stack>
using namespace std;
void reverseString(string &str){
    
    stack<char>s;
    for(int i=0;i<str.size();i++){
        s.push(str[i]);
    }
    for(int i=0;i<str.size();i++){
        str[i]=s.top();
        s.pop();
    }
}
int main(){
    string str="Hello World";
    cout<<"Original String: "<<str<<endl;
    reverseString(str);
    cout<<"Reversed String: "<<str<<endl;
}