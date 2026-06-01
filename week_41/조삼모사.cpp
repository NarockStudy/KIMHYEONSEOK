// 	[Codetree] 조삼모사 / L9 / 백트레킹 / 54 ms / 0 MB

/*
    문제 입, 출력

    문제 방향
        1. next_permutation을 이용한 풀이

        2. 절반 선택을 할 것.
            2.1. 아침과 저녁을 선택하면, 한번씩 중복이 생긴다. 1,2 vs 3,4 / 3,4 vs 1,2
                따라서 1번을 고정으로 저녁으로 만들면 중복이 생기지 않음.
        
        3. 절반 선택된 것을 Pab + Pba 더하기 

*/

#include<bits/stdc++.h>
using namespace std;

int n;
int board[40][40];


int ans = 0x3f3f3f3f;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);
    

    cin >> n;
    for(int i = 1; i <= n ; i ++)
        for(int j = 1; j <=n ; j ++)
            cin >> board[i][j];
    
    
    int half = n / 2;

    int sel[n] = {};
    for(int i = half; i < n; i ++) sel[i] = 1;
    // for(int i = 0 ; i < n ; i ++ ) cout << sel[i];

    do{
        vector<int> m_idx,e_idx;
        int m_v = 0,e_v = 0;
        for(int i = 0 ; i < n ; i ++ ) {
            if(sel[i]) m_idx.push_back(i+1);
            else e_idx.push_back(i+1);
        }

        for(int i = 0; i < half -1; i++){
            for(int j = i + 1 ; j < half ; j ++){
            m_v += board[m_idx[i]][m_idx[j]] + board[m_idx[j]][m_idx[i]];
            e_v += board[e_idx[i]][e_idx[j]] + board[e_idx[j]][e_idx[i]];
            }
        }


        int diff_me = abs(m_v - e_v);
        if(ans > diff_me)  ans = diff_me;


    } while(next_permutation(sel+1,sel+n));
    


    cout << ans;

}