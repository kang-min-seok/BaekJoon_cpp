// 단순구현
#include <iostream>
#include <vector>
using namespace std;


int height, width;
vector<vector<int>> board;
pair<int,int>now_dice; // x,y

vector<int> dice_updown(4, 0); // index:1 = 위 index:3 = 아래
vector<int> dice_side(3, 0); // index: 1 = 위 


void move_up(){
    if(now_dice.second - 1 < 0)
        return;
    
    vector<int> temp_updown = dice_updown;
    dice_updown[0] = temp_updown[1];
    dice_updown[1] = temp_updown[2];
    dice_updown[2] = temp_updown[3];
    dice_updown[3] = temp_updown[0];
    dice_side[1] = temp_updown[2];

    now_dice.second -= 1;

    if(board[now_dice.second][now_dice.first] == 0){
        board[now_dice.second][now_dice.first] = dice_updown[3];
    } else {
        dice_updown[3] = board[now_dice.second][now_dice.first];
        board[now_dice.second][now_dice.first] = 0;
    }

    cout << dice_updown[1] << "\n";
}

void move_down(){
    if(now_dice.second + 1 >= height)
        return;
    
    vector<int> temp_updown = dice_updown;
    dice_updown[0] = temp_updown[3];
    dice_updown[1] = temp_updown[0];
    dice_updown[2] = temp_updown[1];
    dice_updown[3] = temp_updown[2];
    dice_side[1] = temp_updown[0];

    now_dice.second += 1;

    if(board[now_dice.second][now_dice.first] == 0){
        board[now_dice.second][now_dice.first] = dice_updown[3];
    } else {
        dice_updown[3] = board[now_dice.second][now_dice.first];
        board[now_dice.second][now_dice.first] = 0;
    }

    cout << dice_updown[1] << "\n";
}

void move_right(){
    if(now_dice.first + 1 >= width)
        return;
    
    vector<int> temp_updown = dice_updown;
    vector<int> temp_side = dice_side;
    dice_side[0] = temp_updown[3];
    dice_side[1] = temp_side[0];
    dice_side[2] = temp_side[1];
    dice_updown[3] = temp_side[2];
    dice_updown[1] = temp_side[0];

    now_dice.first += 1;

    if(board[now_dice.second][now_dice.first] == 0){
        board[now_dice.second][now_dice.first] = dice_updown[3];
    } else {
        dice_updown[3] = board[now_dice.second][now_dice.first];
        board[now_dice.second][now_dice.first] = 0;
    }

    cout << dice_updown[1] << "\n";
}

void move_left(){
    if(now_dice.first - 1 < 0)
        return;
    
    vector<int> temp_updown = dice_updown;
    vector<int> temp_side = dice_side;
    dice_side[0] = temp_side[1];
    dice_side[1] = temp_side[2];
    dice_side[2] = temp_updown[3];
    dice_updown[1] = temp_side[2];
    dice_updown[3] = temp_side[0];

    now_dice.first -= 1;

    if(board[now_dice.second][now_dice.first] == 0){
        board[now_dice.second][now_dice.first] = dice_updown[3];
    } else {
        dice_updown[3] = board[now_dice.second][now_dice.first];
        board[now_dice.second][now_dice.first] = 0;
    }

    cout << dice_updown[1] << "\n";
}




int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 지도 크기 설정
    cin >> height >> width;
    board.resize(height,vector<int>(width,0));
    
    // 주사위 현재위치 설정
    cin >> now_dice.second >> now_dice.first;

    int command_num;
    cin >> command_num;
    

    // 보드상태 설정
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            cin >> board[i][j];
        }
    }

    

    for(int i=0; i<command_num; i++){
        int command;
        cin >> command;

        switch (command)
        {
        case 1:
            move_right();
            break;
        case 2:
            move_left();
            break;
        case 3:
            move_up();
            break;
        case 4:
            move_down();
            break;
        default:
            break;
        }
    }

    return 0;
}