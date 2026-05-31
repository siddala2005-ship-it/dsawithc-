#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool compare(pair<int,int>a,pair<int,int>b){
    return a.second<b.second;
}

int maxChainLength(vector<pair<int,int>> activities){
    sort(activities.begin(),activities.end(),compare);
    int count=1;
    int lastEnd=activities[0].second;
    for(int i=1;i<activities.size();i++){
        if(activities[i].first>lastEnd){
            count++;
            lastEnd=activities[i].second;
        }
    }
    return count;
}
int main(){
    vector<int> arr={1,5,3,19,18,25};
    vector<int> arr2={23,127,235,19,8,15};
    vector<pair<int,int>> activities(3,make_pair(0,0));
    activities[0]=make_pair(1,2);
    activities[1]=make_pair(3,4);
    activities[2]=make_pair(0,6);
cout<<maxChainLength(activities)<<endl;

}