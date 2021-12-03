// 29 공유기설치
#include <bits/stdc++.h>
using namespace std;

int N, C;
vector<long long> home;

int main(){
    cin >> N >> C;
    int a;
    for(int i = 0 ; i < N; i++){
        cin >> a;
        home.push_back(a);
    }
    sort(home.begin(), home.end());
    long long low = 0, hi =  home.back();
    long long mid, result;
    while(low<=hi){
        int cnt = 1;
        mid = (low+hi)/2;
        long long start = home[0];  // 첫번째 공유기
        for(int i = 0 ; i < N; i++){
            if(home[i] - start >= mid){ // 공유기 설치 지점과 집 사이의 거리가 mid 이상이라면
                start = home[i];    // 공유기 설치
                cnt++;
            }
        }
        if(cnt < C){    //공유기 모두 설치 못했다면
            hi = mid - 1;
        }else{          // 공유기 모두설치... 공유기간 넓혀서 다시 검사
            low = mid + 1;
            result = mid;
        }
    }
    cout << result;
}