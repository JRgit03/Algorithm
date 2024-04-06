/**
 *  题意：给定n个飞机的开始降落时间ti,最晚降落时间ti+di,和飞机降落时间li,
 *       求是否存在一种合法的顺序,使得n个飞机全部安全降落 n<=10
 *  思路：n<=10枚举所有可能的降落顺序，贪心维护起飞时间 O(n! * n)
 */
const int N = 11;
int n,suc;
int t[N],d[N],l[N];

void solve(){
    suc = 0;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>t[i]>>d[i]>>l[i];
    vector<int> id(n+1); for(int i=1;i<=n;i++) id[i] = i;
    do{
        int f = 1, cur = 0;
        for(int i=1;i<=n;i++){
            int x = t[id[i]], y = t[id[i]] + d[id[i]];
            if(y < cur) f = 0;
            else {
                cur = max(cur, x);
                cur = cur + l[id[i]];
            }
        }
        suc |= f;
    }while(next_permutation(id.begin() + 1, id.end()));
    cout << (suc ? "YES" : "NO") << "\n";        
}