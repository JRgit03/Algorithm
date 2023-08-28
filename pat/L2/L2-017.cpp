#include <bits/stdc++.h>
using namespace std;

int ls,rs;
int lcnt,rcnt;

int main(){
	int n;cin>>n;
    vector<int> vec(n+1);
    for(int i=1;i<=n;i++) cin>>vec[i];
    sort(vec.begin()+1,vec.end());
    
    for(int i=1,j=n;i<=j;i++,j--){
        if(i==j){
            rs+=vec[i];rcnt++;
        }else{
            ls+=vec[i] , rs+=vec[j];
            lcnt++ , rcnt++;
        }
    }
    printf("Outgoing #: %d\n",rcnt);
    printf("Introverted #: %d\n",lcnt);
    printf("Diff = %d\n",rs-ls);
	return 0;
}

/**
 * Outgoing #: 5
   Introverted #: 5
   Diff = 3611
*/