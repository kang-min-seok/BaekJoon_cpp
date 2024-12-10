#include <iostream>
#include <vector>

using namespace std;

int board_size;
int result = 0;
vector<int> board;

void basic_input(){
    cin >> board_size;
    board.resize(board_size);
}

bool check_queen(int size){
    for(int i=0; i<size; i++){
        if(board[i] == board[size] || (size - i) == abs(board[i] - board[size]))
            return false;
    }
    return true;
}

void backtracking(int size){
    if(size == board_size){
        result++;
        return;
    }

    vector<int>temp_board = board;
    for(int j=0; j<board_size; j++){
        board[size] = j;
        if(check_queen(size)){
            backtracking(size+1);
        }
    }
    
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    basic_input();

    for(int i=0; i<board_size; i++){
        board[0] = i;
        backtracking(1);
    }

    cout << result << "\n";

    return 0;
}