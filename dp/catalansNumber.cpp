#include<iostream>
#include<vector>
using namespace std;
int catalansNumberRec(int n){
    if(n<=1){
        return 1;
    }
    int res=0;
    for(int i=0;i<n;i++){
        res+=catalansNumberRec(i)*catalansNumberRec(n-i-1);
    }
    return res;
}
//MEMOIZATION
int catalansNumberMem(int n,vector<int>&dp){
    if(n<=1){
        return 1;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int res=0;
    for(int i=0;i<n;i++){
        res+=catalansNumberMem(i,dp)*catalansNumberMem(n-i-1,dp);
    }
    return dp[n]=res;
}
//TABULATION
int catalansNumberTab(int n){
    vector<int>dp(n+1,0);
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        for(int j=0;j<i;j++){
            dp[i]+=dp[j]*dp[i-j-1];
        }
    }
    return dp[n];
}
int main(){
    int n=5;
    cout<<catalansNumberRec(n)<<endl;
    vector<int>dp(n+1,-1);
    cout<<catalansNumberMem(n,dp)<<endl;
    cout<<catalansNumberTab(n)<<endl;
}
