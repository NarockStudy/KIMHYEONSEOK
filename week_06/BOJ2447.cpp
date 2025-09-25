// [BOJ2447] 별 찍기 - 10 / 골드 5 / 재귀 / 104 ms / 6696 KB
/*
    문제 입, 출력
        n   :       ~ 3^7         int

        s[3^7+@][3^7+@]         char
        
    문제 방향

        base condition :
            k == 1  --> 이거 일때는 1x1 디자인
                행렬 가운데 부분만 재귀 형식으로 채우기.
                k x k 의 가운데 부분만 '\0' 이므로 '\0' 일때 빈칸으로 출력
                
            k == 3 ---> 이거 일때는 3x3 디자인
                k == 1 보다 한칸 덜 들어가는 구조.

            

*/

#include<bits/stdc++.h>
using namespace std;

const int MX = 3*3*3*3*3*3*3 + 1; // ~ 2,187 + 1

// char c[3][3] = {
//     {'*','*','*'},
//     {'*',' ','*'},
//     {'*','*','*'},
// };

char s[MX][MX];

void solve(int k, int x, int y){

    /* k == 1 일때 base condition */
    // ==================================
    // if(k == 1){
    //     s[x][y] = '*';
    //     return;
    // }
    // ==================================

    /* k == 3 일때 base condition */
    // ==================================
    if(k == 3){
        s[x][y] = s[x][y+1] = s[x][y+2] = '*';
        s[x+1][y] = s[x+1][y+2] = '*'; s[x+1][y+1] = ' ';
        s[x+2][y] = s[x+2][y+1] = s[x+2][y+2] = '*';
        return;
    }
    // ==================================

    int idx = k /3 ;
    solve(idx, x, y);
    solve(idx, x, y + idx);
    solve(idx, x, y + idx * 2);

    solve(idx, x + idx, y);
    // solve(idx, x + idx, y + idx);        // k x k 의 가운데 비우기.
    solve(idx, x + idx, y + idx * 2);

    solve(idx, x + idx * 2 , y);
    solve(idx, x + idx * 2 , y + idx);
    solve(idx, x + idx * 2 , y + idx * 2);


}


int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);
    

    int n;
    cin >> n ;
    
    solve(n,0,0);

    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < n ; j ++){
            if(s[i][j] == '\0') cout << ' ';    // NULL 일 경우 처리
            else cout << s[i][j] ;
        } cout << '\n';
    }

    
}

