#include <iostream>

using namespace std;

int main(void) {
    int paperNum, result=0;
    bool bigPaper[100][100] = {false,};

    cin >> paperNum;

    for(int i=0; i < paperNum; i++){
        int x,y;
        cin >> x >> y;

        for(int a=0; a<10;a++){
            for(int b=0; b<10;b++){
                bigPaper[y+a][x+b] = true;
            }
        }
    }

    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            if(bigPaper[i][j]){
                result += 1;
            }
        }
    }

    cout << result << endl;

    return 0;
}