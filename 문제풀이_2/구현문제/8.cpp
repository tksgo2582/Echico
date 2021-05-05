// 문자열 재정렬
#include <bits/stdc++.h>
using namespace std;

int main(){
    string str, alpa, num;
    cin >> str;
    int result=0;
    for(auto a : str){
        if(a >= '0' && a <= '9'){
            result += a-'0';
        }
        else{
            alpa.push_back(a);
        }
    }
    //sort(num.begin(), num.end());
    sort(alpa.begin(), alpa.end());

    cout << alpa << result <<"\n";
}