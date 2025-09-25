// [BOJ14956] Philosopher’s Walk / 골드 2 / 재귀 / 0 ms / 2020 KB
/*
    문제 입, 출력
        n       :       ~2^15               int
        m       :       ~2^30               int  

        ans                                 pair<int,int>
    문제 방향
        base condition 
            k == 2 (W1)
                1,1 -> 2,1 -> 2,2 -> 2,1 
            
        먼저 사분면 개념으로 보자면 
            왼쪽 하단 0사분면,  왼쪽 상단을 1사분면
            오른쪽 하단 3사분면  오른쪽 상단 2사분면
        
        매개변수는 한 변의 길이 k 와 사분면을 알려주는 w 로 구성
        
        base condition에 도달하면, ans 에 w1 에 해당되는 좌표 설정

        도달 이후 k = 2 부터 .... k = n 까지 좌표를 더해줘야 된다.

            half * half :   한 사분면의 수 
            val = w / (half * half) : k 일때의 몇 사분면인가?
            
                0 사분면(왼쪽 하단) 일 경우, y = x 대칭을 하여 처리
                    2 3         ->      4 3
                    1 4         ->      1 2
                1 사분면인 경우,    y만 half 만큼 증가하여 처리

                2 사분면인 경우, x,y half 증가시켜 처리

                3 사분면인 경우, y = -x + half  +1 대칭 이동 + y 축 half 감소하여 처리
                        



*/

#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second
pair<int,int> ans = {0,0};

void solve(int k, int w){
    //base condition
    if(k == 2 ){
        if(w == 0) ans = {1,1};
        else if(w == 1) ans = {1,2};
        else if(w == 2) ans = {2,2};
        else if(w == 3) ans = {2,1};

        return;
    }

    int half = k / 2;        
    
    solve(half, w % (half*half) );

    int val = w / (half*half) ;              // 몇 사분면인지 확인.

    if(val == 0)  swap(ans.X,ans.Y);       //  y = x 대칭을 하여 처리
    else if(val == 1 ) ans.Y += half;       // y 축 half 평행 이동 
    else if(val == 2 ) {                    // x,y 축 half 평행이동 
        ans.X += half;
        ans.Y += half;
    }
    else if(val == 3 ) {
        // y = -x + half + 1 대칭 이동 
        int tmp_x = half - ans.Y + 1;
        int tmp_y = half - ans.X + 1;
        // y축 방향으로 -half 평행이동 
        tmp_x = tmp_x + half ;
        ans = {tmp_x,tmp_y};
    }
    
    

}


int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);
    

    int n,m;
    cin >> n >> m;

    solve(n,m-1);   // 0 - indexed

    cout << ans.X << ' ' << ans.Y;

}