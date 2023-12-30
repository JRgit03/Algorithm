int tr[N];
int lowbit(int x){return x&-x;}
void add(int x,int c){for(int i=x;i<=n;i+=lowbit(i)) tr[i] += c;}
int sum(int x){int res = 0;for(int i=x;i;i-=lowbit(i)) res += tr[i];return res;}