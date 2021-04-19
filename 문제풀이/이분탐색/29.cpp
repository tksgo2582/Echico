//공유기 설치
#include <bits/stdc++.h>
using namespace std;

int main(){
    long long N, C,tmp;
    vector <long long> v;
    cin >> N >> C;
    for(int i =0; i < N; i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end());

    long long result = 0 ;
    long long low = 1, hi = v.back()- v[0];
    long long mid;

    while(low<=hi){
        long long value = v[0]; // 시작지점 지정(시작에 공유기 설치)
        int cnt = 1;       // 현재 설치한 공유기 수
        mid = (low+hi)/2;
        for(long long i = 1; i < N; i++){ 
            if(v[i] >= value + mid){ // 현재 지점에 공유기 설치 가능한지 체크
                value = v[i];       // 공유기 설치된 뒤 다음 공유기 설치위한 위치 지정
                cnt++;
            }
        }
        if(cnt >= C){           // 공유기 모두 설치 가능했다면 
            low = mid+1;        // 공유기 거리 증가 시켜서 다시 측정
            result = mid;
        }else{
            hi = mid-1;
        }
    }
    cout << result;
}