#include<iostream>
#include<vector>
using namespace std;
int unboundedKnapSack(int wt[],int val[],int n,int W){
    vector<vector<int>> dp(n+1,vector<int>(W+1,0));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
            else if(wt[i-1]<=j){
                dp[i][j]=max(val[i-1]+dp[i][j-wt[i-1]],dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][W];
}
int main(){
    int wt[]={2,5,1,3,4};
    int val[]={15,14,10,45,30};
    int W=7;
    int n=sizeof(wt)/sizeof(wt[0]);
    cout<<"Maximum value in Knapsack = "<<unboundedKnapSack(wt,val,n,W)<<endl;
    return 0;
}