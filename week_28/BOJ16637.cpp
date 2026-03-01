// [BOJ16637] 괄호 추가하기 / 골드 3 / 시뮬레이션 / 0 ms / 2028 KB
/*
    문제 입, 출력

    문제 방향
    - 연산자 인덱스 조합 완전탐색
    - 인접한 인덱스는 선택 불가
    - 선택된 위치 먼저 계산 후 전체 계산
*/

#include<bits/stdc++.h>
using namespace std;

int N;
string s;

vector<int> numbers;
vector<char> ops;

int calc(int a, int b, char op){
    if(op == '+') return a + b;
    if(op == '-') return a - b;
    return a * b;
}

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> s;



    for(int i = 0; i < N; i++){
        if(i % 2 == 0)  numbers.push_back(s[i] - '0');
        else            ops.push_back(s[i]);
    }

    int m = ops.size();
    int answer = INT_MIN;

    // 괄호 개수 k
    for(int k = 0; k <= (m + 1) / 2; k++){

        // 연산자 인덱스 중 k개 선택
        vector<int> comb(m, 0);
        fill(comb.begin(), comb.begin() + k, 1);

        do{
            vector<int> selected;

            for(int i = 0; i < m; i++){
                if(comb[i])
                    selected.push_back(i);
            }

            // 인접 인덱스 검사
            bool valid = true;
            for(int i = 1; i < selected.size(); i++){
                if(selected[i] == selected[i-1] + 1){
                    valid = false;
                    break;
                }
            }

            if(!valid) continue;

            vector<int> temp_nums = numbers;
            vector<char> temp_ops = ops;

            // 괄호 먼저 계산
            for(int idx : selected){
                int res = calc(temp_nums[idx], temp_nums[idx+1], temp_ops[idx]);
                temp_nums[idx] = res;
                temp_nums[idx+1] = 0;
                temp_ops[idx] = '+';
            }

            // 왼쪽부터 계산
            int result = temp_nums[0];

            for(int i = 0; i < m; i++){
                if(find(selected.begin(), selected.end(), i) != selected.end())
                    continue;

                result = calc(result, temp_nums[i+1], temp_ops[i]);
            }

            answer = max(answer, result);

        } while(prev_permutation(comb.begin(), comb.end()));
    }

    cout << answer;
    return 0;
}