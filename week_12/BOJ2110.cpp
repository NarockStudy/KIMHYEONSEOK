// [BOJ2110] 공유기 설치 / 골드 4 / 이분탐색 / 32 ms / 2800 KB
/*
    문제 입, 출력

    문제 방향
        1. n 개 의 집, c개의 공유기 갯수
        
        2. 파라메트릭 서치로 풀이

        3. solve의 x 는 인접한 거리 기준

        4. 인접한 거리를 0 ~ 10^9 까지 이분탐색 

*/

#include<bits/stdc++.h>
using namespace std;

int n,c;
int arr[200'001];


// solve의 x 는 인접한 거리 기준
bool solve(int x){
    int cnt = 1;
    int last = arr[0];

    for(int i = 1 ; i < n ; i ++ ){
        if(arr[i] - last >= x){
            cnt ++;
            last =arr[i];
        }
    }


    return  (cnt >= c);
}

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> c;
    for(int i = 0 ; i < n;  i ++) cin >> arr[i];
    sort(arr,arr+n);

    int st = 0;
    int en = 1'000'000'000;

    // 인접한 거리를 0 ~ 10^9 까지 이분탐색 
    while(st < en ){
        int mid = (st + en + 1) / 2;
        if(solve(mid)) st =mid;
        else en = mid - 1;

    }

    cout << st ;

    
}