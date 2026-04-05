// [BOJ16236] 아기 상어 / 골드 3 / 시뮬레이션 / 0 ms / 2028 KB
/*
    문제 입, 출력

    문제 방향
        1. 현재 상어 위치에서 BFS를 수행하여 이동 가능한 모든 칸을 탐색
        2. 가까운 거리 우선 -> 가장 위쪽 우선 -> 왼쪽 물고기 선택
        3. 위치 이동 후 상태 갱신
            - 이동 시간, 먹은 개수, 크기 증가
        4. 먹을 물고기 없으면 종료  
*/

#include <bits/stdc++.h>
using namespace std;


int n;
int cnt ;
int ans ;
int sz = 2;

int board[21][21];
bool vis[21][21];

int dr[4] = {-1, 0, 0, 1}; 
int dc[4] = {0, -1, 1, 0};

struct Fish {
    int r, c, dist;
};

bool cmp(Fish a, Fish b) {
    if (a.dist != b.dist) return a.dist < b.dist;
    if (a.r != b.r) return a.r < b.r;
    return a.c < b.c;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int sr, sc;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 9) {
                sr = i;
                sc = j;
                board[i][j] = 0;
            }
        }
    }

     

    while (true) {
        for(int i = 0 ; i < n ; i ++ ) fill(vis[i],vis[i]+n,0);
        // memset(vis, false, sizeof(vis));

        queue<pair<int,int>> q;
        q.push({sr, sc});
        vis[sr][sc] = true;

        vector<Fish> candidates;

        int dist = 0;
        bool found = false;

        while (!q.empty()) {
            int qSize = q.size();

            while (qSize--) {
                int r,c;
                r = q.front().first;
                c = q.front().second;
                // auto [r, c] = q.front(); 
                q.pop();

                // 먹을 수 있는 물고기 발견
                if (board[r][c] > 0 && board[r][c] < sz) {
                    candidates.push_back({r, c, dist});
                    found = true;
                }

                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if (nr < 0 || nc < 0 || nr >= n || nc >= n) continue;
                    if (vis[nr][nc]) continue;
                    if (board[nr][nc] > sz) continue;

                    vis[nr][nc] = true;
                    q.push({nr, nc});
                }
            }

            // 같은 거리까지는 다 탐색하고 멈춤
            if (found) break;
            dist++;
        }

        if (candidates.empty()) break;

        sort(candidates.begin(), candidates.end(), cmp);
        Fish target = candidates[0];

        // 이동 및 상태 갱신
        sr = target.r;
        sc = target.c;
        ans += target.dist;

        board[sr][sc] = 0;
        cnt++;

        if (cnt == sz) {
            sz++;
            cnt = 0;
        }
    }

    cout << ans << "\n";
}