// [BOJ1700] 멀티탭 스케줄링 / 골드 1 / 그리디 / 0 ms / 2160 KB
/*
    문제 입, 출력
        n,k     :       ~100        int
        
        arr[k+@]                    int
        um                          unordered_map<int,queue<int>>
        us                          unordered_set<int>

    문제 방향
        
        1. 각 전기용품들의 인덱스들 모두 저장 
        2. 플러그 과정
            2-1 이미 꽂혀있으면 통과
            2-2 멀티탭 구멍보다 꽂혀있는 수가 적으면 꽂고 통과
            2-3 멀티탭 구멍에 있는 전기용품들의 인덱스 검사
                2-3-1. 가장 가까이 안쓰이는 전기용품 선택.
                2-3-2. 교체.

        
*/

#include<bits/stdc++.h>
using namespace std;

int arr[101];
unordered_map<int,queue<int>> um;
unordered_set<int> us;

int ans;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);
    

    int n,k;
    cin >> n >> k;
    for(int i = 0 ; i < k ; i ++ ) cin >> arr[i];
    
    // 인덱스 저장
    for(int i = 0 ; i < k; i ++ ) um[arr[i]].push(i);

    for(int i = 0 ; i < k ; i ++){
        int x = arr[i];
        um[x].pop();

        // 이미 꽂힘
        if(us.count(x)) continue;       
        // 구멍 갯수 보다 작을 경우 처리
        if(us.size() < n) {
            us.insert(x);
            continue;
        }

        int v = -1;
        int f = -1;
        for(int p : us){
            if(um[p].empty()){
                v = p;
                break;
            }else{
                int nx = um[p].front();
                if(nx > f){
                    f = nx;
                    v = p;
                }
            }
        }

        us.erase(v);
        us.insert(x);
        ans ++;
        
    }

    cout << ans;
    
}