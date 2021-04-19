//카드 정렬하기
// 작은 애들부터 검사하면 될까? -> 우선순위 큐 이용해서 차례대로 카운트.
#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, tmp;
    priority_queue <int> v;
    cin >> N;
    if(N == 1){
        cout << 0;
        return 0 ;
    }
    for(int i = 0; i <N ; i++){
        cin >> tmp;
        v.push(-tmp);
    }
    int result=0;
    while(!v.empty()){
        int n1 = -v.top();
        v.pop();
        int n2 = -v.top();
        v.pop();
        result += n1+n2;
        v.push(-(n1+n2));
        if(v.size() == 1){
            break;
        }
    }
    cout << result;
}