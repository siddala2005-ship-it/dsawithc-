#include <iostream>
#include <vector>
#include<list>
using namespace std;
template<class T>
class stack{
    list<T>ll;
public:
    void push(T x){
        ll.push_front(x);
    }
    void pop(){
        if(ll.empty()){
            cout<<"stack is empty"<<endl; 
            return;
        }
        ll.pop_front();
    }
    bool empty(){
        if(ll.size()==0){ 
            return true;
        }
        return false;
        
    }
    T top(){
        if(ll.empty()){
            cout<<"stack is empty"<<endl; 
        return T();
        }
        return ll.front();

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