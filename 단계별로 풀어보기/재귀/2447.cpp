#include <iostream>
#include <vector>
using namespace std;

void star_draw(int a, vector<string> star){
    // 윗부분 출력(공백없이 3번출력)
    // 중앙부분 출력(출력, 공백, 출력)
    // 아랫부분 출력(공백없이 3번 출력)
}


int main() {
    int num;
    vector<string>star_field = {"*"};
    cin >> num;
    star_draw(num, star_field);

    return 0;
}