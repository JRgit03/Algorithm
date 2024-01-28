#include <bits/stdc++.h>
using namespace std;

int main(){
    string s; cin>>s;
    vector<int> cnt(26);
    for(auto &c : s) cnt[c - 'a'] += 1;
    int maxx = *max_element(cnt.begin(), cnt.end());
    for(int i=0;i<26;i++)
        if(cnt[i] == maxx){
            cout << char(i + 'a') << "\n";
            return 0;
        }
    return 0;
}
