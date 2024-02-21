vector<int> preorder;
vector<int> inorder;

int build(int il,int ir,int pl,int pr){ //根据中序遍历 + 前序遍历建树
    int root = preorder[pl];
    int k; 
    for(k=il;k<=ir;k++){
        if(root == inorder[k])  break;
    }
    if(il < k){//存在左子树
        l[root] = build(il,k-1,pl+1,pl+1+(k-1-il));
    }
    if(ir > k){
        r[root] = build(k+1,ir,pl+1+(k-1-il)+1,pr);
    }
    return root;
}