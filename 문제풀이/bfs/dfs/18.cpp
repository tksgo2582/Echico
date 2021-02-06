#include <string>
#include <vector>

using namespace std;
string S;
int balancedIndex(string p){ // 괄호개수 체크
    int cnt = 0;
    for(int i = 0; i < p.size(); i ++){
        if(p[i]== '('){
            cnt++;
        }
        else if(p[i] == ')'){
            cnt--;
        }
        if(cnt == 0){   //균형잡힌 괄호의 인덱스 넘겨준다
            return i;
        }
    }
    return -1;
}
bool checkProper(string p){ //올바른 괄호인지 체크
    int cnt = 0;
    for(int i = 0; i < p.size(); i ++){
        if(p[i]== '('){ // '('로 먼저 시작하는지 체크
            cnt++;
        }
        else{           // ')' 나왔는데 이미 cnt가 0이라면 잘못된 괄호
            if(cnt == 0){
                return false;
            }
            cnt--;      // 감소할게 있다면 --
        }
    }
    return true;
}

string solution(string p) {
    string answer = "";
    if(p=="") 
        return "";
    int index = balancedIndex(p); // u 배열을 뽑을 인덱스 찾기
    string u = p.substr(0, index + 1); // 인덱스 +1 해야 원하는 길이
    string v = p.substr(index + 1); // index+1 부터 끝까지 v에 저장
    if(checkProper(u)){             //올바른 괄호인지 체크
        answer = u + solution(v);   // u는 정답에 넣고 v에 대해서 다시 solution함수 실행
    }
    else{                           //올바른 괄호가 아니라면
        answer = "(";               //'(' 부착
        answer += solution(v);      // 
        answer += ")";              //
        u = u.substr(1, u.size() - 2);  //4-4첫번째와 마지막 문자를 제거한 뒤
        for(int i = 0; i < u.size(); i++){ // 4-4 문자열에 남아있는 괄호들의 방향 뒤집기
            if(u[i] == '(')
                u[i] =')';
            else
                u[i] ='(';
        }
        answer += u;
    }
    return answer;
}