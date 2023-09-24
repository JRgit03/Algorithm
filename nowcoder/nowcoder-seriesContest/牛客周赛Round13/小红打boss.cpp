#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define int long long
using namespace std;

void solve(){
    int n; cin>>n;
    multiset<int> sf,si,st; // fire ice thunder
    for(int i=0;i<n;i++){
        string s; int x; cin>>s>>x; 
        if(s[0] == 'f') sf.insert(x);
        else if(s[0] == 'i') si.insert(x);
        else st.insert(x);
    }
    
    //for(auto x : st) cout << x << "\n";
    
    int ans = 0;
    while(st.size() > 0 || si.size() > 0 || sf.size() > 0){
        if(st.size() && si.size() && sf.size()){
        	//cout << st.size() << " " << si.size() << " " << sf.size() << "\n";
            int maxx = max({*sf.rbegin(),*si.rbegin(),*st.rbegin()}); //cout << maxx << "\n";
            if(maxx == *sf.rbegin()){
                sf.erase(--sf.end());
                int minn = min(*si.begin(),*st.begin());
                if(minn == *si.begin()){
                    si.erase(si.begin());
                    ans += minn + maxx * 2;
                }else{
                    st.erase(st.begin());
                    ans += minn + maxx * 2;
                }
            }else if(maxx == *si.rbegin()){
                si.erase(--si.end()); 
                int minn = min(*sf.begin(),*st.begin());
                if(minn == *sf.begin()){
                    sf.erase(sf.begin());
                    ans += minn + maxx * 2;
                }else{
                    // cout << "x" << "\n";
                    st.erase(st.begin()); 
                    ans += minn + maxx * 2;
                }
            }else if(maxx == *st.rbegin()){
                st.erase(--st.end());
                int minn = min(*sf.begin(),*si.begin());
                if(minn == *sf.begin()){
                    sf.erase(sf.begin());
                    ans += minn + maxx * 2;
                }else{
                    si.erase(si.begin());
                    ans += minn + maxx * 2;
                }
            }
        }else if(st.size() && si.size()){
            int maxx = max(*st.rbegin(),*si.rbegin());
            if(maxx == *st.rbegin()){
                st.erase(--st.end());
                int minn = *si.begin(); si.erase(si.begin());
                ans += minn + maxx * 2;
            }else{
                si.erase(--si.end());
                int minn = *st.begin(); st.erase(st.begin());
                ans += minn + maxx * 2;
            }
        }else if(st.size() && sf.size()){
        	//cout << st.size() << " " << si.size() << " " << sf.size() << "\n";
            int maxx = max(*st.rbegin(),*sf.rbegin());
            if(maxx == *st.rbegin()){
                st.erase(--st.end());
                int minn = *sf.begin(); sf.erase(sf.begin());
                ans += minn + maxx * 2;
            }else{
                sf.erase(--sf.end());
                int minn = *st.begin(); st.erase(st.begin());
                ans += minn + maxx * 2;
            }
        }else if(si.size() && sf.size()){
            int maxx = max(*si.rbegin(),*sf.rbegin());
            if(maxx == *si.rbegin()){
                si.erase(--si.end());
                int minn = *sf.begin(); sf.erase(sf.begin());
                ans += minn + maxx * 2;
            }else{
                sf.erase(--sf.end());
                int minn = *si.begin(); si.erase(si.begin());
                ans += minn + maxx * 2;
            }
        }else if(st.size()){
            ans += *st.begin(); st.erase(st.begin());
        }else if(si.size()){
            ans += *si.begin(); si.erase(si.begin());
        }else {
            ans += *sf.begin(); sf.erase(sf.begin());
        }
    }
    cout << ans << "\n";
}

signed main(){
    IOS; solve();
    return 0;
}

/*
5
fire 3
thunder 2
ice 5
fire 4
thunder 3
*/
