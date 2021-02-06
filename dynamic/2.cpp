#include <iostream>
#include <vector>

using namespace std;

#define Min(a, b) a < b ? a : b

int N;

int main() {
    cin >> N;
    int cnt = 0;
    vector<int> d(3001, 0);  //벡터에 공간 30001 만들고 0 넣기

    for (int i = 2; i <= N; i++) {  //2부터 원하는 숫자까지 시작
        d[i] = d[i - 1] + 1;    //맨처음엔 직전의 +1 수 지정

        if (i % 2 == 0) //2로 나누어진다면 
            d[i] = Min(d[i], d[i / 2] + 1);
        if (i % 3 == 0)
            d[i] = Min(d[i], d[i / 3] + 1);
        if (i % 5 == 0)
            d[i] = Min(d[i], d[i / 5] + 1);
    }

    cout << d[N];
}