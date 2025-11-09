// [BOJ1654] 랜선 자르기 / 실버 2 / 이분탐색ㄷ / 0 ms / 2060 KB
/*
    문제 입, 출력

    문제 방향

        1. parametric search

        2. 0 ~ 2^31 - 1 범위에서 이분 탕색으로 구할 수 있음.

        3. mid 범위 +1 하여 st 무한 루프 방지 

*/

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int n,k;
int arr[10'001];

int solve(int x){
    int cur = 0 ;
    for(int i = 0 ; i < k; i ++) cur += arr[i]/x;
    return cur >= n;
}


int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);
    

    cin >> k >> n;
    for(int i = 0 ; i < k ; i ++  ) cin >> arr[i];
    
    ll st = 0;
    ll en = 0x7fff'ffff;
    

    //  0 ~ 2^31 - 1 범위에서 이분 탕색으로 구할 수 있음.
    while(st < en){
        //  mid 범위 +1 하여 st 무한 루프 방지 
        ll mid = (st + en + 1 ) / 2;
        
        if(solve(mid)) st = mid;
        else en = mid - 1;
    }


    cout << st ;
                               
}