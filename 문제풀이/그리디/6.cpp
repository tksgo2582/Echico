#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    long long summary = 0;
    for (int i = 0; i < food_times.size(); i++) {
        summary += food_times[i];
    }
    if (summary <= k) 
        return -1;
    
    // long long min = *min_element(food_times.begin(), food_times.end());
    // k -= min*food_times.size();
    priority_queue <pair<int,int>> pq;
    for (int i = 0; i < food_times.size(); i++) {
        pq.push({-food_times[i], i+1});
    }
    long long before = 0, length = food_times.size();
    summary = 0;
    
    while(summary + (-pq.top().first - before)* length <= k){
        int now = -pq.top().first;
        pq.pop();
        summary += (now - before) * length;
        length--;
        before = now;
    }
    vector<pair <int, int>> result;
    
    while(!pq.empty()){
        int food_time = -pq.top().first;
        int num = pq.top().second;
        pq.pop();
        result.push_back({num,food_time});
    }
    sort(result.begin(), result.end());
    return result[(k-summary) % length].first;
}