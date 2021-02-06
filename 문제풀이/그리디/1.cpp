#include <bits/stdc++.h>

using namespace std;

int N, X, cnt =0;

int main(){
    cin >> N;
    vector <int> v;
    int tmp;
    for(int i =0 ;i<N; i++){
        cin >> tmp ;
        v.emplace_back(tmp); 
    }
    sort(v.begin(), v.end(), greater<int>());
    int size = v.size();
    int i = 0;
    while(i < v.size()){
        if(v[i] <= size){
            cnt += 1;
            size -= v[i];
            i += v[i];
        }
        else{
            break;
            i++;
        }
    }
    cout << cnt << "\n";
    return 0;
}