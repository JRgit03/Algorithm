int inorder[N] , postorder[N];
unordered_map<int,int> l,r;
unordered_map<int,int> pos; // pos[i] 表示值为i的值在中序遍历中的位置

int build(int il,int ir,int pl,int pr){ //返回当前维护区间子树的根
    int root = postorder[pr];
    int k = pos[root];

    if(il < k){ //存在左子树
        l[root] = build(il,k-1,pl,pl+(k-1-il)); //两个区间长度相同！
    }

    if(ir > k){
        r[root] = build(k+1,ir,pl+(k-1-il)+1,pr-1); // 后序遍历开始即左子树+1
    }
    return root;
}