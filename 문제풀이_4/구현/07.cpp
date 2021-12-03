#include <bits/stdc++.h>

using namespace std;

int main(){
    string S;
    cin >> S;
    int mid = S.size()/2;
    int left=0, right =0;

    for(int i = 0; i < mid; i++){
        left += S[i] - '0';
        right += S[i+mid] - '0';
    }
    if(left == right){
        cout << "LUCKY" << '\n';
    }else{
        cout << "READY" << '\n';
    }
}