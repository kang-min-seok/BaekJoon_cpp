#include <iostream>
#include <vector>

using namespace std;
int height, width;
vector<vector<int>> board;
int result = 0;

void basic_input(){
    cin >> height >> width;
    board.resize(height, vector<int>(width));
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            cin >> board[i][j];
        }
    }
}

void bruteforce_x2_y3(){
    for(int i=0; i<height-2; i++){
        for(int j=0; j<width-1; j++){
            if(board[i][j] + board[i+1][j] + board[i+2][j] + board[i+2][j+1] > result){
                result = board[i][j] + board[i+1][j] + board[i+2][j] + board[i+2][j+1];
            }
            if(board[i][j+1] + board[i+1][j+1] + board[i+2][j+1] + board[i+2][j] > result){
                result = board[i][j+1] + board[i+1][j+1] + board[i+2][j+1] + board[i+2][j];
            }
            if(board[i][j] + board[i][j+1] + board[i+1][j+1] + board[i+2][j+1] > result){
                result = board[i][j] + board[i][j+1] + board[i+1][j+1] + board[i+2][j+1];
            }
            if(board[i][j] + board[i][j+1] + board[i+1][j] + board[i+2][j] > result){
                result = board[i][j] + board[i][j+1] + board[i+1][j] + board[i+2][j];
            }
            if(board[i][j] + board[i+1][j] + board[i+1][j+1] + board[i+2][j+1] > result){
                result = board[i][j] + board[i+1][j] + board[i+1][j+1] + board[i+2][j+1];
            }
            if(board[i][j+1] + board[i+1][j+1] + board[i+1][j] + board[i+2][j] > result){
                result = board[i][j+1] + board[i+1][j+1] + board[i+1][j] + board[i+2][j];
            }
            if(board[i][j+1] + board[i+1][j] + board[i+1][j+1] + board[i+2][j+1] > result){
                result = board[i][j+1] + board[i+1][j] + board[i+1][j+1] + board[i+2][j+1];
            }
            if(board[i][j] + board[i+1][j] + board[i+1][j+1] + board[i+2][j] > result){
                result = board[i][j] + board[i+1][j] + board[i+1][j+1] + board[i+2][j];
            }

        }
    }
}
void bruteforce_x3_y2(){
    for(int i=0; i<height-1; i++){
        for(int j=0; j<width-2; j++){
            if(board[i][j] + board[i][j+1] + board[i][j+2] + board[i+1][j] > result){
                result = board[i][j] + board[i][j+1] + board[i][j+2] + board[i+1][j];
            }
            if(board[i][j] + board[i+1][j] + board[i+1][j+1] + board[i+1][j+2] > result){
                result = board[i][j] + board[i+1][j] + board[i+1][j+1] + board[i+1][j+2];
            }
            if(board[i+1][j] + board[i+1][j+1] + board[i][j+1] + board[i][j+2] > result){
                result = board[i+1][j] + board[i+1][j+1] + board[i][j+1] + board[i][j+2];
            }
            if(board[i][j] + board[i][j+1] + board[i+1][j+1] + board[i+1][j+2] > result){
                result = board[i][j] + board[i][j+1] + board[i+1][j+1] + board[i+1][j+2];
            }
            if(board[i+1][j] + board[i+1][j+1] + board[i+1][j+2] + board[i][j+2] > result){
                result = board[i+1][j] + board[i+1][j+1] + board[i+1][j+2] + board[i][j+2];
            }
            if(board[i][j] + board[i][j+1] + board[i][j+2] + board[i+1][j+2] > result){
                result = board[i][j] + board[i][j+1] + board[i][j+2] + board[i+1][j+2];
            }
            if(board[i][j] + board[i][j+1] + board[i][j+2] + board[i+1][j+1] > result){
                result = board[i][j] + board[i][j+1] + board[i][j+2] + board[i+1][j+1];
            }
            if(board[i+1][j] + board[i+1][j+1] + board[i+1][j+2] + board[i][j+1] > result){
                result = board[i+1][j] + board[i+1][j+1] + board[i+1][j+2] + board[i][j+1];
            }
        }
    }

}
void bruteforce_x2_y2(){
    for(int i=0; i<height-1; i++){
        for(int j=0; j<width-1; j++){
            if(board[i][j] + board[i+1][j] + board[i][j+1] + board[i+1][j+1] > result){
                result = board[i][j] + board[i+1][j] + board[i][j+1] + board[i+1][j+1];
            }
        }
    }
}
void bruteforce_x1_y4(){
    for(int i=0; i<height-3; i++){
        for(int j=0; j<width; j++){
            if(board[i][j] + board[i+1][j] + board[i+2][j] + board[i+3][j] > result){
                result = board[i][j] + board[i+1][j] + board[i+2][j] + board[i+3][j];
            }
        }
    }
}
void bruteforce_x4_y1(){
    for(int i=0; i<height; i++){
        for(int j=0; j<width-3; j++){
            if(board[i][j] + board[i][j+1] + board[i][j+2] + board[i][j+3] > result){
                result = board[i][j] + board[i][j+1] + board[i][j+2] + board[i][j+3];
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    basic_input();

    bruteforce_x1_y4();
    bruteforce_x2_y2();
    bruteforce_x2_y3();
    bruteforce_x3_y2();
    bruteforce_x4_y1();

    cout << result << "\n";
    return 0;
}