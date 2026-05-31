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
    int height(Node*root){
        if(root==NULL){
            return 0;
        }
        int left=height(root->left);
        int right=height(root->right);
        return max(left,right)+1;
        
    }

int main(){
    vector<int> nodes = {
    1,2,4,-1,-1,5,-1,6,-1,7,-1,-1,3,-1,-1
};
    Node* root=buildTree(nodes);//1 5 3 -1 -1 19 -1 -1 18 -1 -1 25 -1 -1
    cout<<root->data<<endl;//1
    cout<<"Height of the tree: "<<height(root)<<endl;
    
    return 0;
}