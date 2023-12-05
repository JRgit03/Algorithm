#include <bits/stdc++.h>
using namespace std;

int main(){
    int M,D; cin>>M>>D;
    int y,m,d; cin>>y>>m>>d;
    if(d == D) {
        d = 1;
        if(m == M){
            m = 1;
            y += 1;
        }else{
            m += 1;
        }
    }else{
        d += 1;
    }
    cout << y << " " << m << " " << d << "\n";
    return 0;
}
