#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
    int width, height;
    cin >> height >> width;
    vector<vector<char>> board(height, vector<char>(width));

    int result;
    bool isResultInitialized = false;

    for (int i = 0; i < height; ++i)
    {
        string line;
        cin >> line;
        for (int j = 0; j < width; ++j)
        {
            board[i][j] = line[j];
        }
    }

    for (int i = 0; i < height - 7; i++)
    {
        for (int j = 0; j < width - 7; j++)
        {
            // 맨위 왼쪽이 B인경우
            int cnt_B = 0;
            for (int y = 0; y < 8; y++)
            {
                for (int x = 0; x < 8; x += 2)
                {
                    // 0,2,4,6
                    // 1,3,5,7
                    if (y % 2 == 1)
                    {
                        if (board[i + y][j + x + 1] != 'B')
                        {
                            cnt_B += 1;
                        }
                    }
                    else
                    {
                        if (board[i + y][j + x] != 'B')
                        {
                            cnt_B += 1;
                        }
                    }
                }
            }

            for (int y = 0; y < 8; y++)
            {
                for (int x = 0; x < 8; x += 2)
                {
                    // 1,3,5,7
                    // 0,2,4,6
                    if (y % 2 == 1)
                    {
                        if (board[i + y][j + x] != 'W')
                        {
                            cnt_B += 1;
                        }
                    }
                    else
                    {
                        if (board[i + y][j + x + 1] != 'W')
                        {
                            cnt_B += 1;
                        }
                    }
                }
            }
            if (!isResultInitialized)
            {
                result = cnt_B;
                isResultInitialized = true;
            }

            if (cnt_B <= result)
            {
                result = cnt_B;
            }

            int cnt_W = 0;
            for (int y = 0; y < 8; y++)
            {
                for (int x = 0; x < 8; x += 2)
                {
                    // 0,2,4,6
                    // 1,3,5,7
                    if (y % 2 == 1)
                    {
                        if (board[i + y][j + x] != 'B')
                        {
                            cnt_W += 1;
                        }
                    }
                    else
                    {
                        if (board[i + y][j + x + 1] != 'B')
                        {
                            cnt_W += 1;
                        }
                    }
                }
            }

            for (int y = 0; y < 8; y++)
            {
                for (int x = 0; x < 8; x += 2)
                {
                    // 1,3,5,7
                    // 0,2,4,6
                    if (y % 2 == 1)
                    {
                        if (board[i + y][j + x + 1] != 'W')
                        {
                            cnt_W += 1;
                        }
                    }
                    else
                    {
                        if (board[i + y][j + x] != 'W')
                        {
                            cnt_W += 1;
                        }
                    }
                }
            }

            if (!isResultInitialized)
            {
                result = cnt_W;
                isResultInitialized = true;
            }

            if (cnt_W <= result)
            {
                result = cnt_W;
            }
        }
    }

    cout << result << endl;
    return 0;
}


// 인터넷 코드
// 체스판을 미리 정의해두고 그거랑 비교해서 틀린부분 있을때마다 cnt 올리는 방식
// 물론 0,0 위치의 체스판을 색칠해야 최솟값인 경우도 있기때문에
// 두 경우 모두 실행함. 이 코드가 훨씬 깔끔하네잉. 

// #include <iostream>
// #include <string>
// #include <algorithm>
// #include <utility>
// using namespace std;
// string WB[8] = {
//         "WBWBWBWB",
//         "BWBWBWBW",
//         "WBWBWBWB",
//         "BWBWBWBW",
//         "WBWBWBWB",
//         "BWBWBWBW",
//         "WBWBWBWB",
//         "BWBWBWBW"
// };
// string BW[8] = {
//         "BWBWBWBW",
//         "WBWBWBWB",
//         "BWBWBWBW",
//         "WBWBWBWB",
//         "BWBWBWBW",
//         "WBWBWBWB",
//         "BWBWBWBW",
//         "WBWBWBWB"
// };
// string board[50];
// int WB_cnt(int x, int y)
// {
//     int cnt = 0;
//     for(int i = 0; i < 8; i++)
//     {
//         for(int j = 0; j < 8; j++)
//         {
//             if(board[x+i][y+j] != WB[i][j])
//                 cnt++;
//         }

//     }
//     return cnt;
// }
// int BW_cnt(int x, int y)
// {
//     int cnt = 0;
//     for(int i = 0; i < 8; i++)
//     {
//         for(int j = 0; j < 8; j++)
//         {
//             if(board[x+i][y+j] != BW[i][j])
//                 cnt++;
//         }

//     }
//     return cnt;
// }
// int main() {
//     int size[2];
//     int cnt;
//     int min_val = 12345;
//     pair<int, int> p1;
//     cin >> p1.first >> p1.second;
//     for(int i = 0; i < p1.first; i++)
//         cin >> board[i];
//     for(int i = 0; i + 8 <= p1.first; i++)
//     {
//         for(int j = 0; j + 8 <= p1.second; j++)
//         {
//             int tmp;
//             tmp = min(WB_cnt(i,j),BW_cnt(i,j));
//             if(tmp < min_val) {
//                 min_val = tmp;
//             }
//         }
//     }
//     cout << min_val;
//     return 0;
// }