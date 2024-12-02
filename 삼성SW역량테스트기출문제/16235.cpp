#include <iostream>
#include <vector>
#include <tuple>
#include <deque>
#include <algorithm>
using namespace std;

int board[11][11];
int board_add[11][11] = {0};
int board_size, tree_num, finish_year;
deque<int> tree_info[11][11];

void basic_input(){
    cin >> board_size >> tree_num >> finish_year;
    for(int i=1; i<=board_size; i++){
        for(int j=1; j<=board_size; j++){
            board[i][j] = 5;
        }
    }
    for(int i=1; i<=board_size; i++){
        for(int j=1; j<=board_size; j++){
            cin >> board_add[i][j];
        }
    }
    for(int i=0; i<tree_num; i++){
        int x,y,age;
        cin >> x >> y >> age;
        tree_info[y][x].push_back(age);
    }
}

int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};

void tree_tech(){
    // 봄
    vector<tuple<int,int,int>> dead_tree;
    for(int i=1; i<=board_size; i++){
        for(int j=1; j<=board_size; j++){
            if(tree_info[i][j].empty()) continue;

            deque<int> new_forest;
            int nutrients = board[i][j];
            for(auto &age:tree_info[i][j]){
                if(age <= board[i][j]){
                    nutrients -= age;
                    new_forest.push_back(age+1);
                } else {
                    dead_tree.push_back(make_tuple(age,j,i));
                }
            }

            tree_info[i][j] = new_forest;

        }
    }


    // 여름
    for(auto &dead : dead_tree){
        int dead_age = get<0>(dead);
        int dead_x = get<1>(dead);
        int dead_y = get<2>(dead);
        tree_num--;
        board[dead_y][dead_x] += dead_age / 2;
    }

    // 가을
    for(int i=1; i<=board_size; i++){
        for(int j=1; j<=board_size; j++){
            // if(tree_info[i][j].empty()) continue;

            for(auto &age: tree_info[i][j]){
                if(age % 5 == 0){
                    for(int o=0; o<8; o++){
                        int next_x = j + dx[o];
                        int next_y = i + dy[o];
                        if(next_x < 1 || next_y < 1 || next_x > board_size || next_y > board_size)
                            continue;
                        tree_num++;
                        tree_info[next_y][next_x].push_front(1);
                    }
                }
            }
        }
    }
    
    // 겨울
    for(int i=1; i<=board_size; i++){
        for(int j=1; j<=board_size; j++){
            board[i][j] += board_add[i][j];
        }
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    basic_input();

    for(int i=0; i<finish_year; i++){
        tree_tech();
    }

    cout << tree_num << "\n";
    return 0;
}
