// [BOJ7570] 줄 세우기 / 골드 2 / 그리디 / 96 ms / 5928 KB
/*
    문제 입, 출력
        n       :           ~1'000'000      int
        d[n+@]  :                           int
        
        ans     :                           int
    문제 방향


        1. 테이블 정의
            d[i] : i인 아이를 마지막으로 증가하는 수열의 최대 길이

        2. 점화식 정의
            d[i] = d[i-1] + 1
        3. 초기식 정의
            d[i] = 0


        예외처리
            num 이 1일때, num-1 이 0이고 d[0] = 0 이므로 자동 예외처리
        
*/

#include<bits/stdc++.h>
using namespace std;

int n;
int d[1'000'001];
int num;
int ans;
int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> n;
    for(int i = 0; i <n ; i ++){
        cin >> num;
        d[num] = d[num-1] + 1;
    }
    ans = n - *max_element(d+1,d+n+1);  
    cout << ans;
}