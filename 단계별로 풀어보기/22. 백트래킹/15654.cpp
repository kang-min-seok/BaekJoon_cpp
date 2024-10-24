#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int>num_sequence;
int N, M;

void backtracking(vector<int>& sequence, int num_goal, int except){
    // 종료조건
    if(sequence.size() >= num_goal){
        for(int i=0; i<num_goal; i++){
            cout << sequence[i] << " ";
        }
        cout << "\n";
        return;
    } else {
        for(int i=0; i<N; i++){
            if(find(sequence.begin(), sequence.end(), num_sequence[i]) == sequence.end()){
                sequence.push_back(num_sequence[i]);
                backtracking(sequence, num_goal, except);
                sequence.pop_back();
            }
        }
        return;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;    
    
    for(int i=0; i<N; i++){
        int temp;
        cin >> temp;
        num_sequence.push_back(temp);
    }
    sort(num_sequence.begin(), num_sequence.end());

    for(int i=0; i<N; i++){
        vector<int>sequence_first;
        sequence_first.push_back(num_sequence[i]);
        backtracking(sequence_first,M,i);
    }
    

    return 0;
}
