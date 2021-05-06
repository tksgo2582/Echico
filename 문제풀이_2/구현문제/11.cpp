// 벰
#include <bits/stdc++.h>
using namespace std;
char next_direction(char snake_d, char mv_d);
int N, K, L;
char snake_d = 'R'; // 처음 뱀머리 방향

int main(){
    cin >> N >> K;
    vector<vector<int>> graph(N+1, vector<int>(N+1,0));   // 도스 게임의 맵
    queue<pair<int, int>> snake;
    snake.push({1,1});
    graph[1][1] = 2;        // 뱀의 시작위치
    for(int i = 0; i < K; i++){
        int a,b;
        cin >> a >> b;
        graph[a][b] = 1;    //사과가 있는 위치 맵에 저장
    }
    cin >> L;
    queue<pair<int, char>> mv;
    for(int i = 0; i < L; i++){
        int a; char b;
        cin >> a>> b;
        mv.push({a,b});    // 뱀의 이동 저장(L 왼쪽,D 오른쪽)
    }
    int cnt = 0;
    while(!mv.empty()){
        int mv_n = mv.front().first;    //첫번째 이동 거리 및 방향 
        char mv_d = mv.front().second;
        mv.pop();
        int x,y, tail_x, tail_y;
        x = snake.back().first;    //현재 뱀 머리 위치
        y = snake.back().second;
        while(1){
            cnt++;
            tail_x = snake.front().first;    //현재 뱀 꼬리 위치
            tail_y = snake.front().second;
            if(snake_d == 'R'){     //현재 뱀머리 방향
                if(mv_d == 'L'){    // 이동할 방향
                    y -= 1;
                }else{
                    y += 1;
                }
            }else if(snake_d == 'L'){
                if(mv_d == 'L'){    // 이동할 방향
                    y += 1;
                }else{
                    y -= 1;
                }
            }else if(snake_d == 'U'){
                if(mv_d == 'L'){    // 이동할 방향
                    x -= 1;
                }else{
                    x += 1;
                }
            }else if(snake_d == 'D'){
                if(mv_d == 'L'){    // 이동할 방향
                    x += 1;
                }else{
                    x -= 1;
                }
            }
            if(x <=0 || x > N || y <= 0 || y > N || graph[x][y] == 2){
                cout << cnt << '\n';
                return 0;
            }
            if(graph[x][y] == 0){   // 사과 없을 경우
                graph[tail_x][tail_y] = 0; // 맵에서 뱀 꼬리 부분 삭제
                snake.pop();    // 뱀꼬리 이동
            }
            snake.push({x, y}); //뱀이 이동한 곳 저장
            graph[x][y] = 2;
        }
        snake_d = next_direction(snake_d, mv_d);
    }
    cout << cnt << '\n';
    return 0;
}

char next_direction(char snake_d, char mv_d){
    char result;
    if(snake_d == 'R'){     //현재 뱀머리 방향
        if(mv_d == 'L'){    // 이동할 방향
            result = 'U';
        }else{
            result = 'D';
        }
    }else if(snake_d == 'L'){
        if(mv_d == 'L'){    // 이동할 방향
            result = 'D';
        }else{
            result = 'U';
        }
    }else if(snake_d == 'U'){
        if(mv_d == 'L'){    // 이동할 방향
            result = 'L';
        }else{
                result = 'R';
            }
    }else if(snake_d == 'D'){
        if(mv_d == 'L'){    // 이동할 방향
            result = 'R';
        }else{
            result = 'L';
        }
    }
    return result;
}