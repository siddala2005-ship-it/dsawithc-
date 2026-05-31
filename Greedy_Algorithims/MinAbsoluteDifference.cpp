#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int> arr={1,2,3};
    vector<int> arr2={3,1,2};
    sort(arr.begin(),arr.end());
    sort(arr2.begin(),arr2.end());
    int absDiff=0;
for(int i=0;i<arr.size();i++){
    absDiff=min(absDiff,abs(arr[i]-arr2[i]));
}
cout<<absDiff<<endl;
    return 0;
}