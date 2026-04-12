// [BOJ17406] 배열 돌리기 4 / 골드 4 / 시뮬레이션 / 0 ms / 2028 KB
/*
    문제 입, 출력

    문제 방향
        1. 순열을 이용하여 완전탐색
        2. 회전연산 적용
        3. 모든 경우 최소 행 합 구하기 

*/

#include <bits/stdc++.h>
using namespace std;

int N, M, K;
int A[51][51];
vector<tuple<int,int,int>> ops;
int ans = 0x3f3f3f3f;

void rotate_array(int arr[51][51], int r, int c, int s) {
    for (int layer = 1; layer <= s; layer++) {
        int top = r - layer;
        int left = c - layer;
        int bot = r + layer;
        int right = c + layer;

        int temp = arr[top][left];

        // 왼쪽 → 위
        for (int i = top; i < bot; i++)
            arr[i][left] = arr[i+1][left];

        // 아래 → 왼쪽
        for (int i = left; i < right; i++)
            arr[bot][i] = arr[bot][i+1];

        // 오른쪽 → 아래
        for (int i = bot; i > top; i--)
            arr[i][right] = arr[i-1][right];

        // 위 → 오른쪽
        for (int i = right; i > left+1; i--)
            arr[top][i] = arr[top][i-1];

        arr[top][left+1] = temp;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> A[i][j];

    for (int i = 0; i < K; i++) {
        int r, c, s;
        cin >> r >> c >> s;
        ops.push_back({r, c, s});
    }


    vector<int> vec(K);
    for (int i = 0; i < K; i++) vec[i] = i;

    do {
        int temp[51][51];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                temp[i][j] = A[i][j];
            }
        }

        for (int i = 0; i < K; i++) {
            int r,c,s;
            tie(r,c,s)  = ops[vec[i]];
            // 2. 회전연산 적용
            rotate_array(temp, r-1, c-1, s);
        }

        // 3. 모든 경우 최소 행 합 구하기 
        for (int i = 0; i < N; i++) {
            int row_sum = 0;
            for (int j = 0; j < M; j++) {
                row_sum += temp[i][j];
            }
            ans = min(ans, row_sum);
        }

    } while (next_permutation(vec.begin(), vec.end()));

    

    cout << ans << "\n";
}