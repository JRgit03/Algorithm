#include <bits/stdc++.h>
using namespace std;

bool check(int x){ // O(sqrt(n))
    if(x < 2) return false;
    for(int i=2;i<=x/i;i++)
        if(x % i == 0) 
            return false;
    return true;
}

// 

int main(){
    int n,k; cin>>n>>k;
    string s; cin>>s;
    for(int i=0;i+k-1<n;i++){ // O(n * sqrt(x)) 1000 * sqrt(999-999-999) => 1e7 
        string str = s.substr(i,k);
        int x = stoi(str);
        if(check(x)){
            cout << str << "\n"; // str 可能有前导0
            return 0;
        }
    }
    cout << 404 << "\n";
    return 0;
}
