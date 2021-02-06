//https://programmers.co.kr/learn/courses/30/lessons/60061 기둥과 보 설치
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool possible(vector<vector<int>> answer){  // 설치,삭제 가능한지 체크
    for(int i = 0; i < answer.size(); i++){
        int x = answer[i][0];
        int y = answer[i][1];
        int stuff = answer[i][2];
        if(stuff == 0){     // 기둥일 경우
            bool check = false;
            if(y == 0)      // 기둥위에 설치 ok
                check =true;
            for(int j = 0; j < answer.size(); j++){ // 보의 한쪽 끝부분 위
                if(x - 1 == answer[j][0] && y == answer[j][1] && 1 == answer[j][2]){
                    check = true;
                }                                   // 보의 한쪽 끝부분 위
                if(x == answer[j][0] && y == answer[j][1] && 1 == answer[j][2]){
                    check = true;
                }                                   // 기둥 위
                if(x == answer[j][0] && y-1 == answer[j][1] && 0 == answer[j][2]){
                    check = true;
                }
            }
            if(!check)
                return false;
        }
        else if(stuff == 1){    // '보'일 경우
            bool check = false;
            bool left = false;
            bool right = false;
            for(int j = 0; j< answer.size(); j++){  //보의 한쪽이 기둥의 위
                if(x == answer[j][0] && y-1 == answer[j][1] && 0 == answer[j][2]){
                    check = true;
                }                                   // 보의 한쪽이 기둥의 위
                if(x + 1 == answer[j][0] && y-1 == answer[j][1] && 0 == answer[j][2]){
                    check = true;
                }                                   // 양쪽이 보와 연결 1
                if(x - 1 == answer[j][0] && y == answer[j][1] && 1 == answer[j][2]){
                    left = true;
                }                                   // 양쪽이 보와 연결 2
                if(x + 1 == answer[j][0] && y == answer[j][1] && 1 == answer[j][2]){
                    right = true;
                }
            }
            if(left&&right)     //양쪽이 보와 연결 되어 있다면
                check = true;
            if(!check)
                return false;
        }
    }
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    for(int i = 0; i < build_frame.size(); i++){
        int x = build_frame[i][0];          //주어진 값들 
        int y = build_frame[i][1];
        int stuff = build_frame[i][2];
        int operate = build_frame[i][3];
        if(operate == 0){           //삭제하는 경우
            int index = 0;
            for(int j =0; j <answer.size(); j++){
                if(x == answer[j][0] && y == answer[j][1] && stuff == answer[j][2]){
                    index = j;      //삭제할 곳의 인덱스 기억
                }
            }
            vector<int> erased = answer[index]; // 삭제 목록 임시 저장
            answer.erase(answer.begin() + index); //해당 인덱스 일단 삭제
            if(!possible(answer)){              // 삭제 불가능하다면
                answer.push_back(erased);       // 다시 정답으로 넣어준다
            }
        }
        if(operate == 1){ // 설치하는 경우
            vector<int> inserted;
            inserted.push_back(x);
            inserted.push_back(y);
            inserted.push_back(stuff);
            
            answer.push_back(inserted);         //정답에 넣어준다
            if(!possible(answer)){              //설치 불가능일시
                answer.pop_back();              // 정답에 넣었던거 삭제
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}