#include <bits/stdc++.h>

using namespace std;
int mat[50][50];
int unions[50][50];
int N,L,R, totalcnt=0;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void bfs(int x, int y, int index){
    vector<pair<int, int>> united;  //연합한 나라들 
    united.push_back({x,y});
    queue<pair<int, int>> q;
    q.push({x,y});
    unions[x][y] = index;       // 몇번째 연합인지 체크
    int summary = mat[x][y];    //연합한 나라 인구수
    int cnt = 1;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i =0 ; i < 4; i++){ // 4방향 돌아보며 연합 가능한지 확인
            int nx = x +dx[i];
            int ny = y +dy[i];
            if(0 <= nx && nx < N && 0 <= ny && ny < N && unions[nx][ny] ==-1){ // 그래프 안넘어가고, 기존의 연합 없던 곳
                int gap= abs(mat[x][y] - mat[nx][ny]);      // 나라간의 인구차이
                if(L <= gap && gap <= R){                   // 인구차이가 이동가능한 범위 내라면
                    q.push({nx,ny});
                    unions[nx][ny] = index;                 // 몇번째 연합인지 체크
                    summary += mat[nx][ny];
                    cnt +=1;
                    united.push_back({nx,ny});
                }
            }
        }
    }
    for(int i =0; i < united.size(); i++){  //연합한 나라들의 개수만큼 인구 평준화.
        int x = united[i].first;
        int y = united[i].second;
        mat[x][y] = summary/cnt;
    }
}

int main(void){
    // 입력받는 부분 n,l,r  도시형태 mat
    cin >> N >> L >> R;
    for(int i=0; i < N; i++){
        for(int j =0; j < N; j++){
            cin >> mat[i][j];
        }
    }
    while(true){    // 전체 나라들을 모두 순회 할때까지
        for(int i=0; i < N; i++){
            for(int j =0; j < N; j++){
                unions[i][j] = -1;  // 기존 국가들이 연합했는지 안했는지 확인
            }
        }
        int index = 0;              // 몇번째 국가인지 체크
        for(int i=0; i < N; i++){
            for(int j =0; j < N; j++){
                if(unions[i][j] == -1){ //아직 연합하지 않은 국가들은 bfs로 검사
                    bfs(i,j,index);
                    index+=1;           //연합 안한 횟수 검사
                }
            }
        }
        if(index == N*N)            // 모든 국가들이 연합하지 않았다면 종료
            break;
        totalcnt ++;                // 연합한 횟수 ++
    }
    cout << totalcnt << "\n";
    return 0;
}