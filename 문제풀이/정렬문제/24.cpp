//안테나 ... 이분정렬로 풀려고 했는데, mid 나누는 기준이 애매해져서...
// 중간값을 이용하면 간단하게 해결 가능
#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> v;

int main(){
    cin >> N;
    int tmp;
    for(int i =0 ; i < N; i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());

    int low = v[0], hi = v.back();
    int mid, result = INT_MAX; 
    int result_pos;
    while(low <= hi){
        mid = (low + hi)/2;
        int distance = 0;
        for(auto i : v){
            distance += abs(i - mid);
        }

        if(result > distance){
            hi = mid-1;
            result = min(result, distance);
            result_pos = mid;
        }
        else{
            low = mid+1;
        }
    }
    cout << result_pos;
}