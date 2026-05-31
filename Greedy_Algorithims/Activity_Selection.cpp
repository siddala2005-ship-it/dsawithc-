#include<iostream>
#include<vector>
using namespace std;
void activitySelection(vector<int>start, vector<int>end) {
    int count = 1;
    int currend = end[0];
    for (int i = 1; i < start.size(); i++) {
        if (start[i] >= currend) {
            count++;
            currend = end[i];
        }
    }
    cout << "Maximum number of activities that can be performed: " << count << endl;
}
int main() {
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};
    activitySelection(start, end);
    return 0;
}