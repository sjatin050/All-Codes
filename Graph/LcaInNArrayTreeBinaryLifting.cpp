//https://www.youtube.com/watch?v=k6AQNBwGgbQ&list=PL5DyztRVgtRW0Kdd8i1xML7t-ge56XRQR&index=5

//Using binary lifting to find LCA of 2 nodes
//to make all this LCA 2d array it takes O(NlogN) time
// for find LCA of 2 nodes at max takes O(logN) time
// gives the corresponding parent of all nodes
void dfs(int node,int par)
{
    LCA[node][0]=par;
    for(int child:adj[node])
    {
        if(child!=par)
        {
            dfs(child,node);
        }
    }
}


// takes O(NlogN) time
void init()
{
    dfs(1,-1);
    for(int j=1;j<=maxN;j++)
    {
        for(int i=1;i<=N;i++)
        {
            if(LCA[i][j-1]!=-1)
            {
                int par=LCA[i][j-1];
                LCA[i][j]=LCA[par][j-1];
            }
        }
    }
}

//level[a]--> distance of 'a' from root node
int LCA(int a,int b)
{
    if(level[a]>level[b])
    swap(a,b);
    
    int d=level[b]-level[a];
    
    while(d>0)
    {
        int i=log2(d);
        b=LCA[b][i];
        d-=(1<<i);
    }
    // if one of them is itself an lca
    if(a==b)
    return a;
    
    // if both of them are in diff subtree
    while(LCA[a][0]!=LCA[b][0])
    {
        a=LCA[a][0];
        b=LCA[b][0];
    }
    return LCA[a][0];
}
