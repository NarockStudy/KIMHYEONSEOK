// [BOJ7795] 먹을 것인가 먹힐 것인가 / 실버3 / 정렬 II / 28 ms / 2052 KB
/*
    문제 입, 출력

        t       :       ??                  int
        a,b     :       ~20'000             int
        
        arr_a[a],arr_b[b]                   int
        ans     :       ~20'000 * 20'000    int

    문제 방향

        1. arr_a, arr_b 배열 입력받기
        2. arr_a, aar_b 정렬
        3. arr_a 순회하면서 bidx 를 두어 arr_b[bidx] 과 비교하여 arr_a가 크면 bidx 증가 
            매 번 cnt 갱신
        4. O (n + m) 완성 

*/

#include<bits/stdc++.h>
using namespace std;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int t;
    cin >> t;
    while(t--){
        int a,b;
        cin >> a >> b;
        int arr_a[a],arr_b[b];
        for(int i = 0 ; i < a ; i ++ ) cin >> arr_a[i];
        for(int i = 0 ; i < b ; i ++ ) cin >> arr_b[i];

        //  arr_a, aar_b 정렬
        sort(arr_a,arr_a+a);
        sort(arr_b,arr_b+b);

        int bidx = 0;
        int cnt = 0;


        for(int i = 0 ; i < a ; i ++ ){
            //  arr_a 순회하면서 bidx 를 두어 arr_b[bidx] 과 비교하여 arr_a가 크면 bidx 증가 
            while(bidx < b && arr_b[bidx] < arr_a[i]) bidx++;   
            cnt += bidx;        //  cnt 갱신
        }
        
        cout << cnt << '\n';

        // cout <<'\n';
        // for(int i = 0 ; i < a ; i ++ ) cout << arr_a[i] << ' ';
        // cout << '\n';
        // for(int i = 0 ; i < b ; i ++ ) cout << arr_b[i] << ' ';
        // cout << '\n';
    }
    
}

