#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int N;
    double totalScore = 0.0;
    cin >> N;
    vector<int> scores(N);

    for(int i = 0; i < N; i++){
        cin >> scores[i];
    }

    double max_score = *max_element(scores.begin(), scores.end());

    

    for(int i = 0; i < N; i++){
        totalScore += scores[i] / max_score * 100;
    }

    cout << totalScore / N;
}