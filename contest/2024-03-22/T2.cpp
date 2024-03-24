#include <bits/stdc++.h>
#define int long long
using namespace std;

int k;
int n;
string a,b;

void solve(){
    cin>>k>>a>>b;
    n = a.length();
    vector<int> num1(n), num2(n), num3(n);
    for(int i=0;i<n;i++) {
        num1[i] = a[i] - '0';
        num2[i] = b[i] - '0';
    }
    int op = 0;
    int i = 0;
    for(;i<n && op<k;i++){
        if(num1[i] != num2[i]){
            op += 1;
            num3[i] = num2[i];
        }else{
            num3[i] = num1[i]; 
        }
    }
    if(op == k){
        int last = i;
        int suc = 0;
        for(int j = i; j < n; j++) {
            if(num1[j] < num2[j]){
                suc = 1;
                break;
            }else if(num1[j] > num2[j]) break;
        }
        // a[last:] < b[last:]
        for(int j=last;j<n;j++) num3[j] = num1[j];
        if(suc){
            for(auto &x : num3) cout << x; cout << "\n";
            return;
        }
        // for(auto &x : num3) cout << x; cout << "\n";
        suc = 0;
        int j = last - 1; //printf("last = %d\n", last);
        for(;j >= 0; j--){
            while(num3[j] >= 0 && (num3[j] == num2[j] || num3[j] == num1[j])){
                num3[j] = num3[j] - 1;
            }
            if(num3[j] >= 0) {
                suc = 1;
                break;
            }
            num3[j] = 9;
            while(num3[j] >= 0 && num3[j] != num1[j]){
                num3[j] = num3[j] - 1;
            }
        }
        if(suc){
            for(auto &x : num3) cout << x; cout << "\n";
            return;
        }
    }
}

signed main(){
    solve();
    return 0;
}
