/**
 * 题意：给定n,p,n个形如p^ki,要求将n数ki分为两组，最小化两个集合之和的差的绝对值
 *       n<=1e6, p<=1e6, ki<=1e6
 *  思路：贪心,特判p=1,注意 5^10 = 5 * 5^9 即 a^b = a*a^(b-1) 从高次向低次考虑
 */
void solve(){
    int n,p; cin>>n>>p;
    vector<int> vec(n); for(auto &x : vec) cin>>x;
    if(p == 1){
        cout << (n & 1) << "\n";
        return;
    }
    sort(vec.begin(), vec.end(), greater<int>());
    int s1 = 0, s2 = 0;
    for(int i=0;i<n;i++){
        s1 += fastpow(p, vec[i]);
        s1 %= mod;
        int j = i+1;
        int num = vec[i], ne = 1, s = 0;
        while(j < n && ne > 0){
            // 数字不同 需要的个数得重新计算
            while(vec[j] != num && ne * p <= n - j) num -= 1, ne *= p;
            if(vec[j] == num) ne--;
            s += fastpow(p, vec[j]);
            s %= mod;
            j += 1;
            if(ne == 0){
                s1 -= fastpow(p, vec[i]); //反悔
                s1 %= mod;
                s = 0;
            }
        }
        s2 += s;
        s2 %= mod;
        i = j - 1;
    }
    cout << ((s1 - s2) % mod + mod) % mod << "\n";
}


