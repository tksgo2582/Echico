//럭키스트레이트
#include <bits/stdc++.h>
using namespace std;

int N;

int main(){
    string str;
    cin >> str;

    int len = str.size();
    int right=0, left=0;
    for(int i =0 ; i < len; i++){
        if(i < len/2)
            right += str[i]-'0';
        else {
            left += str[i]-'0';
        }
    }
    if(right == left)
        cout << "LUCKY\n";
    else {
        cout << "READY\n";
    }
}