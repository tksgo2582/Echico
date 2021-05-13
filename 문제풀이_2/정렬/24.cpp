//안테나
#include<bits/stdc++.h>

using namespace std;

int N;
vector<int> v;

int main(){
    cin >> N;
    int tmp;
    for(int i = 0 ; i < N; i++){
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    cout << v[(v.size()-1)/2] << '\n';
}