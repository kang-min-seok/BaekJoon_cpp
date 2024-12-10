#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

vector<int> numbers;
vector<char> opers;
int modi_num;
string modi_input;

int result = INT_MIN;

void basic_input(){
    cin >> modi_num;
    cin >> modi_input;

    for(int i=0; i<modi_num; i+=2){
        numbers.push_back((int)modi_input[i]-48);
    }

    for(int i=1; i<modi_num; i+=2){
        opers.push_back(modi_input[i]);
    }

}

int modify_num(int a, int b, char c){
    if(c == '+') return a + b;
    else if(c == '-') return a - b;
    else if(c == '*') return a * b; 
}

void backtracking(int start, int before_value){
    if(start > numbers.size()-2) return;

    int bracket_num = modify_num(numbers[start], numbers[start+1], opers[start]);
    int next_value = modify_num(before_value, bracket_num, opers[start-1]);

    
    for(int i=start+2; i<numbers.size(); i++){
        // 이전 값과 여기서 뭉친값을 계산하고
        if(i < numbers.size() - 1){
            backtracking(i, next_value);
        }

        next_value = modify_num(next_value, numbers[i], opers[i-1]);
    }

    if(next_value > result){
        result = next_value;
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    basic_input();
    int value = numbers[0];
    for(int i=0; i<numbers.size()-1; i++){
        backtracking(i+1, value);
        value = modify_num(value, numbers[i+1], opers[i]);
    }

    if(result < value){
        result = value;
    }

    cout << result << "\n";
    return 0;
}