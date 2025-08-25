// [BOJ5430] AC / 골드5 / 덱 / 28 ms / 3076 KB

/*
    문제 입출력
        - T : ~100      int 
        - p : ~100'000  string
        - n : ~100'000  int
        - fn : ~100     

        - ans : string 
        
    문제 방향
        1. R, D 함수 구현
            뒤집기, 버리기가 있으므로, deque이 적합.
                진짜 뒤집기 보다는 1, -1 로 체크해놓고 버리거나 출력할때, 이용하는게 효율적.
        2. 배열 문자열 파싱함수 만들기
            문자열 -> int 형으로 만들어서 deque에 넣자.

*/

#include<bits/stdc++.h>
using namespace std;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--){
        string s,fn;
        string ans;
        int n;

        int is_rev = 1; // default 순방향(앞)  , -1 역방향 (뒤)
        bool is_error = false;
        cin >> s >> n >> fn;

        deque<int> dq;

        /* ==================배열 문자열 파싱==========================*/
        int tmp = 0;
        for(int i = 0 ; i < fn.size(); i ++){
            if(fn[i] == '[' || fn[i] == ']') continue;
            if(fn[i] == ','){
                dq.push_back(tmp);
                tmp = 0;
            } else tmp = tmp * 10 + (fn[i] -'0') ;
            
        }
        if(tmp != 0 ) dq.push_back(tmp);
        /* ==================배열 문자열 파싱==========================*/

        /* ==================R, D 함수 구현==========================*/

        for(int i = 0 ; i < s.size(); i ++){
            if ( s[i] == 'R'){
                is_rev *= -1;               // 표시만 해놓기 
            } else if (s[i] == 'D'){
                if(dq.empty()){
                     is_error = true;
                     break;
                }
                else{
                    if(is_rev == 1)dq.pop_front();      
                    else dq.pop_back();             // 표시 확인 후 뒤집은 척하고 뒤쪽에서 빼버리기
                }
            }
        }
        /* ==================R, D 함수 구현==========================*/

        if(is_error) cout << "error\n";
        else {
            // cout << dq.size();
            cout << '[';
            if(is_rev == 1) {
                for(int i = 0 ; i < dq.size(); i ++){
                    cout << dq[i] ;
                    if(i != dq.size() - 1) cout << ',';
                }
            } else{
                for(int i = dq.size() - 1; i >= 0 ; i --){
                    cout << dq[i];
                    if(i != 0 ) cout << ',';
                }
            }
            cout << ']';
            cout << "\n";
        }
    } 
}