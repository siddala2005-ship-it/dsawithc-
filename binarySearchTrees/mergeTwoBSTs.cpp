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
void inorder(Node*root,vector<int>& arr){
    if(root==NULL){
        return;
    }
    inorder(root->left,arr);
    arr.push_back(root->data);
    inorder(root->right,arr);
}
Node*buildTree(int arr[],int n){
    Node*root=NULL;

    for(int i=0;i<n;i++){
        root=insert(root,arr[i]);
    }
    return root;
}
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

Node* mergebst(Node*root1,Node*root2){
    vector<int> arr1;
    vector<int> arr2;
    vector<int> merged;
    inorder(root1, arr1);
    inorder(root2, arr2);
    int i=0,j=0;    
    while(i<arr1.size() && j<arr2.size()){
        if(arr1[i]<arr2[j]){
            merged.push_back(arr1[i]);
            i++;
        }
        else{
            merged.push_back(arr2[j]);
            j++;
        }
        
    }
    while(i<arr1.size()){
        merged.push_back(arr1[i]);
        i++;
    }
    while(j<arr2.size()){
        merged.push_back(arr2[j]);
        j++;
    }
    
   return sortedArrayToBST(merged.data(), 0, merged.size() - 1);
}
int main(){
    Node*root1=new Node(2);
    root1->left=new Node(1);
    root1->right=new Node(4);
    Node*root2=new Node(9);
    root2->left=new Node(3);
    root2->right=new Node(12);
   Node*root=mergebst(root1,root2);

    preorder(root);
    return 0;
}