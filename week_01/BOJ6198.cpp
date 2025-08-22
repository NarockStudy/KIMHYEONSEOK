// [BOJ6198] 옥상 정원 꾸미기 / 골드5 / 스택 / 180 ms / 2152 KB

/* 결국 보임 당하는 기준으로 설정함.
    문제 입력 n : int 적당 | h : long long 설정
    문제 출력 ans : 최대가 (n*(n-1) / 2) ~= 80'000 * 40'000 = 3'200'000'000 == 32억 이므로 long 또는 long long

    문제 입력 예시 과정 : 
        1번이 스택에 들어간다.
        2번이 들어올때, 1번과 크기 비교.
            1번 높이 > 2번 높이 이면 + st.size 
            st에 push
        3번 들어올때, 2번과 크기 비교
            2번 높이 < 3번 높이 이면 pop
                1번 높이 > 3번 높이 이면 + st.size 
            st에 push

        4번 들어올때, 3번과 크기 비교,
            4번 높이 > 3번 높이 이면 + st.size 

            st.push

        5번 들어올때, 4번과 높이 비교,
            5번보다 전부 작으므로 전부 pop
            st.push

        6번 들어올때, 5번과 높이 비교 
            6번  < 5번 이므로  + st.size 

            st.push

*/

#include<bits/stdc++.h>
using namespace std;

int n;
stack<int> st;
long long h;
long long ans;


int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n ;

    while(n--){
        cin >> h ;
        // stack 엠티 확인 +  st.top 과 입력과 비교 , 숏 서킷 룰
        while(!st.empty() &&st.top() <= h )  st.pop();       
         // st 원소들은 자동으로 스택에 내림차순으로  정렬 == Monotonic Stack Algorithm

        ans += st.size(); // 입력마다 보임 당하는 것의 갯수들 더함.

        // cout << st.size() << '\n';   // Debug 

        st.push(h); // st 원소들보다 무조건 작은 값이 들어가게 됨.
    }

    cout << ans;
}