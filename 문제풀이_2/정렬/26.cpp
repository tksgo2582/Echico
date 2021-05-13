//카드 정렬하기
/* 
    우선수위 큐를 사용해야 하는 문제
 */
#include<bits/stdc++.h>

using namespace std;

int N;
priority_queue<int> v;

int main(){
    cin >> N;
    int tmp;
    for(int i = 0 ; i < N; i++){
        cin >> tmp;
        v.push(-tmp);
    }
    int result=0;

    while(v.size() != 1){
        int x1 = -v.top();
        v.pop();
        int x2 = -v.top();
        v.pop();

        result += x1+x2;
        v.push(-x1-x2);
    }

    cout << result << '\n';
}