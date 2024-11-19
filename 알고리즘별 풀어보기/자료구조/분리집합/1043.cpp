#include <iostream>
#include <vector>

using namespace std;

vector<int>parent;
vector<int>ranking;
vector<vector<int>> parties;
vector<bool>is_know_people;

// 연결된 노드끼리 최상단 노드값이 진실을 아는자면 그 아래로는 전부다 진실을 아는자가 되어야함

int find(int x){
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void connect_add(int a, int b){
    a = find(a);
    b = find(b);

    if(a != b){
        if(ranking[b] > ranking[a]){
            parent[a] = b;
            if(is_know_people[a]) is_know_people[b] = true;
        } else {
            parent[b] = a;
            if(is_know_people[b]) is_know_people[a] = true;
            if(ranking[b] == ranking[a]){
                ranking[a]++;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m; // 사람의 수, 파티의 수
    cin >> n >> m;
    parent.resize(n+1);
    ranking.resize(n+1, 0);
    parties.resize(m);
    is_know_people.resize(n+1, false);

    for(int i=1; i<=n; i++){
        parent[i] = i;
    }

    // 진실을 아는자 초기화
    int know_num;
    cin >> know_num;
    for(int i=0; i<know_num; i++){
        int temp;
        cin >> temp;
        is_know_people[temp] = true;
    }

    for(int i=0; i<m; i++){
        int party_pnum; // 파티에 몇명 오는지
        cin >> party_pnum;

        int party_p1; // 몇번 노드가 파티에 오는지
        cin >> party_p1;
        parties[i].push_back(party_p1);

        for(int j=1; j<party_pnum; j++){
            int party_p2;
            cin >> party_p2;
            parties[i].push_back(party_p2);

            connect_add(party_p1, party_p2);
            
            party_p1 = party_p2;
        }
    }

    int result = 0;

    for(int i=0; i<m; i++){
        for(int j=0; j<parties[i].size(); j++){
            if(!is_know_people[find(parties[i][j])]){
                result += 1;
                break;
            }
        }
    }

    cout << result << "\n";
    return 0;
}