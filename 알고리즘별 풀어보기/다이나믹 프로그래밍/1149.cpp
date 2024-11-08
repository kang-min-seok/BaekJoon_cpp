#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int house_num;
    cin >> house_num;

    vector<int>red_house(house_num);
    vector<int>green_house(house_num);
    vector<int>blue_house(house_num);

    for(int i=0; i<house_num; i++){
        cin >> red_house[i] >> green_house[i] >> blue_house[i];
    }

    vector<int>red_min(house_num);
    vector<int>green_min(house_num);
    vector<int>blue_min(house_num);

    red_min[0] = red_house[0];
    green_min[0] = green_house[0];
    blue_min[0] = blue_house[0];

    for(int i=1; i<house_num; i++){
        // i번째 집 빨간색 왔을때 최소값
        if(green_min[i-1] > blue_min[i-1]){
            red_min[i] = blue_min[i-1] + red_house[i];
        } else {
            red_min[i] = green_min[i-1] + red_house[i];
        }

        // i번째 집 초록색 왔을때 최소값
        if(red_min[i-1] > blue_min[i-1]){
            green_min[i] = blue_min[i-1] + green_house[i];
        } else {
            green_min[i] = red_min[i-1] + green_house[i];
        }

        // i번째 집 초록색 왔을때 최소값
        if(red_min[i-1] > green_min[i-1]){
            blue_min[i] = green_min[i-1] + blue_house[i];
        } else {
            blue_min[i] = red_min[i-1] + blue_house[i];
        }

    }

    int r_min = red_min[house_num-1];
    int g_min = green_min[house_num-1];
    int b_min = blue_min[house_num-1];

    int result = min({r_min, g_min, b_min});
    cout << result << "\n";

    return 0;
}