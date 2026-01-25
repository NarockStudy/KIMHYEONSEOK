// [BOJ16235] 나무 재테크 / 골드 3 / 시뮬레이션 / 144 ms / 2608 KB

/*
    문제 입, 출력
        n : A배열의 크기
        m : 나무의 정보의 양
        k : 주어진 년수 
        A[] : 겨울에 추가되는 양분의 양
        arr[] : 양분의 배열
    문제 방향

*/

#include<bits/stdc++.h>
using namespace std;

int n,m,k;

vector<int> trees[12][12];
vector<int> dead[12][12];
int A[12][12];
int arr[111][111];


int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1, 0, 1,-1,1,-1,0,1};


int ans;

void debug_print(int a[][12], int b[][111],vector<int> c[][12],vector<int> d[][12]){
    // cout << "[DEBUG] A 배열\n";
    // for (int i = 1; i <= n; ++i) {
    //     for (int j = 1; j <= n; ++j) {
    //         cout << a[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';

    cout << "[DEBUG] arr 배열\n";
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << b[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';

    cout << "[DEBUG] 나무 배열\n";
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if(c[i][j].empty()) continue;
            for(auto tree : c[i][j]) cout << i << ' ' << j << ' ' << tree <<'\n';
        }
    }
    cout << '\n';
    cout << "[DEBUG] 죽은 나무 배열\n";
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if(d[i][j].empty()) continue;
            for(auto de : d[i][j]) cout << i << ' ' << j << ' ' << de <<'\n';
        }
    }
    cout << '\n';
}


int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> n >> m >> k;

    // 초기 양분량 저장
    for(int i = 1; i <=n ; i ++) fill(arr[i],arr[i]+n+1,5);



    // 추가 양분량 배열에 저장
    for (int i = 1 ; i <= n; i ++){
        for(int j = 1 ; j <=n ; j ++){
            cin >> A[i][j];
        }
    }



    // 초기 나무의 정보 저장 
    for(int cnt = 1; cnt <= m; cnt ++){
        int x,y,z;
        cin >> x >> y >> z;
        trees[x][y].push_back(z);
    }
    
    // debug_print(A, arr,trees,dead);      // test 완료

    for(int t = 1 ; t <= k; t++){

        // cout << "[DEBUG] k : " << t << "\n";

        // 봄
        // 나무가 자신의 나이 만큼 양분을 먹고 나이 +1 
        // 나이가 어린 나무부터 양분을 먹는다.
        // 자신의 나이만큼 양분을 먹을 수 없으면 나무는 죽는다.
        for(int i = 1 ; i <=n ; i ++ ){
            for(int j = 1 ; j <= n; j ++){
                if(trees[i][j].empty()) continue;
                sort(trees[i][j].begin(),trees[i][j].end());
                for (auto it = trees[i][j].begin(); it != trees[i][j].end(); ) {

                    if (arr[i][j] >= *it) {
                        arr[i][j] -= *it;
                        (*it)++;          // 나이 증가
                        ++it;
                    } else {
                        dead[i][j].push_back(*it);
                        it = trees[i][j].erase(it); // 삭제 + 다음 iterator 반환
                    }
                }
            }
        }

        // 여름
        // 봄에 죽은 나무가 양분으로 변함
        // 죽은 나무는 나이 / 2 만큼 해당 칸에 양분으로 변함
        for(int i = 1 ; i <=n ; i ++ ){
            for(int j = 1 ; j <= n; j ++){
                if(dead[i][j].empty()) continue;
                while(!dead[i][j].empty()){
                    arr[i][j] += dead[i][j].back() / 2;
                    dead[i][j].pop_back();
                }
            }
        }
        
        // 가을
        // 나무 번식 시즌, 번식하는 나무는 나이가 5의 배수여야 함
        // 인접한 8개의 칸에 나무 1인 나무가 생김.
        for(int i = 1 ; i <=n ; i ++ ){
            for(int j = 1 ; j <= n; j ++){
                if(trees[i][j].empty()) continue;
                for(auto& tree : trees[i][j]){
                    if(tree % 5 != 0) continue;

                    for(int dir = 0; dir <8; dir++){
                        int nx = i + dx[dir];
                        int ny = j + dy[dir];
                        if(nx <= 0 || ny <= 0 || nx > n || ny > n) continue;
                        trees[nx][ny].push_back(1);
                    }
                }

            }
        }

        // 겨울
        // A 배열만큼의 양분 추가.
        for(int i = 1 ; i <=n ; i ++ ){
            for(int j = 1 ; j <= n; j ++){
                arr[i][j] += A[i][j];
            }
        }        



        // debug_print(A, arr,trees,dead);
    }


    // 살아남은 나무 찾기
    for(int i = 1 ; i <=n ; i ++ ){
        for(int j = 1 ; j <= n; j ++){
            ans += trees[i][j].size();

        }
    }

    cout << ans;


    
}