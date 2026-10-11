#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int val;
    Node*next;
    Node(int val){
        this->val=val;
        next=NULL;
        
    }

};
class List{
    Node*head;
    Node*tail;
    public:
    List(){
        head=tail=NULL;
    }
    void printlist(){
        Node*temp=head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    void push_front(int val){
        if(head==NULL){
            Node*newNode=new Node(val);
            head=tail=newNode;
        }
        else{
            Node*newNode=new Node(val);
            newNode->next=head;
            head=newNode;
        }
    }
    void push_back(int val){
        if(head==NULL){
            Node*newNode=new Node(val);
            head=tail=newNode;
        }
        else{
            Node*newNode=new Node(val);
            tail->next=newNode;
            tail=newNode;
        }
    }
    void delete_pos(int pos){
        Node*temp=head;
        for(int i=0;i<pos-1;i++){
            temp=temp->next;
        }
        temp->next=temp->next->next;
        temp->next=NULL;
    }
};

int main(){
    List ll;
    ll.push_front(10);
    ll.push_front(20);
    ll.push_front(30);
    ll.printlist();
    ll.delete_pos(2);
    ll.printlist();
}