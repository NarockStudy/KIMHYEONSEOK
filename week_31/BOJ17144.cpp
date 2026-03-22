// [BOJ17144] 미세먼지 안녕! / 골드 4 / 시뮬레이션 / 32 ms / 2044 KB
/*
    문제 입, 출력

    문제 방향
        1. 미세먼지를 인접한 4방향으로 확산
        2.  공기 순환 후 먼지 이동 
        3. t번 반복 먼지 합 구하기

*/

#include <bits/stdc++.h>
using namespace std;

int R, C, T;
int board[51][51];
int tmp[51][51];
vector<int> air;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void solve() {
    // 1. 초기화 
    for (int i = 0; i < R; i++) {
        fill(tmp[i], tmp[i] + C, 0);
    }

    // 2. 확산
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (board[i][j] > 0) {
                int val = board[i][j] / 5;
                int cnt = 0;

                for (int d = 0; d < 4; d++) {
                    int nx = i + dx[d];
                    int ny = j + dy[d];

                    if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
                    if (board[nx][ny] == -1) continue;

                    tmp[nx][ny] += val;
                    cnt++;
                }

                tmp[i][j] += board[i][j] - val * cnt;
            }
        }
    }

    // 공기청정기 유지
    for (int r : air) {
        tmp[r][0] = -1;
    }

    // 3. board로 복사
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            board[i][j] = tmp[i][j];
        }
    }

    int top = air[0];
    int bottom = air[1];

    // 4. 공기청정기 작동

    // 위쪽 (반시계)
    for (int i = top - 1; i > 0; i--) board[i][0] = board[i - 1][0];
    for (int j = 0; j < C - 1; j++) board[0][j] = board[0][j + 1];
    for (int i = 0; i < top; i++) board[i][C - 1] = board[i + 1][C - 1];
    for (int j = C - 1; j > 1; j--) board[top][j] = board[top][j - 1];
    board[top][1] = 0;

    // 아래쪽 (시계)
    for (int i = bottom + 1; i < R - 1; i++) board[i][0] = board[i + 1][0];
    for (int j = 0; j < C - 1; j++) board[R - 1][j] = board[R - 1][j + 1];
    for (int i = R - 1; i > bottom; i--) board[i][C - 1] = board[i - 1][C - 1];
    for (int j = C - 1; j > 1; j--) board[bottom][j] = board[bottom][j - 1];
    board[bottom][1] = 0;
}

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> R >> C >> T;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> board[i][j];
            if (board[i][j] == -1) air.push_back(i);
        }
    }

    while (T--) {
        solve();
    }

    int result = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (board[i][j] > 0) result += board[i][j];
        }
    }

    cout << result << "\n";
    
}