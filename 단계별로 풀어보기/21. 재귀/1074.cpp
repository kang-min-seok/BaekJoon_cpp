#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void recursion(int height_goal, int width_goal, int square_size, int plus_value){
    int width_plus=0, height_plus=0;
    
    // 4분면 중 왼, 오 인지 판별
    if(width_goal >= pow(2,square_size-1)){
        width_plus = 1;
    }
    // 4분면 중 위, 아래인지 판별
    if(height_goal >= pow(2,square_size-1)){
        height_plus = 2;
    }
    // n이 1이면 종료
    if(square_size == 1) {
        cout << plus_value + width_plus + height_plus << "\n";
        return;
    }
    // 다음 사각형에 맞는 다음 좌표 구하기
    if(height_plus != 0){
        height_goal -= pow(2,square_size-1);
    }
    if(width_plus != 0){
        width_goal -= pow(2,square_size-1);
    }
    
    int next_plus = pow(4,square_size-1) * (width_plus + height_plus);

    recursion(height_goal, width_goal, square_size - 1, plus_value + next_plus);
    return;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, height_goal, width_goal;

    cin >> n >> height_goal >> width_goal;
    recursion(height_goal, width_goal, n, 0);
    return 0;
}




// 인터넷 코드
// 풀이 방식은 나랑 거의 똑같은데 코드가 깔끔함.
// #include <iostream>
// #include <cmath>
// using namespace std;
// int n, r, c;
// int ans = 0;
// void dc(int x, int y, int size){
//     if(c==x && r==y){ // 찾으려는 열과 행이 일치하면 
//         cout << ans;
//         return;
//     }
//     else if (c < x + size && r < y + size && c >= x && r >= y){
//         //찾으려는 열과 행이 4분면안에 있을 경우
//         dc(x, y, size / 2);
//         dc(x + size / 2, y, size / 2);
//         dc(x, y + size / 2, size / 2);
//         dc(x + size / 2, y + size / 2, size / 2);
//     }else{ // 없다면 숫자 카운트 -> 정사각형 넓이
//         ans += size * size;
//     }
// }
// int main(){
//     cin >> n >> r >> c;
//     dc(0, 0, pow(2, n));
//     return 0;
// }