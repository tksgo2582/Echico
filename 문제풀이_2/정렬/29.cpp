//공유기 설치
#include <bits/stdc++.h>
using namespace std;

int N, C;
vector<int> v;

int main(){
    cin >> N >> C;
    int tmp;
    for(int i = 0; i< N; i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    int low = 1 , hi = v.back() - v[0];
    int mid, result = 0;
    while(low <= hi){
        mid = (low + hi)/2;
        int val = v[0];
        int cnt = 1;
        for(int i = 1 ; i < N; i++){
            if(v[i] >= val + mid){
                val = v[i];  
                cnt++;
            }
        }
        if(cnt >= C){
            low = mid + 1;
            result = mid;
        }else{
            hi = mid -1;
        }
    }
    cout << result <<'\n';
}