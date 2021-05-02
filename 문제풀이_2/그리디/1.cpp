// 모험가 길드
// 1. deque 에 넣고 내림차순 정렬
// 2. 첫번째 원소 빼고 그 수만큼 반복문으로 원소 제거  -> 헹동 후 cnt++
// 3. 더 이상 제거 할 원소 없다면 반복문 끝
#include <bits/stdc++.h>
using namespace std;

int N;
deque <int> people;
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    int tmp;
    for(int i = 0 ; i < N; i++){
        cin >> tmp;
        people.push_back(tmp);
    }
    sort(people.begin(), people.end(), greater<int>());
    int cnt = 0;
    bool flag = 0;
    while(!people.empty()){
        int X = people.front();

        for(int i = 0 ;i < X; i++){
            if(people.empty()){
                flag = 1;
                break;
            }
            people.pop_front();
        }
        if(!flag)
            cnt++;
    }
    cout << cnt<<'\n';
}