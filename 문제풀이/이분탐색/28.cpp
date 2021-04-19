//고정점 찾기
#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, tmp;
    vector <int> v;
    cin >> N;
    for(int i=0; i < N; i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    int low = 0, hi = v.size();
    int mid, result=-1;
    while(low<=hi){
        mid = (low + hi)/2;
        int fixed_point = v[mid];
        if(fixed_point < mid){
            low = mid+1;
        }
        else if(fixed_point > mid){
            hi = mid-1;
        }
        else {
            result = mid;
            break;
        }
    }
    cout << result;
}