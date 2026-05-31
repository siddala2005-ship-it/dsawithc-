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
    int count(Node*root){
        if(root==NULL){
            return 0;
        }
        int left=count(root->left);
        int right=count(root->right);
        return left+right+1;
        
    }

int main(){
    vector<int> nodes = {
    1,2,4,-1,-1,5,-1,6,-1,7,-1,-1,3,-1,-1
};
    Node* root=buildTree(nodes);//1 5 3 -1 -1 19 -1 -1 18 -1 -1 25 -1 -1
    cout<<root->data<<endl;//1
    cout<<"Number of nodes in the tree: "<<count(root)<<endl;
    
    return 0;
}