#include<bits/stdc++.h>
using namespace std;
const int N = 110, INF = 0x3f3f3f3f;
int n, m;
int d[N][N];

int main() {
    int n = 291;
    vector<int> vec;
    while(n){
        vec.push_back(n%16); n/=16;
    }
    reverse(vec.begin(),vec.end());
    for(auto &x : vec) cout << x << " ";
    return 0;
}