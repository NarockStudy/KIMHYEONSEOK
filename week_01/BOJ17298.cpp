// [BOJ17298] 오큰수 / 골드4 / 스택 / 228 ms / 14328 KB

/*
    문제 입,출력 
        - N,k 은 ~ 1'000'000 이므로 int 
    
        - ans 는 = N int

        시간 제한 1 초 = 3억 ~ 5억 번 가능
        N = 1'000'000 이므로  O(NlgN) O(N) O(lgN) O(1)
    
    문제 방향
        stack 를 내림차순 정렬시켜서 
        top 보다 큰 수가 들어오면 idx에 큰 수 저장.
        
        모든 입력을 받고 난 후 stack의 남아있는 것들의 ans[idx]를 -1 로 처리

*/

#include<bits/stdc++.h>
using namespace std;

struct XY{
    int idx;
    int num;
};
const int MX = 1'000'010;
int n,k;
stack<XY> st;
int ans[MX];
int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;
    
    for(int i = 0 ; i < n ; i  ++) {
        cin >> k ; 
        
        while(!st.empty() && st.top().num < k) {    // 내림차순 정렬
            ans[st.top().idx] = k ;                 // 오큰수 발견시 ans 배열에 저장
            st.pop();                               // 필요없으므로 제거 
        }
        
        st.push({i,k});
    }
    
    while(!st.empty()){                         // 오큰수를 찾지 못한 수들 처리 
        XY xy = st.top();
        ans[xy.idx] = -1;                       // 찾지 못하면 -1로 채움.
        st.pop();
    }

    for(int i = 0 ; i < n ; i ++){
        cout << ans[i] << ' ' ;
    }
}