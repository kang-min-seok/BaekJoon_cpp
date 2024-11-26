#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int n;
vector<int> numbers;
int oper[4] = {0};

int result_max = INT_MIN;
int result_min = INT_MAX;

void basic_input(){
    cin >> n;
    numbers.resize(n);
    for(int i=0; i<n; i++){
        cin >> numbers[i];
    }
    cin >> oper[0];
    cin >> oper[1];
    cin >> oper[2];
    cin >> oper[3];
}

void backtracking(int len, int value){
    if(len == n-1){
        if(result_max < value){
            result_max = value;
        }
        if(result_min > value){
            result_min = value;
        }
    }
    

    if(oper[0] > 0){
        oper[0]--;
        backtracking(len+1, value + numbers[len+1]);
        oper[0]++;
    }

    if(oper[1] > 0){
        oper[1]--;
        backtracking(len+1, value - numbers[len+1]);
        oper[1]++;
    }

    if(oper[2] > 0){
        oper[2]--;
        backtracking(len+1, value * numbers[len+1]);
        oper[2]++;
    }

    if(oper[3] > 0){
        oper[3]--;
        backtracking(len+1, value / numbers[len+1]);
        oper[3]++;
    }
            
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    basic_input();

    backtracking(0,numbers[0]);

    cout << result_max << "\n";
    cout << result_min << "\n";
}