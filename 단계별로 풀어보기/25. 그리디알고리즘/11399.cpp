#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int people_num;
    cin >> people_num;

    vector<int>people;
    for(int i=0; i< people_num; i++){
        int temp;
        cin >> temp;
        people.push_back(temp);
    }
    sort(people.begin(), people.end());

    int people_time = 0;
    int result = 0;
    for(int i=0; i<people.size(); i++){
        people_time += people[i];
        result += people_time;
    }
    cout << result << "\n";
    return 0;
}