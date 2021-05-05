#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = s.size();
    for(int step = 1; step < s.size()/2+1; step++){ // 절반만큼 압축수 늘려가며 진행
        string compressed = "";                     // 압축된 문자열
        string prev = s.substr(0, step);            // 반복 기준 문자
        int cnt = 1;
        for(int j = step; j < s.size(); j +=step){  // step 크기만큼 문자열 비교 반복
            if(prev == s.substr(j,step)){           // prev 와 같다면 cnt++
                cnt++;
            }
            else{                         //다른게 나온경우 이전까지 반복된거 넣어주기
                compressed += (cnt >= 2) ? to_string(cnt)+prev : prev;
                prev = s.substr(j,step); // 갱신
                cnt = 1;
            }
        }
        compressed += (cnt >= 2) ? to_string(cnt)+prev : prev;
        answer = min(answer, (int)compressed.size());
    }
    return answer;
}