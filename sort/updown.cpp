#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N, tmp;
    vector <int> v;
    cin  >> N;
    for(int i =0 ;i < N; i++){
        cin >> tmp;
        v.emplace_back(tmp);
    }
    
    sort(v.begin(), v.end(), greater<int>());

    for(auto i : v){
        cout << i<< " ";
    }

    return 0;
}