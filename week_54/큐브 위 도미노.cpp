// [Codetree] 큐브 위 도미노 / L9 / Mathematics / 2 ms / 0 MB
/*
    Main Logic
        
        step 1 : 모든 경우의 수는 2 ^ 6  = 64;
            
        step 2 : 꼭지점 과 선 (꼭지점 제외한 가운데만)  계산
            n이 짝수,홀수에 따라 꼭지점 색상 달라짐. 
            

            x,y,z 축으로 하여, [0,n-1] 로 매핑

            꼭지점 8 개 조사
                3개 면의 꼭지점을 조사
                    x 평면 결정 후, y,z 축으로 몇 칸 +  나머지 연산을 통해 색 판정
                    y 평면 결정 후, x,z 축으로 몇 칸 +  나머지 연산을 통해 색 판정
                    z 평면 결정 후, y,z 축으로 몇 칸 +  나머지 연산을 통해 색 판정
                    
                    3개중 2개가 black(1) 이면 +1
            선 12개 조사
                z축 제외 x,y 축으로만 이루어진 테두리 4개 조사
                    x 평면에서 y축으로 몇 칸 + 나머지 연산을 통해 색 판정
                    y 평면에서 x축으로 몇 칸 + 나머지 연산을 통해 색 판정
                    색이 같으면 블랙이 있을 수 있음. 색이 다르면, 없음.
                        0 과 n-1 제외하고, n-2 칸에서 
                            짝수, (n-2) / 2 이다. 
                                ex) n = 6 , 4칸(6-2) 흑백흑백 or  백흑백흑 = 2개
                            홀수, (n-2) / 2 + 1(맨 앞이 백이면)
                                ex) n = 7, 5칸 맨앞이 흑일 경우, 백흑백흑백 = 2개, 백일 경우, 흑백흑백흑 = 3개
                        
        step 3 : bb 의 수와 ww 의 최댓값은 같다. 색 반전 하면 동일하기 때문.
                bw 는 모두 다른 경우의 수를 생각해서 전부인, 6 * n^2 / 2 개 
        
        

*/

#include<bits/stdc++.h>
using namespace std;

const int TOT = 64;

int n;
int n_side;
long long mx_bb,mx_wb;


int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);
    

    cin >> n;

    // 테두리 선 가운데 길이
    n_side = n - 2;
    // cout << n_side << '\n';

    // 0 : 위 , 1 : 아래, 
    // 2 : 앞,  3 : 뒤 
    // 4, 왼쪽, 5: 오른쪽
    for(int i = 0 ; i < TOT; i ++){

        // 0 : 최좌측 흑, 
        // 1 : 최좌측 백
        int states[6] = {};
        int brute = i;
        for(int idx = 0 ; idx < 6 ; idx++){
            states[idx] = brute% 2;  
            brute/= 2;
        }

        // 꼭지점 
        long long cur_bb = 0;

        int ends[2] = {0,n-1};
        for(int x : ends){
            for(int y : ends){
                for(int z : ends){
                    int f_x,f_y,f_z;
                    int c_x,c_y,c_z;
                    f_x = (x == 0) ? 0 : 1; // 위 아래
                    f_y = (y == 0) ? 2 : 3; // 앞 뒤 
                    f_z = (z == 0) ? 4 : 5; // 왼 오른

                    c_x = (states[f_x] + y + z) % 2;
                    c_y = (states[f_y] + x + z) % 2;
                    c_z = (states[f_z] + x + y) % 2;
                    
                    int cnt = c_x + c_y + c_z;
                    if(cnt >= 2) cur_bb++;
                }
            }
        }

        // 테두리 

        for(int x : ends){
            for(int y : ends){
                int f_x = (x == 0) ? 0 : 1;
                int f_y = (y == 0) ? 2 : 3;
                
                int p_x = (states[f_x] + y) % 2;
                int p_y = (states[f_y] + x) % 2;
                
                if(p_x == p_y){
                    cur_bb += ((n-2)/2);
                    if(n% 2 !=0 && p_x == 0){
                        cur_bb++;
                    }
                    // if(n % 2 == 0)  cur_bb += ((n-2)/2);
                    // else{
                    //     cur_bb += ((n-2)/2);
                    //     if(p_x == 0){ // 흑이면
                    //         cur_bb ++;
                    //     }    
                    // }
                }

            }
        }

        for(int x : ends){
            for(int z : ends){
                int f_x = (x == 0) ? 0 : 1;
                int f_z = (z == 0) ? 4 : 5;
                
                int p_x = (states[f_x] + z) % 2;
                int p_z = (states[f_z] + x) % 2;

                if(p_x == p_z){
                    cur_bb += ((n-2)/2);
                    if(n% 2 !=0 && p_x == 0){
                        cur_bb++;
                    }
                }
            }
        }
        for(int y : ends){
            for(int z : ends){
                int f_y = (y == 0) ? 2 : 3;
                int f_z = (z == 0) ? 4 : 5;

                int p_y = (states[f_y] + z) % 2;
                int p_z = (states[f_z] + y) % 2;

                if(p_y == p_z){
                    cur_bb += ((n-2)/2);
                    if(n% 2 !=0 && p_y == 0){
                        cur_bb++;
                    }
                }
            }
        }
        

        mx_bb = max(mx_bb, cur_bb);
    }



    // wb 는 6 * n^2  / 2  전체가 체스판 처럼 되면 가능 
    mx_wb = 1LL * n * n * 6 / 2 ;

    cout << mx_bb << ' ' << mx_bb << ' ' << mx_wb << '\n';

    


}