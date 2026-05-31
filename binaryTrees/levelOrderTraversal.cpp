#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
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
    void levelOrder(Node*root){
    if(root==NULL){
        return;
    }
    std::queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* current=q.front();
        q.pop();
        cout<<current->data<<" ";
        if(current->left!=NULL){
            q.push(current->left);
        }
        if(current->right!=NULL){
            q.push(current->right);
        }
    }
}
int main(){
    vector<int> nodes = {
    1,
    5,
    3, -1, -1,
    19, -1, -1,
    18,
    25, -1, -1,
    -1
};
    Node* root=buildTree(nodes);//1 5 3 -1 -1 19 -1 -1 18 -1 -1 25 -1 -1
    cout<<root->data<<endl;//1
    cout<<"Level-order traversal: ";
    levelOrder(root);
    cout<<endl;
    return 0;
}
