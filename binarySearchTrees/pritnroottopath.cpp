#include<iostream>
#include<vector>
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
void rootToLeaf(Node*root,vector<int>&path){
    if(root==NULL){
        return;
    }
    path.push_back(root->data);
    if(root->left==NULL && root->right==NULL){
        for(int i=0;i<path.size();i++){
            cout<<path[i]<<" ";
        }
        cout<<endl;
    }
    rootToLeaf(root->left,path);
    rootToLeaf(root->right,path);
    path.pop_back();
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
    cout<<endl;
    vector<int>path;
    rootToLeaf(root,path);
     

    return 0;
}