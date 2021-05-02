#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> cost, v(10001, 10001); // 화폐 종류  / dp테이블

int main() {
    cin >> N >> M;
    int tmp;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        cost.emplace_back(tmp);
    }

    v[0] = 0;       //맨 처음은 0
    for (int i = 0; i < N; i++) {   //화폐종류만큼 반복
        for (int j = cost[i]; j <= M; j++) {    //화폐 단위부터 시작가능
            if (v[j - cost[i]] != 10001)    //이전에 화폐 이용해서 만들 수 있었다면
                v[j] = min(v[j], v[j - cost[i]] + 1); // 더 최소의 경우
        }
    }
    if (v[M] == 10001)
        cout << "-1";
    else {
        cout << v[M];
    }
}