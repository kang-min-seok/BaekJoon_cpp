#include <iostream>
#include <vector>
using namespace std;

int blue_cnt = 0;
int white_cnt = 0;
vector<vector<int>> paper;

void cut_paper(int x, int y, int size){
    int now_color = paper[y][x]; // 1이면 파란색, 0이면 흰색
    for(int i=y; i<y+size; i++){
        for(int j=x; j<x+size; j++){
            // 온전한 색종이가 아니라면
            if(paper[i][j] != now_color){
                int next_size = size/2;
                cut_paper(x,y,next_size);
                cut_paper(x+next_size,y,next_size);
                cut_paper(x,y+next_size,next_size);
                cut_paper(x+next_size,y+next_size,next_size);
                return;
            }
        }
    }
    // 온전한 색종이 인경우
    if(now_color == 1){
        blue_cnt += 1;
    } else {
        white_cnt += 1;
    }
}

int main() {
    int size;
    cin >> size;
    paper.resize(size, vector<int>(size, 0));

    // 정사각형 선언
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            cin >> paper[i][j];
        }
    }

    cut_paper(0,0,size);

    cout << white_cnt << "\n";
    cout << blue_cnt << "\n";

    return 0;
}