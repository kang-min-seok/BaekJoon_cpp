#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<tuple<int,int,int>> down_map(n);
    
    for(int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        down_map[i] = make_tuple(a, b, c);
    }

    int min_a = get<0>(down_map[0]);
    int min_b = get<1>(down_map[0]);
    int min_c = get<2>(down_map[0]);

    
    int max_a = get<0>(down_map[0]);
    int max_b = get<1>(down_map[0]);
    int max_c = get<2>(down_map[0]);

    for(int i = 1; i < n; i++) {
        int next_min_a = min({min_a, min_b}) + get<0>(down_map[i]);
        int next_min_b = min({min_a, min_b, min_c}) + get<1>(down_map[i]);
        int next_min_c = min({min_b, min_c}) + get<2>(down_map[i]);

        int next_max_a = max({max_a, max_b}) + get<0>(down_map[i]);
        int next_max_b = max({max_a, max_b, max_c}) + get<1>(down_map[i]);
        int next_max_c = max({max_b, max_c}) + get<2>(down_map[i]);

        min_a = next_min_a;
        min_b = next_min_b;
        min_c = next_min_c;

        max_a = next_max_a;
        max_b = next_max_b;
        max_c = next_max_c;
    }
   

    int result_max = max({max_a, max_b, max_c});
    int result_min = min({min_a, min_b, min_c});

    cout << result_max << " " << result_min << "\n";
    
    return 0;
}
