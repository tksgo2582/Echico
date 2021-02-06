#include <iostream>
#include <vector>

using namespace std;

int N;
vector <int> v(1000, 0);

int main(){
    cin >> N;

    v[1] = 1;   //타일 하나 깔기
    v[2] = 3;   //타일 2개 깔기
    for(int i =3 ; i<= N; i++)
        v[i] = v[i-1]+ v[i-2]*2;    //한칸 비어 있었을시 경우의 수 1개
                                    //두칸 비어 있었을시 경우의 수 2개
    cout << v[N];
}