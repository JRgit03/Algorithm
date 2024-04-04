struct Node{
    int l,r;
    int sum;  
    int lazy; 
}tr[N*4];

void pushdown(int u){ 
    auto &root = tr[u] , &left = tr[u<<1] , &right = tr[u<<1|1];
    if(root.lazy){
        left.sum += 1LL * (left.r-left.l+1) * root.lazy , left.lazy += root.lazy;
        right.sum += 1LL * (right.r-right.l+1) * root.lazy , right.lazy += root.lazy;
        root.lazy = 0; 
    }
}

void pushup(int u){
    tr[u].sum = tr[u<<1].sum + tr[u<<1|1].sum; 
}

void build(int u,int l,int r){
    if(l == r) tr[u] = {l,r,w[r],0}; 
    else{
        tr[u] = {l,r,0,0};
        int mid = l + r >> 1;
        build(u<<1,l,mid) , build(u<<1|1,mid+1,r);
        pushup(u); 
    }
}

void modify(int u,int l,int r,int d){
    if(tr[u].l >= l && tr[u].r <= r){
        tr[u].sum += 1LL * (tr[u].r - tr[u].l + 1) * d;
        tr[u].lazy += d;
    }else{
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if(l <= mid) modify(u<<1,l,r,d);
        if(r >  mid) modify(u<<1|1,l,r,d);
        pushup(u); 
    }
}

int query(int u,int l,int r){
    if(tr[u].l >= l && tr[u].r <= r) return tr[u].sum;
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    int sum = 0;
    if(l <= mid) sum += query(u<<1,l,r);
    if(r >  mid) sum += query(u<<1|1,l,r);
    return sum;
}