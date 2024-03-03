//level[a]--> distance of a from root node
// TC --> O(n) in worst case
// so better to use binary lifting
int LCA(int a,int b)
{
    ind d=level[b]-level[a];
    if(d<0)
    swap(a,b);
    d=abs(d);
    while(d>0)
    {
        b=par[b];
        d--;
    }
    // if one of them is itself an lca
    if(a==b)
    return a;
    
    // if both of them are in diff subtree
    while(par[a]!=par[b])
    {
        a=par[a];
        b=par[b];
    }
    return par[a];
}
