#include<bits/stdc++.h>
#include<list>
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

};
int main(){
    List ll;
    ll.push_front(10);
    ll.push_front(20);
    ll.push_front(30);
    ll.printlist();
//the output of the linked list is not implemented yet, so we will just print a message indicating that the linked list has been created with values.
//lets print the ouput of linked list values


    
}