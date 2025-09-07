// [BOJ14002] 가장 긴 증가하는 부분 수열 4 / 골드 4 / DP / 0 ms / 2032 KB

/*
    문제 입,출력
        n :             ~1'000          int

        d[n+@] :                        int
        s[n+@] :                        int

        pre[n+@]:                       int
    문제 방향

        테이블 정의
            d[i] :  i번째 원소가 증가하는 부분 수열의 몇 번째 원소 인 수
        점화식 정의
            d[i] = max(d[i], d[j]+1);
        초기식 정의
            d[i] = 1 (i = 1 ~ n)

        
        pre 초기값은 최댓값일때 인덱스에서 시작함.
        pre 를 이용하여 이전인덱스를 가져와서  역추적 가능.
        pre[1] = 0 이므로 cur == 0 일때 종료됨.
        */

#include<bits/stdc++.h>
using namespace std;

int n;
int s[1'002],d[1'002],pre[1'002];

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);


    cin >> n ;

    for(int i = 1; i <=n ; i ++) cin >> s[i];
    
    fill(d+1,d+n+1,1);      // 초기식 정의
    for(int i = 2 ; i <= n ; i++){
        for(int j = 1 ; j < i ; j ++){
            if(s[j] < s[i]) {   //   증가 수열일 경우 
                
                if(d[i] < d[j]+1) {     // 증가 수열의 길이 갱신 여부 
                    d[i] = d[j]+1;
                    pre[i] =j;          // 증가 수열 + 길이 갱신 될 때 pre 저아

                }
            }
        }
    }

    // 최대값 STL 한줄 딸깍
    int ans = *max_element(d+1,d+n+1);      
    cout << ans << '\n';

    // 최대값 iterator 찾기
    auto it = max_element(d+1,d+n+1);       
    int cur = distance(d,it);               


    vector<int> pre_ans ;
    while(cur != 0 ){
        pre_ans.push_back(s[cur]);
        cur = pre[cur];
    }

    for(auto it =pre_ans.rbegin(); it != pre_ans.rend(); it++)  //거꾸로 출력하기
        cout << *it << ' ';
}
