#include<iostream>
#include<stack>
using namespace std;
void stockSpan(int arr[],int n,int span[]){
    stack<int>s;
    for(int i=0;i<n;i++){
        while(!s.empty() && arr[s.top()]<=arr[i]){
            s.pop();
        }
        if(s.empty()){
            span[i]=i+1;
        }
        else{
            span[i]=i-s.top();
        }
        s.push(i);
    }
}
int main(){
    int arr[]={100,80,60,70,60,75,85};
    int n=sizeof(arr)/sizeof(arr[0]);
    int span[n];
    stockSpan(arr,n,span);
    cout<<"Stock Prices: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"Stock Spans: ";
    for(int i=0;i<n;i++){
        cout<<span[i]<<" ";
    }
    cout<<endl;
}