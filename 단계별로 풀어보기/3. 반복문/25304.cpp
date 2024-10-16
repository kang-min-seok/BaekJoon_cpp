#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main(void) {
    int totalCost, totalKind;
    int a,b;
    int cost=0;

    vector<pair<int, int>> vec;

    cin >> totalCost;
    cin >> totalKind;

    for(int i = 0; i < totalKind; i++){
        cin >> a >> b;
        vec.push_back(make_pair(a, b));
    }

    for (int j = 0; j < totalKind; j++) {
        cost += vec[j].first * vec[j].second;
    }

    if(totalCost == cost){
        cout << "Yes";
    } else {
        cout << "No";
    }
}