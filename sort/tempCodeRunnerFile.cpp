#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(){
    int N,K;
    int tmp;
    vector <int> A,B;
        for(int j =0 ; j < N; j++){
            cin >>tmp;
            A.emplace_back(tmp);
        }
        for(int j =0 ; j < N; j++){
            cin >>tmp;
            B.emplace_back(tmp);
        }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<int>());

    for(int i =0; i < K;){
        if(A[i] < B[i]){
            tmp = A[i];
            A[i] = B[i];
            i++;
        }
        else
        {
            break;
        }
        int sum=0;
    }
    for(auto i : A){
        sum += i;
    }
    cout <<sum;

}