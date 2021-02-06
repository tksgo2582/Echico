#include <string>
#include <vector>

using namespace std;

vector<vector<int>> rotateMatrixBy90(vector<vector<int>> a) {  // 90돌리는 함수
    int n = a.size();
    int m = a[0].size();
    vector<vector<int>> result(n, vector<int>(m));  // 2차원 배열 생성(n만큼 vector 생성)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            result[j][n - i - 1] = a[i][j];  //*90도 돌리는법
        }
    }
    return result;
}

bool check(vector<vector<int>> newLock) {  // 가운데 자물쇠에 모두 맞는지 체크
    int lockLength = newLock.size() / 3;
    for (int i = lockLength; i < lockLength * 2; i++) {
        for (int j = lockLength; j < lockLength * 2; j++) {
            if (newLock[i][j] != 1)
                return false;
        }
    }
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int n = lock.size();
    int m = key.size();

    vector<vector<int>> newLock(n * 3, vector<int>(n * 3));  //3배 크기의 판 생성
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            newLock[i + n][j + n] = lock[i][j];  // 가운데 자물쇠 배정
        }
    }

    for (int r = 0; r < 4; r++) {          //90도씩 돌려가며 확인
        key = rotateMatrixBy90(key);       //90도 회전
        for (int x = 0; x < n * 2; x++) {  // n*2 까지 해야 전체 확인
            for (int y = 0; y < n * 2; y++) {
                for (int i = 0; i < m; i++) {  //시작점부터 key 크기 만큼
                    for (int j = 0; j < m; j++) {
                        newLock[x + i][y + j] += key[i][j];
                    }
                }

                if (check(newLock))  //들어맞는지 체크
                    return true;
                for (int i = 0; i < m; i++) {  //안맞으면 원상복구
                    for (int j = 0; j < m; j++) {
                        newLock[x + i][y + j] -= key[i][j];
                    }
                }
            }
        }
    }
    return false;
}