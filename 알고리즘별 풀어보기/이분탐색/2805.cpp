#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int tree_num, tree_need;
vector<int>tree;
void recursion(int low, int high){
    
    int middle = high - ((high - low) / 2);
    long long sum = 0;
    // 중앙값을 기준으로 쭉 잘라봄
    for(int i=0; i<tree_num; i++){
        if(tree[i] > middle){
            sum += tree[i] - middle;
        }
    }
    // 다 잘랐는데 딱 맞는 경우
    if(tree_need == sum){
        cout << middle << "\n";
        return;
    }
    // 다 잘랐는데 딱 맞지않고 low와 high가 같거나 1만큼 차이날경우 low를 출력해야 충분히 얻을 수 있는 높이의 최댓값임
    else if(middle == high){
        cout << low << "\n";
        return;
    }
    // 다 잘랐는데 넘친 경우
    else if (tree_need < sum){
        recursion(middle, high);
        return;
    }
    // 다 잘랐는데 부족한 경우
    else if (tree_need > sum){
        recursion(low, middle);
        return;
    }
   
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> tree_num >> tree_need;

    tree.resize(tree_num);
    for(int i=0; i<tree_num; i++){
        cin >> tree[i];
    }

    sort(tree.begin(), tree.end());


    recursion(0, tree[tree_num-1]);
    return 0;
}


// 재귀함수 호출할때 벡터를 매개변수로 넣어서 하는건 효율 개떨어짐, 시간도 늘어나고 메모리 개먹음
// 그러니 이런 문제의 경우에 벡터는 전역으로 선언해놓고 쓰는게 맞음