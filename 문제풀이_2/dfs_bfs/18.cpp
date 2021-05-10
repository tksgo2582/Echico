#include <bits/stdc++.h>

#include <string>
#include <vector>
using namespace std;
string S;
int balancedIndex(string p) {   //2.균형잡힌 괄호 문자열의 인덱스를 알려준다.
    int cnt = 0;
    for (int i = 0; i < p.size(); i++) {
        if (p[i] == '(') {
            cnt++;
        } else if (p[i] == ')') {
            cnt--;
        }
        if (cnt == 0) {
            return i;
        }
    }
    return -1;
}
bool checkProper(string p) {        //올바른 문자열인지 체크
    int cnt = 0;
    for (int i = 0; i < p.size(); i++) {
        if (p[i] == '(') {
            cnt++;
        } else {
            if (cnt == 0) {
                return false;
            }
            cnt--;
        }
    }
    return true;
}

string solution(string p) {
    string answer = "";
    if (p == "")        //1. 빈 문자열
        return answer;
    int index = balancedIndex(p);   //2. 균형잡힌 문자열 u, 나머지 v 로 분리
    string u = p.substr(0, index + 1);
    string v = p.substr(index + 1);
    if (checkProper(u)) {           //3-1. 문자열 u가 올바른 괄호문자열인지 체크
        answer = u + solution(v);   // 3. 올바른 문자열이라면 u에v 붙여서 반환. v는 1단계부터 다시 검사.
    } else {                        //4. 문자열u가 올바른 문자열 아니라면.
        answer = "(";               // 4-1. 빈문자열에 ')'
        answer += solution(v);      //4-2. v에 대해 1단계부터 재귀적 수행
        answer += ")";              //4-3. ')'
        u = u.substr(1, u.size() - 2);  //4-4. u의 첫번째 마지막 제거 후 나머지는 괄호 방향 반대로.
        for (int i = 0; i < u.size(); i++) {
            if (u[i] == '(')
                u[i] = ')';
            else
                u[i] = '(';
        }
        answer += u;                //4-5. 생성된 문자열 반환
    }
    return answer;
}