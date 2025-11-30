// [BOJ13335] 트럭 / 실버 1 / 시뮬레이션 / 0 ms / 2024 KB
/*
    문제 입, 출력

    문제 방향
        1. queue 를 이용해서 풀이

        2. 큐는  다리 위의 트럭 무게

        3. 초기 다리 길이만큼 0으로 채움
        
        4. 다음 트럭을 올릴 수 있는지 체크
        5. 올릴 수 있으면 트럭 올림
        6. 무게 초과 하면 0을 올려서 한 칸 전진만 함


*/

#include <bits/stdc++.h>
using namespace std;

int n, w, L;
int arr[1001];
queue<int> bridge; 

int currentWeight;
int t;
int idx;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> w >> L;

    
    for (int i = 0; i < n; i++) cin >> arr[i];



    // 초기 다리 길이만큼 0으로 채움
    for (int i = 0; i < w; i++) bridge.push(0);

    while (!bridge.empty()) {
        t++;
        currentWeight -= bridge.front();
        bridge.pop();

        // 다음 트럭을 올릴 수 있는지 체크
        if (idx < n) {
            if (currentWeight + arr[idx] <= L) {
                // 올릴 수 있으면 트럭 올림
                bridge.push(arr[idx]);
                currentWeight += arr[idx];
                idx++;
            } else {
                // 무게 초과 하면 0을 올려서 한 칸 전진만 함
                bridge.push(0);
            }
        }
    }

    cout << t << "\n";
    return 0;
}
