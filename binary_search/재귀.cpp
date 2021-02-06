#include <iostream>
#include <vector>

using namespace std;
//재귀 이진탐색 코드
int binary_search(int *array, int target, int start, int end){
    if(start > end) //while 문으로 바꾸면 반복문 이진탐색
        return ;
    int mid = (start + end) / 2;

    if (array[mid] == target){
        return mid;
    }
    else if(array[mid] > target){
        return binary_search(array, target, start, mid-1);
    }
    else
    {
        return binary_search(array, target, mid+1, end);
    }
    
}


int main(){

}