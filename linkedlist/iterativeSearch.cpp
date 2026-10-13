#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* next;
        Node(int val){
            this->val=val;
            this->next=NULL;
        }
};
class List{
    public:
    Node* head;
    Node* tail;
    int size;
        List(){
            this->head=NULL;
            this->tail=NULL;
            this->size=0;
        }
        void push_front(int val){
            Node* newNode=new Node(val);
            if(head==NULL){
                head=tail=newNode;
            }else{
                newNode->next=head;
                head=newNode;
            }
            size++;
        }
        void print(){
            Node* temp=head;
            while(temp!=NULL){
                cout<<temp->val<<" ";
                temp=temp->next;
            }
        }
        void push_back(int val){
            Node* newNode=new Node(val);
            if(tail==NULL){
                head=tail=newNode;
            }else{
                tail->next=newNode;
                tail=newNode;
            }
            size++;
        }
        int iterativeSearch(int key){
            Node* temp=head;
            int index=0;
            while(temp!=NULL){
                if(temp->val==key){
                    return index;
                }
                temp=temp->next;
                index++;
            }
            return -1;
        }
};
int main(){
    List ll;
    ll.push_front(10);
    ll.push_front(20);
    ll.push_front(30);
    ll.push_front(40);
    cout<<ll.iterativeSearch(30)<<endl;
  

}