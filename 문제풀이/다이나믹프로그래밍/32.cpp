//정수 삼각형
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int arr[501][501] = {0,};
    cin >> n;
    for(int i=1; i <= n; i++){
        for(int j=1 ; j <= i ;j++){
            cin >> arr[i][j];
        }
    }
    for(int i=1; i <= n; i++){
        for(int j=1 ; j <= i ;j++){
            arr[i][j]+= max(arr[i-1][j-1], arr[i-1][j]);
        }
    }
    int result=0;
    for(auto a : arr[n]){
        result = max(result, a);
    }
    cout << result<< "\n";
}