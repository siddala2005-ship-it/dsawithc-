#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};


Node* sortedArrayToBST(int arr[],int start,int end){
    if(start>end){
        return NULL;
    }
    int mid=(start+end)/2;
    Node* newNode=new Node(arr[mid]);
    newNode->left=sortedArrayToBST(arr,start,mid-1);
    newNode->right=sortedArrayToBST(arr,mid+1,end);
    return newNode;
}
 void preorder(Node*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main(){
    int arr[7]={3,4,5,6,7,8,9};
    Node*root=sortedArrayToBST(arr,0,6);
    
    cout<<endl;
    preorder(root);
    cout<<endl;
    return 0;
}