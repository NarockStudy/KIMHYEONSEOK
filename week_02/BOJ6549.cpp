// [BOJ6549] 히스토그램에서 가장 큰 직사각형 / 플래티넘5 / 스택 / 32 ms / 2540 KB

/*
    문제 입, 출력
        - n : 100'000           int
        - h : 1'000'000'000     int 

        - ans ~ n * h                  long long 

    문제 설명
        - 스택의 남아있는 원소는 오름차순 정렬함.
        - 오름차순을 유지하면서, max 넓이 값을 갱신하기 위해 idx 를 조정해야됨.
            - top 보다 같거나 작은 값이 들어오면, 같거나 작아질때까지, 넓이 값 갱신하고 idx 값을 물려줌.
                - idx 값을 물려주는 이유 : pop된 마지막 막대의 idx를 새 막대에 물려주어, 새 막대가 왼쪽으로 최대한 확장할 수 있는 경계를 저장.
        
        - stack의 남은 원소들을 처리
            - 맨 마지막 원소들 이므로 (n - idx * h) 로 처리 가능 
*/



#include<bits/stdc++.h>
using namespace std;

using ll = long long;

struct E{ ll idx,h ; };
int n;
ll ans;
int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);

    
    
    
    while(cin >> n && n != 0){
        ans = 0;
        stack<E> st;
        
        for(int i = 0 ; i < n ; i ++) {
            ll h;
            cin >> h;
            int idx = i;
            while(!st.empty() && st.top().h >= h ){     // 입력값이 st.top 보다 값이 같거나 작을 경우 
                ans = max(ans, (i - st.top().idx) * st.top().h );      // 이때까지 저장되어있던 넓이 계산.
                idx = st.top().idx;                                    // 가장 작은 놈에게 idx 물려주기
                st.pop(); 
            }
            

            st.push({idx,h});
        }

        while(!st.empty()){                                         // 남아있는 원소들 처리 
            ans = max(ans, (n - st.top().idx) * st.top().h );       // 오른쪽 끝 n - idx 를 통해 ans 갱신 시도 
            st.pop();
        }

        cout << ans << "\n";
    }

}