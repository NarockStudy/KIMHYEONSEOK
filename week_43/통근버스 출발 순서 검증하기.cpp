// 	[Codetree] 통근버스 출발 순서 검증하기 / L10 / Bruteforce / 3 ms / 0 MB
/*
    Main Logic

        0. 5000 C 3 구해서 stack 에 넣어보는 것은 == 104'041'712'495'000 번이므로 
            어림없는 볼
        0.1 1초 n = 5000 이므로, n2lgn 이하 으로 해결해야됨.


        1. i < j < k 일때 ai < aj이고 ai > ak 이므로 == ak < ai < aj 인걸 찾아야됨.

        2. n^2 풀이 

            k 후보 찾기
                뒤에서부터 순회하여 ak < ai 일때, k 이므로 cnt++
                ak > ai 일때, j 후보이므로 ans += cnt

        
*/

#include<bits/stdc++.h>
using namespace std;

int n;
int arr[5'100];
int ans ;



void solve_n3();
void solve_n3_2();

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);

    

    cin >> n ;
    for(int i = 1; i <= n ; i++) cin >> arr[i];



    for(int i = 1 ; i <=n; i++){
        int cnt = 0;

        for(int k = n; k >= i+1; k--){
            if(arr[i] > arr[k]) cnt++;
            else {
                ans +=cnt;
            }
            // cout << i << ' ' << j << '\n';
        }

    }




    cout << ans;

    // solve_n3();
    // solve_n3_2();
}


void solve_n3(){

    int n;
    int arr[5'100] = {};
    int ans =0 ;

    cin >> n;
    for(int i = 0 ; i < n ; i ++ ) cin >> arr[i];


    
    // N^3 == 5000 5000 5000 ==  125 000 000 000 

    for(int i = 0; i < n; i ++){
        for(int j = i+1; j <n ; j++){
            for(int k = j+1; k <n ; k++){
                if(arr[i] < arr[j] && arr[k] < arr[i] )  ans ++;
            }
        }
    }
    cout << ans;

}

void solve_n3_2(){

    int n;
    int arr[5'100] = {};

    vector<int> right_big_idx [5'100];
    vector<int>  right_small_idx [5'100];
    int ans  = 0;


    cin >> n ;
    for(int i = 1; i <= n ; i++) cin >> arr[i];

    for(int i = 1 ; i <=n; i++){
        for(int j = i+1 ; j <=n ; j++){
            if(arr[i] < arr[j]) right_big_idx[i].push_back(j);
            if(arr[i] > arr[j]) right_small_idx[i].push_back(j);
        }
    }
    // i < j < k 는 보장
    // a[i] < a[j] 보장
    // a[j] > a[k] 보장 
    for(int i = 1 ; i <=n; i++){

        // j : 오른쪽 큰 원소 
        for(auto j : right_big_idx[i]) {
            // k 
            for(auto k : right_small_idx[j] ){
                if(arr[i] < arr[k]) continue;
                // ans += right_small_idx[k].size();
                ans++;
            }
        }
    }

    cout << ans;
}

