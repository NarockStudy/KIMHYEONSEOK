// [BOJ16234] 인구 이동 / 골드 4 / 시뮬레이션 / 444 ms / 2172 KB
/*
    문제 입, 출력

    문제 방향
        1. 모든 칸 bfs 탐색, 연합찾음.
        
        2. 연합은 동서남북으로 인구 차이가 범위안에 있으면 연결
        3. 인구 계산

        4. 크기 >= 2이면, 재분배 
        5. 이동이 더 이상 없으면 종료, 총 일 수 출력 

*/

#include <bits/stdc++.h>
using namespace std;

int N, L, R;
int A[51][51];        
bool vis[51][51]; 

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> L >> R;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> A[i][j];

    int days = 0;

    while (true) {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                vis[i][j] = false;
        bool moved = false;   // 오늘 하루 동안 이동이 있었는지 여부

        // 모든 칸 bfs 탐색, 연합찾음.
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {

                // 방문하지 않은 칸이면 BFS로 연합 찾기
                if (!vis[i][j]) {
                    queue<pair<int, int>> q;
                    vector<pair<int, int>> cells; // 연합에 속한 칸들

                    q.push({ i, j });
                    cells.push_back({ i, j });
                    vis[i][j] = true;

                    int sum = A[i][j]; // 연합 전체 인구 합

                    // BFS 시작
                    while (!q.empty()) {
                        int y, x;
                        tie(y, x) = q.front();
                        q.pop();

                        for (int d = 0; d < 4; d++) {
                            int ny = y + dy[d];
                            int nx = x + dx[d];

                            // 범위 체크
                            if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
                            if (vis[ny][nx]) continue;

                            // 인구 계산
                            int diff = abs(A[y][x] - A[ny][nx]);
                            if (diff >= L && diff <= R) {
                                vis[ny][nx] = true;
                                q.push({ ny, nx });
                                cells.push_back({ ny, nx });
                                sum += A[ny][nx];
                            }
                        }
                    }

                    //  크기 >= 2이면, 재분배 
                    if (cells.size() > 1) {
                        moved = true;
                        int newPop = sum / cells.size();
                        for (auto& p : cells)
                            A[p.first][p.second] = newPop;
                    }
                }
            }
        }

        //  이동이 더 이상 없으면 종료
        if (!moved) break;
        days++;
    }

    cout << days << "\n";
    return 0;
}