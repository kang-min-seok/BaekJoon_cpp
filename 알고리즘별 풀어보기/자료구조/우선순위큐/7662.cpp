#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    int test_case;
    cin >> test_case;

    for(int i=0; i<test_case; i++){
        int case_num;
        cin >> case_num;
        priority_queue<pair<int,int>>queue_max; // 최대힙
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>queue_min; // 최소힙
        set<int>delete_set;

        int queue_length = 0;
        for(int j=0; j<case_num; j++){
            char command;
            int num;
            cin >> command >> num;

            while(!queue_max.empty() && delete_set.find(queue_max.top().second) != delete_set.end()){
                delete_set.erase(queue_max.top().second);
                queue_max.pop();
            }
            while(!queue_min.empty() && delete_set.find(queue_min.top().second) != delete_set.end()){
                delete_set.erase(queue_min.top().second);
                queue_min.pop();
            }

            // I면 그냥 입력
            if(command == 'I'){
                queue_max.push({num,j});
                queue_min.push({num,j});
                queue_length += 1;
            } 
            // D인경우 + 큐 길이가 0보다 큰지 판별
            else if(command == 'D' && queue_length > 1) {
                // 최대값 뺴기
                if(num == 1){
                    if(queue_max.empty())
                        continue;
                    delete_set.insert(queue_max.top().second);
                    queue_max.pop();
                    queue_length -= 1;
                }
                // 최소값 뺴기
                else {
                    if(queue_min.empty())
                        continue;
                    delete_set.insert(queue_min.top().second);
                    queue_min.pop();
                    queue_length -= 1;
                }
            } else if(command == 'D' && queue_length == 1) {
                queue_max = priority_queue<pair<int,int>>(); // 최대힙
                queue_min = priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>(); // 최소힙
                delete_set = set<int>();
                queue_length = 0;
            }

        }

        while(!queue_max.empty() && delete_set.find(queue_max.top().second) != delete_set.end()){
            delete_set.erase(queue_max.top().second);
            queue_max.pop();
        }
        while(!queue_min.empty() && delete_set.find(queue_min.top().second) != delete_set.end()){
            delete_set.erase(queue_min.top().second);
            queue_min.pop();
        }
    
        if(queue_length == 0) {
            cout << "EMPTY" << "\n";
        } else {
            cout << queue_max.top().first << " " << queue_min.top().first << "\n";
        }
    }
    

 
    return 0;
}