//금광
#include <bits/stdc++.h>
using namespace std;

int T ,n, m;
int arr[20][20]={0,};

int main(){
// 입력받고

    for(int i = 0; i < n; i++){
        for(int j = 0 ; j < m; j++){
            arr[i][j] = max(arr[i-1][j-1], max(arr[i-1][j], arr[i-1][j+1])); 
        }
    }
}