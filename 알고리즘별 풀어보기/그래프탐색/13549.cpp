#include <iostream>
#include <queue>
#include <vector>
using namespace std;

queue<pair<int,int>> subin_queue; // 현재위치, 이동한 시간
bool visited_vec[100001] = {false,};
int bro;
int result = 100001;
void bfs(){
    while(!subin_queue.empty()){
        int now = subin_queue.front().first;
        int time = subin_queue.front().second;
        visited_vec[now] = true;
        subin_queue.pop();
        if(now == bro && time < result){
            result = time;
        }

        if(now+1 < 100001 && !visited_vec[now+1]){
            subin_queue.push(make_pair(now+1,time+1));
        }
        if(now-1 >= 0 && !visited_vec[now-1]){
            subin_queue.push(make_pair(now-1,time+1));
        }
        if(2*now < 100001 && !visited_vec[2*now]){
            subin_queue.push(make_pair(2*now,time));
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int subin;
    cin >> subin >> bro;

    subin_queue.push(make_pair(subin, 0));
    bfs();
    cout << result << "\n";
    return 0;
}