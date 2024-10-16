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



// 이걸 생각 못하냐 ㅅㅂ 반성하자 코드 왜 이따구로 짜니..

// 더 효율적인 풀이
// 나는 색종이 다 방문처리를 하고
// 방문이 된부분마다 카운트 1증가하는 식으로 했는데
// 여기는 카운트 1증가하면서 방문을 해서 알고리즘 효율을 높임
// #include<iostream>
// using namespace std;
// int a[100][100];
// int main(){
//     int n,x,y,cnt=0;
//     cin>>n;
//     while(n--){
//         cin>>x>>y;
//         for(int i=y;i<y+10;i++){
//             for(int j=x;j<x+10;j++){
//                 if(!a[i][j]){
//                     cnt++;
//                     a[i][j]=1;
//                 }
//             }
//         }
//     }
//     cout<<cnt;
// }