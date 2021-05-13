//고정점 찾기  이진탐색 활요하는 문제
#include <bits/stdc++.h>
using namespace std;

int N;
vector <int> v;

int main(){
    cin >> N;
    int tmp;

    for(int i= 0 ; i < N; i++){
        cin >> tmp;
        v.push_back(tmp);
    }

    int low = 0 , hi = v.back();
    int mid; bool flag = 0;
    while(low <=hi){
        mid = (low + hi)/2;
        if(mid == v[mid]){
            cout << mid << '\n';
            return 0 ;
        }

        if(mid < v[mid]){
            hi = mid -1;
        }else{
            low = mid + 1;
        }
    }
    cout << -1 << '\n';
}