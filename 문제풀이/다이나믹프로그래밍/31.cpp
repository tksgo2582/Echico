//금광.. 위,옆에 0 번째 넣어서 편하게 처리
#include <bits/stdc++.h>
using namespace std;

int main(){
    int T, N,M, tmp;
    int arr[22][22] = {0,};
    cin >> T;
    while(T--){
        cin >> N >>M;
        memset(arr, 0, sizeof(arr));
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= M; j++){
                cin >> arr[i][j];
            }
        }
        for(int j = 1; j <= M; j++){
            for(int i = 1; i <= N; i++){
                arr[i][j] += max(max(arr[i-1][j-1], arr[i][j-1]), arr[i+1][j-1]);
            }
        }
        int result=0;
        for(int j = 1; j <= N; j++){
            result = max(result, arr[j][M]);
        }
        cout << result << "\n";
    }
}