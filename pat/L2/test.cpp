#include <bits/stdc++.h>
using namespace std;

int main(){
    int n = 5;
    vector<int> a(n); iota(a.begin(), a.end(), 0);
    do{
        for(auto &x : a) cout << x << " "; cout << "\n";
    }while(next_permutation(a.begin(), a.end()));
    return 0;
}