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
bool isBST(Node*root,Node*min=NULL,Node*max=NULL){
    if(root==NULL){
        return true;
    }
    if(min!=NULL && root->data <= min->data){
        return false;
    }
    if(max!=NULL && root->data >= max->data){
        return false;
    }
    bool leftValid=isBST(root->left,min,root);
    bool rightValid=isBST(root->right,root,max);
    return leftValid && rightValid;
}
int main(){
    int arr[5]={5,1,3,4,2};
    Node*root=buildTree(arr,5);
    inorder(root);
    cout<<endl;
    if(isBST(root)){
        cout<<"The tree is a valid BST."<<endl;
    }
    else{
        cout<<"The tree is not a valid BST."<<endl;
    }
    return 0;
}
