#include<bits/stdc++.h>
using namespace std;        
class Node{
    public:
    int val;
    Node*next;
    Node(int val){
        this->val=val;
        this->next=NULL;
    }

};  
    class List{
    public:
    Node*head;  
    Node*tail;
    List(){
        head=tail=NULL;
    }

    void push_front(int val){
        Node*newNode=new Node(val);
        if(head==NULL){
            head=tail=newNode;
        }else{
            newNode->next=head;
            head=newNode;
        }
    }
    void print(){
        Node*temp=head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }   
    }
    };
    int main(){
        List l;
        l.push_front(10);
        l.push_front(20);
        l.push_front(30);
        l.push_front(40);
        l.push_front(50);
        l.print();
    }