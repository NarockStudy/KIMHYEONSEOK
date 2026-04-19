// [BOJ17070] 파이프 옮기기 1 / 골드 5 / dp / 0 ms / 2024 KB
/*
    문제 입, 출력

    문제 방향
        dp : 위치 정보, 방향을 냄. 초기 상태 dp[1][2][0] = 1; 1,2 끝에 가로로 정의 

        1. 1,1 부터 -> N,N 까지 순차적으로 진행

        2. 벽일 경우 패스

        3. i,j 위치에서 0 : 가로 일때, 오른쪽, 대각선으로 이동
            ex)
                경계확인 j + 1 <= n 
                다음칸 벽인지 확인 board[i][j+1] == 0
            1 : 세로일때, 아래, 대각선으로 이동
            2 : 대각선일때, 오른쪽,아래, 대각선 이동 
        
        4. n,n의 0,1,2 합을 더해 출력



*/

#include <bits/stdc++.h>
using namespace std;

int n;
int board[17][17];
int dp[17][17][3];
int ans;

void right(int i, int j,int d) {
    if (j + 1 <= n && board[i][j+1] == 0)
        dp[i][j+1][0] += dp[i][j][d];
}

void down(int i, int j, int d){
    if (i + 1 <= n && board[i+1][j] == 0)
        dp[i+1][j][1] += dp[i][j][d];

}
void dia(int i,int j, int d){
    if (i + 1 <= n && j + 1 <= n &&
        board[i][j+1] == 0 && board[i+1][j] == 0 && board[i+1][j+1] == 0)
        dp[i+1][j+1][2] += dp[i][j][d];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> board[i][j];
        }
    }

    dp[1][2][0] = 1; // 초기 상태

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {

            // 벽일때
            if (board[i][j] == 1) continue;

            // 가로
            if (dp[i][j][0]) {
                // 오른쪽
                right(i,j,0);
                // 대각선
                dia(i,j,0);
            }

            // 세로
            if (dp[i][j][1]) {
                // 아래
                down(i,j,1);
                // 대각선
                dia(i,j,1);
            }

            // 대각선
            if (dp[i][j][2]) {
                // 오른쪽
                right(i,j,2);
                // 아래
                down(i,j,2);
                // 대각선
                dia(i,j,2);
            }
        }
    }

    ans = dp[n][n][0] + dp[n][n][1] + dp[n][n][2];
    cout << ans  << '\n';
}