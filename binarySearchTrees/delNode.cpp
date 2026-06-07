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
Node*delNode(Node*root,int key){
    if(root==NULL){
        return NULL;
    }
    if(root->data > key){
        root->left=delNode(root->left,key);
    }
    else if(root->data < key){
        root->right=delNode(root->right,key);
    }
    else{
        //case 1: no child
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        //case 2: one child
        else if(root->left==NULL){
            Node*temp=root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL){
            Node*temp=root->left;
            delete root;
            return temp;
        }
        //case 3: two children
        Node*temp=root->right;
        while(temp->left!=NULL){
            temp=temp->left;
        }
        root->data=temp->data;
        root->right=delNode(root->right,temp->data);
    }
    return root;

}
Node*buildTree(int arr[],int n){
    Node*root=NULL;

    for(int i=0;i<n;i++){
        root=insert(root,arr[i]);
    }
    return root;
}
int main(){
    int arr[5]={5,1,3,4,2};
    Node*root=buildTree(arr,5);
    inorder(root);
    root=delNode(root,3);
    cout<<endl;
    inorder(root);
    return 0;
}