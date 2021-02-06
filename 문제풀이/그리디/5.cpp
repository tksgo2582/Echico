#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[11];
int main(){
    int result = 0;
    cin >> N >> M;
    int tmp, cnt=0;
    for(int i =0 ; i < N; i++){
        cin >> tmp;
        arr[tmp]++;
        if(arr[tmp]>1)
            cnt++;
    }
    result = (N*(N-1))/2;
    result -= cnt;

    cout << result << "\n";
}