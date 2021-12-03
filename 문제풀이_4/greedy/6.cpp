/* 
    그리디
    음식시간 작은순으로 pq에 넣고
    처음부터 한번에 삭제... 
 */
#include <queue>
#include <string>
#include <vector>
#include<algorithm>

using namespace std;

int cmp(pair<int, int> a, pair<int, int>b){
    return a.second < b.second;
}

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    long long summury = 0;
    for (int a : food_times) {
        summury += a;
    }
    if (summury <= k) {         // 방송 시간이 총 음식 시간보다 작거나 같다면 -1  
        return -1;
    }

    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < food_times.size(); i++) {
        pq.push({-food_times[i], i + 1});
    }
    // 시간계산
    summury = 0;                        //사용시간
    long long pre = 0;                  //직전 다 먹은 음식 시간
    long long len = food_times.size();  //남은 음식 개수
            // 사용시간 + (현재음식시간 - 직전 사용시간)*음식개수 가 방송시간보다 적으면 진행..
    while(summury + ((-pq.top().first - pre)*len) <= k){
        int now = -pq.top().first;
        pq.pop();
        summury += (now - pre) * len;
        len -= 1;
        pre = now;
    }

    vector<pair<int, int>> result;
    while(!pq.empty()){
        int food_time = -pq.top().first;
        int num = -pq.top().second;
        pq.pop();
        result.push_back({food_time, num});
    }
    sort(result.begin(),result.end(), cmp);
    // 남은것 중에서 시간 % 개수로 선택
    return result[(k-summury) % len].second;
}