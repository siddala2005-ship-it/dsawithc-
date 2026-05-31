#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool compare(pair<int,int>a,pair<int,int>b){
    return a.second<b.second;
}
int main(){
    vector<int> start = {0,1,2,3,4};
    vector<int> end = {1,2,3,4,5};
    vector<pair<int,int>> activities(3,make_pair(0,0));
    activities[0]=make_pair(1,2);
    activities[1]=make_pair(3,4);
    activities[2]=make_pair(0,6);
    for(int i=0;i<activities.size();i++){
        cout<<activities[i].first<<" "<<activities[i].second<<endl;
    }
    sort(activities.begin(),activities.end(),compare);
    cout<<"After sorting: "<<endl;
    for(int i=0;i<activities.size();i++){
        cout<<activities[i].first<<" "<<activities[i].second<<endl;
    }

    

    return 0;
}