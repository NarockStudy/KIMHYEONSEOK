// [BOJ2805] 나무 자르기 / 실버 2 / 이분탐색 / 152 ms / 5928 KB
/*
    문제 입, 출력

    문제 방향
        1. 파라메트릭 서치

        2. 랜선 자르기와 같은 로직
        
        3. mid  +1 을 하여 st, en 1 차이날때, 무한 루프 방지

        4. 높이에 따라 m 값 이상인 것 중, 최소 값을 찾음.

*/

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int n,m;
int arr[1'000'001];

bool solve(int x){
    ll cur = 0 ;

    for(int i = 0 ; i < n ; i ++ ) 
        if(arr[i] - x > 0 ) cur += (arr[i] - x);

    return cur >= m ;
}

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);
    

    cin >> n >> m;
    for(int i = 0 ; i < n ; i ++ ) cin >> arr[i];
    // sort(arr,arr+n);
    ll st = 0;
    ll en = 2'000'000'000;
    // ll en = arr[n-1];

    while(st < en){
        //  mid  +1 을 하여 st, en 1 차이날때, 무한 루프 방지
        int mid = (st + en + 1 ) / 2;

        // 높이에 따라 m 값 이상인 것 중, 최소 값을 찾음.
        if(solve(mid)) st = mid;
        else en = mid - 1;
    }


    cout << st ;
    
}