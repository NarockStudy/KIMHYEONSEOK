// [BOJ17281] ⚾ / 골드 4 / 시뮬레이션 / 328 ms / 2024 KB

/*
    문제 입,출력

    문제 방향

    1. 1번 선수가 4번 타자 지정하고 나머지 12356789 타자들을 순열로 찾기
        1-1. 4번 인덱스 1로 고정
        1-2. 나머지 123 / 56789 순열 
    2.  한 타순 에서 한 이닝 3 out 까지 계속 진행
    
    3. 
*/

#include<bits/stdc++.h>
using namespace std;

const int HITTER_COUNT = 9;
int n;
int out_count;

int arr[52][12];
vector<int> D(10);
int cur_D = 1;

int ans;
int inning_count(int inning){
    int out_count = 0;
    int score = 0;

    bool ru[5] = {};
    while(out_count != 3){
        // 아웃일 경우 
        if(!arr[inning][D[cur_D]]) out_count ++;
        // 1루타일 경우
        else if(arr[inning][D[cur_D]] == 1){
            // 주자 처리
            for(int r = 3; r >= 1; r --){
                if(!ru[r]) continue;
                ru[r] = false;
                if(r >= 3) score ++;
                else ru[r+1] = true;
            }
            // 타자 처리
            ru[1] = true;
        }
        // 2루타일 경우 
        else if(arr[inning][D[cur_D]] == 2){
            for(int r = 3; r >= 1; r --){
                if(!ru[r]) continue;
                ru[r] = false;
                if(r >= 2) score++;
                else   ru[r+2] = true;
                    
            }

            // 타자 처리
            ru[2] = true;
        }
        // 3루타일 경우 
        else if(arr[inning][D[cur_D]] == 3){
            for(int r = 3; r >= 1; r --){
                if(!ru[r]) continue;
                ru[r] = false;
                if(r >= 1) score++;
                else   ru[r+3] = true;
                    
            }

            // 타자 처리
            ru[3] = true;
        }

        // 홈런일 경우 
        else if(arr[inning][D[cur_D]] == 4){

            // 주자 처리
            for(int r = 3 ; r >= 1; r--) 
                if(ru[r]) score ++;
            fill(ru+1,ru+5,false);

            // 타자 처리
            score ++ ;  
        }

        // 타순 로직 cur_D , cur_D + 1 ... 9일경우 1로 
        cur_D = cur_D  % 9 + 1;
    }

    return score;
}


int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;
    for(int i = 1 ; i <= n ; i ++){
        for(int j = 1 ; j <= HITTER_COUNT; j ++){
            cin >> arr[i][j];
        }
    }


    // 타순 정하기 (4번타자 1번선수로 고정)
    // for(int i = 1; i <= 9; i ++ ) {
    //         if(i == 1) D[i] = 4;
    //         else if(i <= 4) D[i] = i - 1;
    //         else  D[i] = i;            
    // }
    for(int i = 1 ; i <=9 ; i ++ ) D[i] = i ;
    // for(int i = 1 ; i <=9 ; i ++ ) cout << D[i] << ' ';
    // cout << '\n';
    do{
        if(D[4] != 1) continue;
        int tot = 0 ;
        cur_D = 1;
        for(int i = 1 ; i <= n ; i ++){
            int inning_score = inning_count(i);
            tot += inning_score;
        }
        ans = max(ans,tot);


    } while(next_permutation(D.begin()+1,D.end()));
    // D.begin() == 0 , +1 == 1 , +2 == 2 


    cout << ans << '\n';



    
    
}