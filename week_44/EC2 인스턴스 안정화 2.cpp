// 	[Codetree] EC2 인스턴스 안정화 2 / L10 / Preprocessing / 2 ms / 0 MB
/*
    Main Logic
        1. n에 대한 normal 모드와 brust 모드의 차이를 미리 저장
            1.1. i == 1, i==n 일때, 예외 처리 
        2. 인접한 경우와 인접하지 않는 경우 나눔.
            2.1. 인접한 경우, i == 1, i+1 == n 예외 처리 
            2.2. 인접하지 않는 경우, 
                j 에서, i가 될 수 있는 범위 (j -2, j-3,... ) 중 가장 큰 차이는 prev_mx 에 저장 
        

                
*/

#include<bits/stdc++.h>
using namespace std;

int n;
int arr[5'010];
int diff[5'010];

int init_ans;
int diff_mx;
int ans;


void solve_On2();


int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> n;
    for(int i = 1; i <=n ; i++ ) cin >> arr[i];
    for(int i = 1; i < n ; i ++ ) init_ans += abs(arr[i] - arr[i+1]);

    for(int i = 1 ; i <=n; i++){
        int b = 0 , a=0;
        
        if(i > 1){
            b += abs(arr[i-1] - arr[i]);
            a += abs(arr[i-1] - arr[i] * 2);
        }
        if(i < n){
            b += abs(arr[i] - arr[i+1]);
            a += abs(arr[i]*2 - arr[i+1]);
        }
        diff[i] = a- b;
    }

    // 인접한 경우 i+1 == j
    for(int i = 1 ; i <n ; i++){
        int a = 0, b = 0;
        
        b = abs(arr[i] - arr[i+1]);
        a = abs(arr[i]*2 - arr[i+1]*2);

        if(i > 1){
            b += abs(arr[i-1] - arr[i]);
            a += abs(arr[i-1] - arr[i]*2);
        }
        if(i + 1 < n){
            b += abs(arr[i+1] - arr[i+2]);
            a += abs(arr[i+1]*2 - arr[i+2]);
        }

        diff_mx = max(diff_mx,a - b );
    }

    // 인접하지  않는 경우 최소 3 부터
    int prev_mx = diff[1];
    for(int j = 3; j <=n; j++){
        
        diff_mx = max(diff_mx, prev_mx + diff[j]);
        prev_mx = max(prev_mx, diff[j-1]);
    }

    
    cout << init_ans + diff_mx;

    // solve_On2();
    
}

void solve_On2(){

    cin >> n;
    for(int i = 1; i <=n ; i++ ) cin >> arr[i];
    for(int i = 1; i < n ; i ++ ) init_ans += abs(arr[i] - arr[i+1]);

    for(int i = 1 ; i <= n ; i++){
        for(int j = i +1 ; j <=n; j ++){
            int tmp_ans = init_ans;
            if(i+1 == j){
                if(i == 1){
                    tmp_ans -= abs(arr[i] - arr[i+1]);
                    tmp_ans -= abs(arr[j] - arr[j+1]);
                    
                    tmp_ans += abs(arr[i]* 2 - arr[i+1] *2);
                    tmp_ans += abs(arr[j]* 2 - arr[j+1]);
                } else if(j == n) {
                    tmp_ans -= abs(arr[i-1] - arr[i]);
                    tmp_ans -= abs(arr[i] - arr[j]);

                    tmp_ans += abs(arr[i-1] - arr[i] * 2);
                    tmp_ans += abs(arr[i]* 2 - arr[j] *2);

                } else{

                    tmp_ans -= abs(arr[i-1] - arr[i]);
                    tmp_ans -= abs(arr[i] - arr[i+1]);
                    tmp_ans -= abs(arr[j] - arr[j+1]);

                    tmp_ans += abs(arr[i-1] - arr[i] * 2) ;
                    tmp_ans += abs(arr[i]*2 - arr[i+1]*2);
                    tmp_ans += abs(arr[j]*2 - arr[j+1]);
                }
                
            } else{
                if(i == 1){
                    tmp_ans -= abs(arr[i] - arr[i+1]);
                    // tmp_ans -= abs(arr[j-1] - arr[j]);
                    // tmp_ans -= abs(arr[j] - arr[j+1]);

                    tmp_ans += abs(arr[i]* 2 - arr[i+1]);
                    // tmp_ans += abs(arr[j-1] - arr[j] * 2);
                    // tmp_ans += abs(arr[j] * 2 - arr[j+1]);
                }  else{
                    tmp_ans -= abs(arr[i-1] - arr[i]);
                    tmp_ans -= abs(arr[i] - arr[i+1]);
            
                    tmp_ans += abs(arr[i-1] - arr[i] * 2);
                    tmp_ans += abs(arr[i] * 2 - arr[i+1]);
                }
                if(j == n){
                    // tmp_ans -= abs(arr[i-1] - arr[i]);
                    // tmp_ans -= abs(arr[i] - arr[i+1]);
                    tmp_ans -= abs(arr[j-1] - arr[j]);

                    // tmp_ans += abs(arr[i-1] - arr[i] * 2);
                    // tmp_ans += abs(arr[i] * 2 - arr[i+1]);
                    tmp_ans += abs(arr[j-1] - arr[j] *2);

                } 
                else{
                    tmp_ans -= abs(arr[j-1] - arr[j]);
                    tmp_ans -= abs(arr[j] - arr[j+1]);

                    tmp_ans += abs(arr[j-1] - arr[j] * 2);
                    tmp_ans += abs(arr[j]*2 - arr[j+1]);

                }
                    

            }

            ans = max(tmp_ans,ans);
        }
    }
    if(n == 2) ans = 2*init_ans;
    cout << ans; 


}