//치킨배달
/* 
    1. 집, 치킨 벡터 각각 모아서 저장 ..
    2. 치킨집 개수 만큼 배열idx 만들고 M개 만큼 1, 나머지는 0...(순열을 조합으로 만들기 위함)
    3. next_permutation(사용전 정렬 필수!) 이용하여 idx 순열 하나씩 뽑고, 뽑힌 idx 의 1 순서처럼 치킨집 선택...(조합)
    4. 선택된 치킨집으로 도시 치킨거리 계산
    5. 가장 작은 치킨거리만 남기고 출력.
 */
#include <bits/stdc++.h>
using namespace std;
#define MAX_N 55
#define INF 1e4
int N, M;
vector<pair<int, int>> chicken, home;

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    int x, y, tmp;
    for(int i = 0 ; i < N; i++){
        for(int j = 0 ; j < N; j++){
            cin >> tmp;
            if(tmp == 1){    //집
                home.push_back({i,j});
            }
            else if (tmp == 2){ //치킨집
                chicken.push_back({i,j});
            }
        }
    }

    int idx[chicken.size()]={0,};    //순열을 조합으로 사용하기 위한 배열
    for(int i =0 ; i < M; i++){
        idx[i] = 1;
    }
    sort(idx, idx+chicken.size());
    int result = INF;    //최소 치킨거리
    do{
        vector<pair<int, int>> choice;
        int city_sum = 0;
        for(int i =0; i < chicken.size(); i++){
            if(idx[i] == 1){
                choice.push_back(chicken[i]); //M개의 치킨집 뽑기
            }
        }
        for(int i = 0; i < home.size(); i++){
            int min_distance = INF;
            for(int j = 0; j < choice.size(); j++){
                min_distance = min(abs(home[i].first - choice[j].first) + abs(home[i].second - choice[j].second), min_distance);
            }
            city_sum += min_distance;
        }
        result = min(result, city_sum);        // 도시 중 가장 작은 치킨거리 구한다
    }while(next_permutation(idx, idx+chicken.size()));       // 순열
        
    cout << result << '\n';
}