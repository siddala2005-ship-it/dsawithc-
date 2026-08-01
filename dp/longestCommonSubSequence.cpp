#include<iostream>
#include<vector>
using namespace std;
//using recursioon
int lcs(string str1,string str2){
    int n=str1.size();
    int m=str2.size();
    if(n==0 || m==0){
        return 0;
    }
    if(str1[n-1]==str2[m-1]){
        return 1+lcs(str1.substr(0,n-1),str2.substr(0,m-1));

    }
    else{
        int ans1=lcs(str1.substr(0,n-1),str2);
        int ans2=lcs(str1,str2.substr(0,m-1));
        return max(ans1,ans2);
    }
}
//memoization
int lcsMemo(string str1,string str2){
    int n=str1.size();
    int m=str2.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    if(n==0 || m==0){
        return 0;
    }
    if(str1[n-1]==str2[m-1]){
        dp[n][m]=1+lcs(str1.substr(0,n-1),str2.substr(0,m-1));

    }
    else{
        int ans1=lcs(str1.substr(0,n-1),str2);
        int ans2=lcs(str1,str2.substr(0,m-1));
        dp[n][m]=max(ans1,ans2);
    }
    return dp[n][m];
}
//tabulation
int lcsTab(string str1,string str2){
    
    int n=str1.size();
    int m=str2.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(str1[i-1]==str2[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                
        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

            }
        }
    }
    return dp[n][m];
}
int main(){
    string str1="abcdxyz";
    string str2="xyzabcd";

    cout<<lcsMemo(str1,str2);
    cout<<lcsTab(str1,str2);
    cout<<lcs(str1,str2);
}