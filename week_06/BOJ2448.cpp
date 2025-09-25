// [BOJ2448] 별 찍기 - 11 / 골드 4 / 재귀 / 412 ms / 20456 KB

/*
    문제 입, 출력
        n   :          ~3 * 1024            int
        
        board[n+@][n*2+@]                   char


    문제 방향

        base condition :
            k == 3 일때, 기본 모형 6 x 6 디자인

        
        전체 행은 n 이되고 열은 n * 2 가 된다.
        따라서 기준점은 0, n-1 으로 시작
            기준점에 따라 6 x 6  시작점은 0,k 이므로 
                (0,k-2)  ~ (0,k+2)
                (1,k-2)  ~ (1,k+2)
                (2,k-2)  ~ (2,k+2)
        
        
        기준점을 고려하여
            재귀적으로 k/2 아래 행 
                1. - k/2 열
                2. + k/2 열 

    
        그 전에는 기준점을

*/

#include<bits/stdc++.h>
using namespace std;

const int MX = 3 * 1024 ;

char board[MX][MX*2+1];

void solve(int k,int x , int y){

    /*base condition*/
    if(k == 3 ) {
        board[x][y] = '*';

        board[x+1][y-1] = '*';
        board[x+1][y+1] = '*';

        board[x+2][y-2] = '*';
        board[x+2][y-1] = '*';
        board[x+2][y] = '*';
        board[x+2][y+1] = '*';
        board[x+2][y+2] = '*';
        return;
    }


    int idx = k/2;


    solve(idx, x, y );
    solve(idx, x + idx, y - idx);   // - k/2 열
    solve(idx, x + idx, y + idx);   // + k/2 열
    

}


int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);
    

    int n;
    cin >> n ;

    solve(n,0,n-1);       // 기준점 0,n 으로 시작 

    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < n * 2 - 1; j ++){
            if(board[i][j] == '\0') cout << ' ';
            else cout << board[i][j];
        } cout << '\n';
    }
}

