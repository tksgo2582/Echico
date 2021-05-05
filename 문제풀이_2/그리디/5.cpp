//볼링공 고르기
/* 
    중복은 걸러도 되는듯?
    A 기준으로 작은 무게 개수 * 남은 공 개수로 반복
 */
#include <bits/stdc++.h>
using namespace std;

int N,M;
int arr[1010] = {0,};

int main(){
    cin >> N >> M;

    for(int i =0 ; i < N; i++){
        int tmp;
        cin >> tmp;
        arr[tmp]++;
    }

    int cnt =0;
    for(int i = 1 ; i <= M; i++){
        N -= arr[i];
        cnt += arr[i] *N;
    }
    cout << cnt <<'\n';
}