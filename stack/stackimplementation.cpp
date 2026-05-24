#include <iostream>
#include <vector>
using namespace std;
template<class T>
class stack{
    vector<T> ver;
public:
    void push(T x){
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
    T top(){
        if(ver.empty()){
            cout<<"stack is empty"<<endl; 
        return T();
        }
        int lastIdx=ver.size()-1;
        return ver[lastIdx];

    }


};
int main(){
    stack<int> s; //stack<string> s; // for string stack //stack<double> s; // for double stack //stack<char> s; // for char stack //stack<float> s; // for float stack//stack<bool> s; // for bool stack//
    s.push(10); //s.push("Hello"); // for string stack //s.push(3.14); // for double stack //s.push('A'); // for char stack //s.push(3.14f); // for float stack//s.push(true); // for bool stack//
    s.push(20);
    s.push(30);
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
}