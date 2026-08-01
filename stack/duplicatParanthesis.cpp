#include<iostream>
#include<stack>
using namespace std;
bool duplicateParanthesis(string s){
    stack<char> st;
    for(int i=0;i<s.length();i++){
        char ch=s[i];
        if(ch!=')'){
            st.push(ch);
        }
        else{
            int count=0;
            while(st.top()!='('){
                st.pop();
                count++;
            }
            st.pop();
            if(count<1){
                return true;
            }
        }
    }
    return false;
}
int main(){
    string s="((a+b))";
    if(duplicateParanthesis(s)){
        cout<<"Duplicate Paranthesis"<<endl;
    }
    else{
        cout<<"No Duplicate Paranthesis"<<endl;
    }
}