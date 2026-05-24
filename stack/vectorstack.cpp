#include <iostream>
#include <vector>
using namespace std;
class stack{
    vector<int> ver;
public:
    void push(int x){
        ver.push_back(x);
    }
    void pop(){
        if(ver.empty()){
            cout<<"stack is empty"<<endl; 
            return;
        }
        ver.pop_back();
    }
    bool empty(){
        if(ver.size()==0){ 
            return true;
        }
        return false;
        
    }
    int top(){
        if(ver.empty()){
            cout<<"stack is empty"<<endl; 
        return -1;
        }
        int lastIdx=ver.size()-1;
        return ver[lastIdx];

    }


};
int main(){
    stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
}