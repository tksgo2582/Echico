#include <bits/stdc++.h>
using namespace std;
// 지나온 스테이지에 도달했던 사람들 모두++, 계수정렬?
// count ? 활용해서 각 스테이지에 머물러 있는 사람 체크
// -> 스테이지별 실페율 계산 , int,int 벡터에 스테이지, 실패울 저장, 정렬
bool cmp(pair<double,int> v1, pair<double,int> v2){
    if(v1.first == v2.first){
        return v1.second < v2.second;
    }
    return v1.first > v2.first;
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<double> player(N+1,0);
    vector<double> stay(N+1,0);
    for(auto a : stages){
        for(int i = 1 ; i <= a; i++){
            if(i != N+1)
                player[i]++;
        }
        
        if(a == N+1)
            continue;
        stay[a]++;
    }
    vector<pair<double, int>> fail_rate;
    for(int i = 1; i <= N; i++){
        double rate;
        if(player[i] == 0)
            rate = 0;
        else{
            rate = stay[i]/player[i];
        }
        fail_rate.push_back({rate, i});
        //cout << rate << " " << i << "\n";
    }
    sort(fail_rate.begin(), fail_rate.end(),cmp);
    for(auto a : fail_rate){
        answer.push_back(a.second);
    }
    return answer;
}