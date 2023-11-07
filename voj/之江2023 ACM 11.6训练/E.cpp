#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    string s; cin>>s;
    int x = 0, y = 0;
    set<pair<int,int>> st = {{0,0}};
    for(auto c : s){
        if(c == 'R') x++;
        else if(c == 'L')x--;
        else if(c == 'U')y++;
        else y--;
        if(st.count({x,y})){
            cout << "Yes" << "\n";
            return 0;
        }
        st.insert({x,y});
    }
    cout << "No" << "\n";
    return 0;
}
