// [Codetree바이러스 검사] 바이러스 검사 / L4 / Basic / 349 ms / 4 MB

/*
    
    1. 검사팀장 먼저 검사 인원 제거 
    2. 검사팀원 검사 인원이 있다면, 검사 인원 올림으로 나눗셈으로 제거
    
    ans : 최대는 식당 갯수(n) * 검사 1명 가능 * 고객의 수 (n) == 10^12

*/
#include <bits/stdc++.h>
using namespace std;

int n;
int cust[1'000'001];
int ldr,mbr;

long long ans;

int main() {
    // Please write your code here.

    cin >> n;
    for(int i = 0 ; i < n ; i++) cin >> cust[i];
    cin >> ldr >> mbr ;

    for(int i = 0 ; i < n ; i++) {
        cust[i] -= ldr;
        ans ++;
        // 나눗셈 올림 
        if(cust[i]) ans += (cust[i] + mbr - 1) / mbr;
    }
    

    cout << ans;

    return 0;
}