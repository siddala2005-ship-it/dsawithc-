#include<iostream>
#include<vector>
using namespace std;
//recursive solution
int climbStairsRecr(int n){
    if(n==0 || n==1){
       return 1;
    }
    return climbStairsRecr(n-1)+climbStairsRecr(n-2);
}
//using memoization
int climbStairsMemo(int n,vector<int>&dp){
    if(n<=1){
        return 1;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n]=climbStairsMemo(n-1,dp)+climbStairsMemo(n-2,dp);
    return dp[n];
}
//using tabulation
int climbStairsTab(int n){
    vector<int> dp(n+1,-1);
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
//IF CLIMBIMING STAIRS TKAES 1,2 0R 3 STEPS AT A TIME
int climbStairsTab3(int n){
    vector<int> dp(n+1,-1);
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
    }
    return dp[n];
}
int main(){
    int n=5;
    vector<int> dp(n+1,-1);
    cout<<climbStairsMemo(n,dp)<<endl;
    cout<<climbStairsRecr(n)<<endl;
    cout<<climbStairsTab(n)<<endl;
    cout<<climbStairsTab3(n)<<endl;
}