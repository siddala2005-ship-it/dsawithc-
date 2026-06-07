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
void printInRange(Node*root,int low,int high){
    if(root==NULL){
        return;
    }
    if(root->data >= low && root->data <= high){
        cout<<root->data<<" ";
    }
    if(root->data > low){
        printInRange(root->left,low,high);
    }
    if(root->data < high){
        printInRange(root->right,low,high);
    }
}
int main(){
    int arr[5]={5,1,3,4,2};
    Node*root=buildTree(arr,5);
    inorder(root);
    cout<<endl;
    int low=2,high=4;
    cout<<"Nodes in the range ["<<low<<","<<high<<"] are: ";
    printInRange(root,low,high);    

    return 0;
}