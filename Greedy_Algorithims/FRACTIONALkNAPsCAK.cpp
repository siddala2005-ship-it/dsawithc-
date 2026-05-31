#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

// Comparator function to sort by value/weight ratio in descending order
bool compare(const pair<double, int>& p1, const pair<double, int>& p2) {
    return p1.first > p2.first;
}

// Fractional Knapsack Function
double fractionalKnapsack(const vector<int> weight,
                          const vector<int>value,
                          int capacity) {
    int n = value.size();

    // Store {ratio, index}
    vector<pair<double, int>> ratio(n);

    for (int i = 0; i < n; i++) {
        ratio[i].first = static_cast<double>(value[i]) / weight[i];
        ratio[i].second = i;
    }

    // Sort items according to ratio
    sort(ratio.begin(), ratio.end(), compare);

    double maxValue = 0.0;

    for (int i = 0; i < n && capacity > 0; i++) {
        int idx = ratio[i].second;

        if (weight[idx] <= capacity) {
            // Take the whole item
            maxValue += value[idx];
            capacity -= weight[idx];
        } else {
            // Take a fraction of the item
            maxValue += capacity * ratio[i].first;
            capacity = 0;
        }
    }

    return maxValue;
}

int main() {
    vector<int> weight = {10, 20, 30};
    vector<int> value = {60, 100, 120};
    int capacity = 50;

    cout << "Maximum value in Knapsack = "
         << fractionalKnapsack(weight, value, capacity)
         << endl;

    return 0;
}