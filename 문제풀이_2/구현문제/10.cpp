//자물쇠와 열쇠
/* 
    자물쇠를 3배 더 크게 해서 생각. 
 */
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> rotateMatrixBy90(vector<vector<int>> a){
    int n = a.size();
    int m = a[0].size();
    vector<vector<int>> result(n, vector<int>(m));
    for(int i = 0; i <n ; i++){
        for(int j =0 ; j < m; j++){
            result[j][n - i -1] = a[i][j]; //*90도 돌리는법
        }
    }
    return result;
}

bool check(vector<vector<int>> newLock){
    int lockLen = newLock.size() / 3;
    for(int i = lockLen; i < lockLen *2; i++){
        for(int j = lockLen; j <lockLen *2; j++){
            if(newLock[i][j] != 1)
                return false;
        }
    }
    return true;
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int n = lock.size();
    int m = key.size();

    vector<vector<int>> newLock(n*3, vector<int>(n*3)); // 자물쇠의 크기를 3배 키워서 가운데에 저장
    for (int i =0; i< n; i++) {
        for(int j =0;  j < n; j++){
            newLock[i+n][j+n] = lock[i][j];
        }
    }

    for(int r =0; r < 4; r++){      //4번 회전..
        for(int x = 0; x < n*2; x++){   // x,y 는 자물쇠
            for(int y = 0; y < n*2; y++){
                for(int i = 0; i < m; i++){ // i,j 는 열쇠
                    for(int j = 0; j < m; j++){
                        newLock[x+i][y+i] += key[i][j]; // 각 위치에 두개의 합 저장
                    }
                }
                if(check(newLock)){     // 가운데 자물쇠가 모두 1이 되는지 체크
                    return true;
                }
                for(int i = 0; i < m; i++){     // 더했던거 다시 제자리로...
                    for(int j = 0; j < m; j++){
                        newLock[x+i][y+i] -= key[i][j];
                    }
                }
            }
        }
    }
    return false;
}