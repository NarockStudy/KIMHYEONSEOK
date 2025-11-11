// [BOJ11650] 좌표 정렬하기 / 실버 5 / 정렬 I / 40 ms / 2800 KB
/*
    문제 입,출력

    문제 방향

        1. 처음에 비교 람다함수를 만들어서 작성하려고 했으나, 사실 기본 sort 성질을 이용하면 됨.


*/

#include<bits/stdc++.h>
using namespace std;

#define X first 
#define Y second

int n;
pair<int,int> arr[100'001];
int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;
    for(int i = 0 ; i < n ; i ++ ) cin >> arr[i].X >> arr[i].Y;

    // sort(arr,arr+n,[](const pair<int,int>&a, const pair<int,int> b){
    //     if(a.X != b.X) return a.X < b.X;
    //     return a.Y < b.Y;
    // });
    sort(arr,arr+n);


    for(int i = 0 ; i < n ; i ++ ) cout << arr[i].X << ' ' <<arr[i].Y << '\n';
    
}
