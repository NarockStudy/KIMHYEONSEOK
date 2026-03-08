// [BOJ17143] 낚시왕 / 골드 3 / 시뮬레이션 / 968 ms / 2308 KB

/*
    문제 입, 출력
        R C M 
        R: 격자 행 (<= 100) 
        C: 격자 열 (<= 100) 
        M: 상어 수 (<= 10000)



    문제 방향
        1. 낚시왕은 1번 열부터 C번 열까지 이동
        2. 해당 열에서 가장 가까운(행이 가장 작은) 상어를 잡음
        3. 상어 이동
        - 속도만큼 이동
        - 경계를 만나면 방향 반전
        4. 이동 후 같은 칸에 여러 상어가 있으면
        - 크기가 가장 큰 상어만 생존
        5. 위 과정을 모든 열에 대해 반복

*/


    #include<bits/stdc++.h>
    using namespace std;

    struct Shark {
        int r, c;   // 위치
        int s;      // 속도
        int d;      // 방향
        int z;      // 크기
        bool alive; // 생존 여부
    };

    int R, C, M;
    vector<Shark> sharks;

    int board[101][101];

    int dr[5] = {0, -1, 1, 0, 0};
    int dc[5] = {0, 0, 0, 1, -1};

    int ans;

    void move() {

        for (int i = 0; i < 101; i++) fill(board[i], board[i] + 101, -1);

        for (int i = 0; i < sharks.size(); i++) {

            if (!sharks[i].alive) continue;

            int r = sharks[i].r;
            int c = sharks[i].c;
            int d = sharks[i].d;

            for (int step = 0; step < sharks[i].s; step++) {

                int nr = r + dr[d];
                int nc = c + dc[d];

                if (nr < 1 || nr > R || nc < 1 || nc > C) {

                    if (d == 1) d = 2;
                    else if (d == 2) d = 1;
                    else if (d == 3) d = 4;
                    else d = 3;

                    nr = r + dr[d];
                    nc = c + dc[d];
                }

                r = nr;
                c = nc;
            }

            sharks[i].r = r;
            sharks[i].c = c;
            sharks[i].d = d;

            if (board[r][c] == -1) {
                board[r][c] = i;
            } 
            else {
                int other = board[r][c];

                if (sharks[other].z < sharks[i].z) {
                    sharks[other].alive = false;
                    board[r][c] = i;
                } 
                else {
                    sharks[i].alive = false;
                }
            }
        }
    }



    int main(void){
        cin.tie(0);
        ios::sync_with_stdio(0);
        
        cin >> R >> C >> M;

        sharks.resize(M);

        for (int i = 0; i < M; i++) {
            cin >> sharks[i].r >> sharks[i].c >> sharks[i].s >> sharks[i].d >> sharks[i].z;
            sharks[i].alive = true;
        }

        for (int fisher = 1; fisher <= C; fisher++) {

            int target = -1;
            int minRow = 0x3f3f3f3f;

            for (int i = 0; i < sharks.size(); i++) {

                if (!sharks[i].alive) continue;

                if (sharks[i].c == fisher && sharks[i].r < minRow) {
                    minRow = sharks[i].r;
                    target = i;
                }
            }

            if (target != -1) {
                sharks[target].alive = false;
                ans += sharks[target].z;
            }

            move();
        }

            cout << ans << "\n";

        
    }