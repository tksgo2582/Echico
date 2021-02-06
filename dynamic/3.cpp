#include <iostream>
#include <vector>

using namespace std;

int N;
vector <int> v(100, 0);

int main(){
    int tmp;
    vector <int> food;
    cin >> N;
    for(int i = 0; i<N; i++){
        cin >>tmp;
        food.emplace_back(tmp);
    }
    v[0] = food[0];
    v[1] = max(food[0], food[1]);
    //cout << v[1]<< " ";

    for(int i = 2; i<N; i++){   //마지막 창고 터는거/ 직전창고 터는거 선택
        v[i] = max(v[i-1], v[i-2] + food[i]);
    }

    cout << v[N-1];
}