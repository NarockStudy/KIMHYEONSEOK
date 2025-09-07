// [BOJ15486] 퇴사 2 / 골드 5 / DP / 200 ms / 25460 KB
/*
    문제 입,출력
        n       :       ~1'500'000      int
        
        d[n+@]                          int
        t[n+@]                          int
        o[n+@]                          int

    문제 방향

        테이블 정의
            d[i] : i번째 날 아침까지 얻을 수 있는 최대 수익
        점화식 정의
            d[i] = max(d[i], d[i-1])
            d[i+t[i]] = max(d[i+t[i]],d[i]+p[i])    (i + t[i] <= n+1)

        초기식 정의
             d[0] = 0
*/

#include<bits/stdc++.h>
using namespace std;

const int NMX = 1'500'001;
int n;
int p[NMX],t[NMX];
long long d[NMX];
int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n ;
    for(int i = 1 ; i <= n ; i ++) cin>> t[i] >> p[i] ;

    for (int i = 1; i <= n; ++i) {
        // 전날까지의 최댓값을 i일 갱신
        d[i] = max(d[i], d[i - 1]);

        // i일에 상담 시작 → 종료 시점으로 점프
        int en = i + t[i];
        if (en <= n + 1) {
            d[en] = max(d[en], d[i] + p[i]);
        }
    }
    
    
    d[n + 1] = max(d[n + 1], d[n]);

    cout << d[n + 1] << '\n';
}
