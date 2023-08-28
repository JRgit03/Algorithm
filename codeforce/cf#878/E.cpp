#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

void solve(){
	vector<string> s(2); cin>>s[0]>>s[1];
    int n = s[0].length() , bad = 0;
    for(int i=0;i<n;i++) bad += (s[0][i] != s[1][i]);
    queue<pair<int,int>>  unblock; // [time,pos] time递增 pos从0开始
    int t,q;cin>>t>>q;
    for(int i=0;i<q;i++){
        while(unblock.size() && unblock.front().first == i){
            auto [time,pos] = unblock.front(); unblock.pop();
            if(s[0][pos] != s[1][pos]) bad++;
        }
        int type; cin>>type;
        if(type==1){
            int pos;cin>>pos;pos--;
            if(s[0][pos] != s[1][pos]) bad--;
            unblock.push({i+t,pos});
        }else if(type==2){
            int ob1,pos1,ob2,pos2;
            cin>>ob1>>pos1>>ob2>>pos2;
            ob1--;pos1--;ob2--;pos2--;
            //交换前
            if(s[ob1][pos1] != s[1^ob1][pos1]) bad--;
            if(s[ob2][pos2] != s[1^ob2][pos2]) bad--;
            //交换后
            swap(s[ob1][pos1],s[ob2][pos2]);
            if(s[ob1][pos1] != s[1^ob1][pos1]) bad++;
            if(s[ob2][pos2] != s[1^ob2][pos2]) bad++;
        }else{
            //cout << bad << "\n";
            cout << (!bad ? "YES" : "NO") << "\n";
        }
    }
}

int main(){
	int t;cin>>t;
    while(t--)solve();
	return 0;
}