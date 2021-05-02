//만들 수 없는 금액
// 해결어려웠음...
/* 
    1. 정렬 후 작은 순서대로 꺼내면서 target이 그 금액에 도달하는지 체크??
    2. target +=a;
 */
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;
bool num[1010] = {false,};

int main(){
    cin >> n;
    int tmp;
    for(int i =0; i <n; i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());

    int target =1;
    for(auto a : v){
        // 만들 수 없는 금액을 찾았을 때 반복 종료
        if(target < a){
            break;
        }
        target += a;
    }
    cout << target << '\n';
}