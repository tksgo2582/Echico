//치킨배달
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
    // 각 집의 치킨거리 미리 구하기
    int chicken_d[N];
    fill(chicken_d, chicken_d+N, INF);

    /* for(int i = 0; i < home.size(); i++){
        for(int j = 0; j < chicken.size(); j++){
            int distance = abs(home[i].first - chicken[j].first) + abs(home[i].second - chicken[j].second);
            chicken_d[i] = min(chicken_d[i], distance);
        }
    } */

    int idx[N]={0,};    //순열을 조합으로 사용하기 위한 배열
    for(int i =0 ; i < M; i++){
        idx[i] = 1;
    }
    int result = INF;
    do{
        vector<pair<int, int>> choice;
        int city_sum = 0;
        for(int i =0; i < N; i++){
            if(idx[i] == 1){
                choice.push_back(chicken[i]); //M개의 치킨집 뽑기
            }
        }
        for(int i = 0; i < home.size(); i++){
            int min_distance = INF;
            for(int j = 0; j < choice.size(); j++){
                int distance = abs(home[i].first - choice[j].first) + abs(home[i].second - choice[j].second);
                min_distance = min(min_distance, distance);
            }
            city_sum += min_distance;
        }
        result = min(result, city_sum);        // 도시 중 가장 작은 치킨거리 구한다
    }while(next_permutation(idx, idx+N));       // 순열

    cout << result << '\n';
}