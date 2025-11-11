// [BOJ15688] 수 정렬하기 5 / 실버 5 / 정렬 I / 4220 ms / 5928 KB
/*
    문제 입,출력

    문제 방향
        1. 기본 sort STL 쓰면 됨.
*/

#include<bits/stdc++.h>
using namespace std;

int n;
int arr[1'000'001];

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);


    cin >> n;
    for(int i = 0 ; i < n ; i ++) cin >> arr[i];
    sort(arr,arr+n);

    for(int i = 0 ; i < n ; i ++ ) cout << arr[i] <<'\n';
    
    
}

