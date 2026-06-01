// 	[Codetree] 외주 수익 최대화하기 / L8 / 백트레킹 / 6 ms / 0 MB

/*
    문제 입, 출력

    문제 방향
        solve : 현재 외주 작업을 선택할 경우, 선택안 할 경우를  재귀 방식으로 표현
        solve_2 : solve 에서 base condition을 제거하고 현재 외주 작업을 선택할 경우 
            퇴사일 보다 작을 경우만 선택함.
        solve_3 : 백트래킹은 next_permutation을 이용함. 

*/

#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second


pair<int,int> arr[20];      // t, p
int n;

int t,ans;



void solve(int cur, int tot){
    if(cur > n ) return;
    if(cur == n) {
        ans = max(ans, tot);
        return;
    }

    solve(cur + arr[cur].X, tot + arr[cur].Y);
    solve(cur + 1, tot);
}

void solve_2(int cur, int tot){
    if(cur == n) {
        ans = max(ans, tot);
        return;
    }

    if(cur + arr[cur].X <= n) solve(cur + arr[cur].X, tot + arr[cur].Y);
    solve(cur + 1, tot);
}

void solve_3(){


    for(int i = 1 ; i <= n ; i ++ ){
        
        int sel[n] = {};
        for(int j = n - i ; j < n; j ++ ) sel[j] = 1;

        // for(int j = 0 ; j < n ; j ++ ) cout << sel[j] ;
        // cout << '\n';

        do{
            bool is_valid = true;
            int cur_t = 0;
            int cur_p = 0 ;
            for(int j = 0 ; j < n ; j ++){
                if(sel[j] == 0 ) continue;

                if(j + arr[j].X > n || j < cur_t ) {
                    is_valid = false;
                    break;
                }

                cur_p += arr[j].Y;
                cur_t = j + arr[j].X;
            }

            if(is_valid) ans = max(ans, cur_p);

        } while(next_permutation(sel,sel+n));



    }


}

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> n;
    
    for(int i =0 ; i < n ; i ++){
        cin >> arr[i].X >> arr[i].Y;
    }


    // solve(0,0);
    // solve_2(0, 0);
    solve_3();
    
    cout << ans;
}