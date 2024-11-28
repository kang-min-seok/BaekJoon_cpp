#include <iostream>
#include <vector>
#include <limits.h>
#include <math.h>
using namespace std;

int n;
vector<vector<int>> board;
vector<bool>team_in;

void basic_input(){
    cin >> n;
    team_in.resize(n+1, false);
    board.resize(n+1, vector<int>(n+1));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> board[i][j];
        }
    }
}

int result = INT_MAX;
int team_len = 0;



void backtracking(int now){  
    
    if(team_len == n/2){
        int true_team_add = 0;
        int false_team_add = 0;

        for(int i=1; i<=n; i++){
            if(team_in[i]){
                for(int j=1; j<=n; j++){
                    if(team_in[j]){
                        true_team_add += board[i][j];
                    }
                }    
            } else {
                for(int j=1; j<=n; j++){
                    if(!team_in[j]){
                        false_team_add += board[i][j];
                    }
                }   
            }
        }
        if(result > abs(true_team_add - false_team_add)){
            result = abs(true_team_add - false_team_add);
        }
    }
    for(int i=now+1; i<=n; i++){
        if(team_in[i] == false){
            team_in[i] = true;
            team_len++;
            backtracking(i);
            team_in[i] = false;
            team_len--;
        }
    }  
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    basic_input();
    
    team_len++;
    team_in[1] = true;
    backtracking(1);
    team_len--;
    team_in[1] = false;

    cout << result << "\n";
    return 0;
}