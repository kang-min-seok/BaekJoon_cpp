#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int>sum_vector(n);
    int temp;
    cin >> temp;
    sum_vector[0] = temp;

    for(int i=1; i<n; i++){
        cin >> temp;
        sum_vector[i] = sum_vector[i-1] + temp;
    }


    for(int i=0; i<m; i++){
        int start, end;
        cin >> start >> end;
        if(start - 2 < 0) {
            cout << sum_vector[end-1] << "\n";
        } else {
            cout << sum_vector[end-1] - sum_vector[start-2] << "\n";
        }
        
    }
    

    return 0;
}



// 나랑 똑같이 풀었는데 초기값 세팅에 대해서 이게 좀 더 깔끔함
// 난 0번째 인덱스부터 값을 넣었지만 이 코드는 0번째 인덱스에 0을 집어넣음으로서
// 마지막에 start - 2가 0보다 작은지 판별을 안해도 되고 인덱스 마다 -1씩 안빼도 됨
// #include <iostream>
// using namespace std;

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cout.tie(NULL);
//     cin.tie(NULL);

//     int num;
//     int que;

//     cin >> num >> que;
//     long long list[num + 1];
//     int calc = 0;
//     list[0] = 0;
//     for (int i = 1; i <= num; i++)
//     {
//         long long a;
//         cin >> a;
//         list[i] = list[i - 1] + a;
//     }

//     for (int i = 0; i < que; i++)
//     {

//         int start, end;
//         cin >> start >> end;
//         int ans = list[end] - list[start - 1];
//         cout << ans << '\n';
//     }
//     return 0;
// }