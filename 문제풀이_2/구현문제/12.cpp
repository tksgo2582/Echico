#include <string>
#include <vector>
#include <algorithm>
#define N_MAX 110 
#define ground -1
using namespace std;

int graph[N_MAX][N_MAX][2];

bool check_install(int x , int y, int kind){    // 설치하는 경우
    bool flag = 0;
    
    if(kind == 0){  // 기둥인 경우 .... 바닥, 기둥, 보 위에 설치 가능( 공중부양만 피하면 될듯?)
        if(y!= 0 && graph[x][y][1] == 0 && graph[x-1][y][1] == 0 && graph[x][y-1][0] == 0 ){    
            flag = 0;
        }else{
            graph[x][y][0] = 1; //기둥 설치
            flag = 1;
        }
    }else{          // 보 인 경우 .... 한쪽이 기둥, 혹은 양쪽이 모두 보와 연결
        if(y == 0 || graph[x][y-1][0] == 0 && graph[x+1][y-1][0] ==0){
            // 바닥이거나 양쪽에 기둥이 없는 경우 ... 설치X
            if(graph[x-1][y][1] == 1 && graph[x+1][y][1] == 1){
            // 양쪽에 보가 있다면 설치.
                flag =1;
                graph[x][y][1] =1; // 보 설치
            }else
                flag = 0;
        }
        else{
            flag = 1;
            graph[x][y][1] =1; // 보 설치
        }
    }

    return flag;
}

bool check_uninstall(int x , int y, int kind){    // 설치하는 경우
    bool flag, right, left;
    if(kind == 0){  // 기둥인 경우 
        if(graph[x][y+1][1] && graph[x-1][y+1][1]){ // 내 위에 보가 있는 경우
        // 기둥 위에 보의 양쪽끝 중 하나라도 닿아 있는경우 삭제x
            flag = 1;
            graph[x][y][0] = 0; // 기둥 철거
        }else{      // 
            flag = 0;
        }  
    }else{          // 보인 경우
        if (graph[x][y][0] == 0) {     // 기둥이 없는데 다른 보와 연결된 경우
            if(graph[x-1][y][1] && graph[x+1][y][1]){ //보끼리 연결된 경우
                flag = 1;
                graph[x][y][1] = 0;
            }
        }
    }

    return flag;
}
struct Data{
    int x, y, building;
}Data;

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    vector<struct Data> insert;

    for(auto frame : build_frame){
        int x , y, kind, install;
        x = frame[0], y = frame[1];
        kind = frame[2], install = frame[3];
        if(install == 1){       //설치
            if(check_install(x,y,kind)){
                insert.push_back({x,y,kind});
            }
        }else{                  //철거
            if(check_uninstall(x, y, kind)){
                struct Data a = {x,y,kind};  
                auto i = find(insert.begin(), insert.end(), a);
                insert.erase(i);
            }
        }
    }
    for(auto a : insert){
        vector<int> tmp(3);
        tmp[0] = a.x, tmp[1] = a.y , tmp[2] = a.building;
        answer.push_back(tmp);
    }
    sort(answer.begin(), answer.end());
    return answer;
}