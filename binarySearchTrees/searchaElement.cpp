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
Node*insert(Node*root,int val){
    if(root==NULL){
        root=new Node(val);
        return root;

    }
    if(root->data > val){
    root->left=insert(root->left,val);
    }
    else{
    root->right=insert(root->right,val);
    }
    return root;

}

void inorder(Node*root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
Node*buildTree(int arr[],int n){
    Node*root=NULL;

    for(int i=0;i<n;i++){
        root=insert(root,arr[i]);
    }
    return root;
}
bool search(Node*root,int key){
    if(root==NULL){
        return false;
    }
    if(root->data==key){
        return true;
    }
    if(root->data > key){
        return search(root->left,key);
    }
    else{
        return search(root->right,key);
    }
}

int main(){
    int arr[5]={5,1,3,4,2};
    Node*root=buildTree(arr,5);
    inorder(root);
    cout<<endl;
    bool result=search(root,3);
    if(result){
        cout<<"Element found"<<endl;
    }
    else{
        cout<<"Element not found"<<endl;
    }
    return 0;
}