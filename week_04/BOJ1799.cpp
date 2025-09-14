// [BOJ1799] 비숍 / 플레티넘 4 / 백트래킹 / 64 ms / 2020 KB
/*
    문제 입, 출력
        n           :       ~10                 int
        board[n+2][n+@]                         int
        chk1[2*n+@]                             int
        chk2[2*n+@]                             int
        
        ans[2]                                  in5W
        
    문제 방향
        검은색, 흰색 불가침 조약임. 

        대각선 확인 <== N-Queen 아이디어

        백트래킹을 통해 모든 경우의수 순회.

*/

#include<bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

int n;
int board[11][11];
bool chk1[30]; // x+y 대각선
bool chk2[30]; // x-y+n-1 대각선
int ans[2];    // 흑/백 칸 각각 최대 비숍 수

void dfs(int idx, int cnt, int color) {
    if (idx >= n * n) {
        ans[color] = max(ans[color], cnt);
        return;
    }

    int x = idx / n;
    int y = idx % n;

    // 다음 칸 탐색
    dfs(idx + 1, cnt, color);

    // 현재 칸에 비숍 놓기 가능 여부 확인
    if (board[x][y] && (x + y) % 2 == color && !chk1[x + y] && !chk2[x - y + n - 1]) {
        chk1[x + y] = chk2[x - y + n - 1] = true;
        dfs(idx + 1, cnt + 1, color);
        chk1[x + y] = chk2[x - y + n - 1] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];

    dfs(0, 0, 0); // 검은 칸
    dfs(0, 0, 1); // 흰 칸

    cout << ans[0] + ans[1] << '\n';
}
