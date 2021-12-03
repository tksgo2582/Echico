//18 괄호 변환
#include <bits/stdc++.h>
using namespace std;

string W;

bool b_check(string u) {  //올바른 문자열인지 체크
    int right = 0;
    for (int i = 0; i < u.size(); i++) {
        if (u[i] == '(') {
            right++;
        } else if (u[i] == ')') {
            right--;
        }
        if (right < 0) {
            return false;
        }
    }
    return true;
}

string rightString(string W) {
    int balance = 0;
    string U, V;
    for (int i = 0; i < W.size(); i++) {
        if (W[i] == '(') {
            balance++;
        } else if (W[i] == ')') {
            balance--;
        }

        if (balance == 0) {           //균형잡힌 괄호 문자열
            U = W.substr(0,i+1);
            int size = W.size() - U.size();
            if (size == 0) {
                V = "";
            } else {
                V = W.substr(i+1, size);
            }

            if (b_check(U)) {         //3-1 올바른 문자열인지 체크
                U += rightString(V);  // 올바른 문자열이라면 v 에 대해서 1단계 시작
                return U;
            } else {                                       // 4 올바른 문자열 x
                string new_s = "(";                        // 4-1
                new_s += rightString(V);                   // 4-2
                new_s += ")";                              // 4-3
                string new_u = U.substr(1, U.size() - 2);  // 4-4
                for (int i = 0; i < new_u.size(); i++) {
                    if (new_u[i] == '(') {
                        new_s += ")";
                    } else {
                        new_s += "(";
                    }
                }
                return new_s;  // 4-5
            }
        }
    }
    return "";
}

int main() {
    cin >> W;
    string result;
    if (W.empty()) {
        cout << "";
    } else {
        result = rightString(W);
    }
    cout << result;
}