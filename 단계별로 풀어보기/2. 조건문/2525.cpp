#include <iostream>

using namespace std;

int main(void) {
    int nowHour,nowMinute,time;

    int temp;
    int plusHour, plusMinute;

    int resultHour;

    cin >> nowHour >> nowMinute;
    cin >> time;

    temp = nowMinute + time;
    plusHour = temp / 60;
    plusMinute = temp % 60;

    if(nowHour + plusHour >= 24){
        resultHour = (nowHour + plusHour) % 24;
    } else {
        resultHour = nowHour + plusHour;
    }

    cout << resultHour << " " << plusMinute;

}