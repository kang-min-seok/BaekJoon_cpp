#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>
#include <map>
using namespace std;

int bro, subin;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> subin >> bro;

    queue<pair<int,int>>q;
    bool visited[100001] = {false,};

    q.push(make_pair(subin, 0));
    visited[subin] = true;

    int result_min = INT_MAX;
    map<int,int>result; // (몇초후, 몇가지)

    while(!q.empty()){
        int now_point = q.front().first;
        int now_sec = q.front().second;
        visited[now_point] = true;
        q.pop();
        if(now_sec > result_min){
            continue;
        }
        if(now_point == bro && now_sec <= result_min){
            result_min = now_sec;
            result[now_sec] += 1;
        }

        if(now_point + 1 <= 100000 && !visited[now_point+1]){
            q.push(make_pair(now_point+1, now_sec+1));
        }
        if(now_point - 1 >= 0 && !visited[now_point-1]){
            q.push(make_pair(now_point-1, now_sec+1));
        }
        if(now_point * 2 <= 100000 && !visited[now_point * 2]){
            q.push(make_pair(now_point * 2, now_sec+1));
        }
    }

    cout << result_min << "\n";
    cout << result[result_min] << "\n";
    return 0;
}
