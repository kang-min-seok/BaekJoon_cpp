#include <iostream>
#include<string>

using namespace std;

int main(void) {
    int N;
    cin >> N;
    int cnt = 1;
    int result = 666;

    while(1){
        if(cnt == N){
            break;
        }
        result += 1;
        string result_str = to_string(result);


        for(int i=0;i<result_str.length() - 2;i++){
            if(result_str[0 + i] == '6' && result_str[1 + i] == '6' && result_str[2 + i] == '6') {
                cnt += 1;
                break;
            }
        }
    }

    cout << result << endl;
    return 0;
}



// 인터넷 코드
// 나랑 사실상 똑같이 짬.
// #include <iostream>
// #include <string>
// using namespace std;
// int Findseries(int N)
// {
//     int i = 666;
//     int series = 0;
//     string target;
//     while(1)
//     {
//         target = to_string(i);
//         for(int j = 0; j < target.length()-2; j++)
//             if(target[j] == '6' && target[j+1] == '6' && target[j+2] == '6')
//             {
//                 series++;
//                 if(series == N)
//                     return i;
//                 break;
//             }
//         i++;
//     }
// }
// int main() {
//     int N;
//     cin >> N;
//     cout << Findseries(N);
// }