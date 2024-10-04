#include <iostream>
#include <string>
#include <cctype>
#include<math.h>

using namespace std;

int main(void) {
    // 10진수 값이 총 몇자리 수인가
    // 가장 높은자리 수부터 최대로 올 수 있는 값 다 넣기
    int N, B;
    int digit=1;
    bool flag = false;
    string result = "";

    cin >> N >> B;

    while(1){
        int temp = N - pow(B,digit);
        if(temp < 0){
            break;
        }
        digit += 1;
    }

    for(int i = digit; i>0; i--){
        for(int j = B-1; j>0; j--){
            string temp;
            int minusValue = j * pow(B,i-1);

            if(j >= 10){
                temp = j + 55;
            } else {
                temp = j + 48;
            }


            if(N - minusValue >= 0){
                N -= minusValue;
                result += temp;
                flag = true;
                break;
            }
        }
        if(!flag){
            result += "0";
        } else {
            flag = false;
        }
    }

    cout << result << endl;
    return 0;
}



// 정석 정답
// 10진수 숫자를 10씩 나누면 자릿수 나눌 수 있듯이
// N진수 숫자를 N씩 나누면 자릿수 나눌 수 있음(난 이걸 생각 못해서 좀 복잡하게 짬)
// 그걸 이용해서 자릿수 다 나눠서 값 구한뒤에 숫자 순서 뒤집는 코드임

// #include <iostream>
// #include <algorithm>
// using namespace std;

// int main()
// {
//     int n, b;
//     cin >> n >> b;

//     string b_num;
//     while (n != 0)
//     {
//         int tmp = n % b;
//         if (tmp > 9)
//         {
//             tmp = tmp - 10 + 'A';
//             b_num += tmp;
//         }
//         else
//         {
//             b_num += ('0' + tmp);
//         }
//         n /= b;
//     }
//     reverse(b_num.begin(), b_num.end());

//     cout << b_num << '\n';

//     return 0;
// }