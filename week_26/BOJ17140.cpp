// [BOJ17140] 이차원 배열과 연산 / 골드 4 / 시뮬레이션 / 0 ms / 2120 KB
/*
    문제 입,출력

    문제 방향
        1. 1-index로 r,c,k가 주어짐.
        2. 100초 동안 arr[r][c] == k 인지 확인
        3. 행의 개수, 열의 개수로 R 연산인지 C 연산 확인
            3-1. 100개가 넘어가지 않고 버리도록 설정.
            3-2. 0은 무시
        4. 배열값들이 100 이하이므로 카운트 소트로 빈도 수 저장 
        5. 수,빈도,수,빈도... 배열만들기 
*/

#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second


const int n = 3;
int arr[110][110];
int narr[110][110];
int r,c,k;
int cur_r = 3;
int cur_c = 3;
int t;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> r >> c >> k;

    for(int i = 0 ; i < n; i ++){
        for(int j = 0 ; j < n ; j ++){
            cin >> arr[i][j];
        }
    }

    int ans = -1;
    while(t <= 100){
        if(arr[r-1][c-1] == k ) {
            ans = t;
            break;
        }

        for(int i = 0 ; i < 110; i ++ ) fill(narr[i],narr[i]+110,0);
        int mx_val = 0;
        if( cur_r >= cur_c) { // R 연산
            for(int i = 0 ; i < cur_r ; i ++){
                int cnt[101] ={0};
                for( int j  = 0 ; j < cur_c; j ++){
                    if(arr[i][j] != 0) cnt[arr[i][j]]++;
                }
                vector<pair<int,int>> v;
                for(int c = 1 ; c <=100 ; c ++){
                    if(cnt[c] == 0 ) continue;
                    v.push_back({cnt[c],c});
                }
                sort(v.begin(),v.end());
                
                int idx = 0;
                for(auto& vv : v) {
                    if(idx >= 100 ) break;
                    narr[i][idx++] = vv.Y;
                    if(idx >= 100 ) break;
                    narr[i][idx++] = vv.X;
                }
                mx_val = max(mx_val, idx);
            }

            cur_c = mx_val;
        } else if( cur_r < cur_c) { // C 연산
            for (int j = 0; j < cur_c; j++) {
                int cnt[101] = {0};
                for( int i  = 0 ; i < cur_r; i++){
                    if(arr[i][j] != 0) cnt[arr[i][j]]++;
                }
                vector<pair<int,int>> v;
                for(int c = 1 ; c <=100 ; c ++){
                    if(cnt[c] == 0 ) continue;
                    v.push_back({cnt[c],c});
                }
                sort(v.begin(),v.end());
                int idx = 0;
                for(auto& vv : v) {
                    if(idx >= 100 ) break;
                    narr[idx++][j] = vv.Y;
                    if(idx >= 100 ) break;
                    narr[idx++][j] = vv.X;
                }
                mx_val = max(mx_val, idx);
            }
            cur_r = mx_val;
        }


        for (int i = 0; i < cur_r; ++i)
            for (int j = 0; j < cur_c; ++j)
                arr[i][j] = narr[i][j];


        t++;
        
    }
    
    cout << ans << '\n';
}
