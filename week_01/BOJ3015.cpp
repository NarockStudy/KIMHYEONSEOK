// [BOJ3015] 오아시스 재결합 / 플래티넘5 / 스택 / 072 ms / 6300 KB

/*
    // 참고 https://blog.thecloer.com/121


    1. 서로 바라 보는 쌍 찾기
    2. A B 사이에 A,B 보다 큰 사람이 없어야 된다. (== 같은 사람까지 가능)
    3. stack을 이용해서 입력값과 스택의 탑을 이용하여 쌍 찾을 수 있다.
        stack은 내림차순 정렬 모노톤 스택을 이용하여 구성

    
        t < x
            x 앞에 x보다 제일 큰 놈까지 볼 수 있고, t보다 크거나 같은 사람을 볼 수 있음.

        t = x 
            x 앞에 x보다 제일 큰 놈까지 볼 수 있고, t보다 크거나 같은 사람을 볼 수 있음.
        
        t > x 
            t 밖에 못봄.
       




*/



#include<bits/stdc++.h>
using namespace std;

struct E{int h, cnt;};


int n;
stack<E> st;
long long ans;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n ;
    while(n--){
        int cnt = 1 ;
        int k;
        cin >> k;

        while(!st.empty() && st.top().h <= k){
            ans += st.top().cnt;
            if(st.top().h == k) cnt += st.top().cnt;
            st.pop();
        }

        
        if(!st.empty()) ans ++;
        st.push({k,cnt});
    }
    
    cout << ans;
}

