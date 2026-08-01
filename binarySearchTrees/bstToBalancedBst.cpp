#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//
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
static int idx=-1;
Node* buildTree(vector<int>& nodes) {
    idx++;
    if (nodes[idx] == -1) {
        return NULL;
    }
    Node* newNode = new Node(nodes[idx]);
    newNode->left=buildTree(nodes);
    newNode->right=buildTree(nodes);
    return newNode;

}
void inorder(Node*root,vector<int>& arr){
    if(root==NULL){
        return;
    }
    inorder(root->left,arr);
    arr.push_back(root->data);  
    inorder(root->right,arr);
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
int main(){
    vector<int> nodes={6,5,4,3,-1,-1,-1,-1,7,-1,8,-1,9,-1,-1};
    Node* root=buildTree(nodes);//1 5 3 -1 -1 19 -1 -1 18 -1 -1 25 -1 -1
    cout<<root->data<<endl;//1
    cout<<"Inorder traversal of the constructed tree: ";
    vector<int> arr;
    inorder(root, arr);
    for(auto i:arr){
        cout<<i<<" ";
    }
    Node*root2=NULL;
    root2=sortedArrayToBST(arr.data(),0,arr.size()-1); //arr.data() returns a pointer to the first element of the vector

    cout<<endl;
    cout<<"Preorder traversal of the balanced BST: ";
    preorder(root2);
    cout<<endl;

    return 0;
}