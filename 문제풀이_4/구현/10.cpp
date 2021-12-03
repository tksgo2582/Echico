#include <string>
#include <vector>

using namespace std;

vector<vector<int>> rotate(vector<vector<int>> key){
    int M = key[0].size();
    vector<vector<int>> rotated_key(M, vector<int>(M));
    for(int i = 0 ; i < M; i++){
        for(int j = 0; j < M; j++){
            rotated_key[j][M-i-1] = key[i][j];
        }
    }
    return rotated_key;
}
bool check(vector<vector<int>> lock){
    int N = lock.size()/3;
    for(int i = N; i< N*2; i++){
        for(int j = N; j < N*2; j++){
            if(lock[i][j]!=1)
                return false;
        }
    }
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int N = lock[0].size();
    int M = key[0].size();
    vector<vector<int>> triple_lock(N*3, vector<int>(N*3));
    for(int i = N; i< N*2; i++){
        for(int j = N; j < N*2; j++){
            triple_lock[i][j] = lock[i-N][j-N];
        }
    }

    for(int r = 0 ; r < 4; r++){
    //    vector<vector<int>> rotated_key(M, vector<int>(M));
        key = rotate(key);
        for(int i = 0; i < N*2; i++){
            for(int j = 0; j < N*2; j++){
                for(int x = 0; x < M; x++){
                    for(int y = 0; y <M; y++){
                        triple_lock[x+i][y+j] += key[x][y];
                    }
                }
                if(check(triple_lock)){
                    return true;
                }
                for(int x = 0; x < M; x++){
                    for(int y = 0; y < M; y++){
                        triple_lock[x+i][y+j] -= key[x][y];
                    }
                }
            }
        }
    }
    return false;
}