#include<iostream>
#include<vector>
using namespace std;
void fibo(int n,vector<int>&dp){
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
}
int main(){
    int n=5;
    
    vector<int> dp(n+1,-1);
    fibo(n,dp);
    cout<<dp[n]<<endl;
}