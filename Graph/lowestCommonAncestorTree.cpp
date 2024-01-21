// this code calculates LCA and shortest distace b/w each and every node in O(nlogn) time
// and after calculating all things..each query can be processed in O(1) time
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> g,LCA;
vector<int> level;
int N,maxN;

void dfs(int node,int lvl,int parent)
{
    level[node] = lvl;
    LCA[node][0]=parent;

    for(auto &child:g[node])
    {
        if(child==parent) continue;
        dfs(child,lvl+1,node);
    }

}

void init(){

    dfs(1,0,-1);

    for(int j=1;j<=maxN;++j)
    {

        for(int i=1;i<=N;++i)
        {
            if(LCA[i][j-1] != -1)
            {
                int par = LCA[i][j-1];
                LCA[i][j] = LCA[par][j-1];
            }
        }

    }
    // for(int i=1;i<=N;++i)
    // {
    //     cout<<i<<"--> ";
    //     for(int j=0;j<=maxN;++j)
    //     {
    //         cout<<LCA[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }


}
// finding LCA
int getLCA(int a,int b)
{
    if(level[a] > level[b]) swap(a,b);
    int d = level[b]-level[a];

    while(d>0)
    {
        int i = log2(d);
        b = LCA[b][i];
        d -= (1<<i);
    }

    if(a==b) return a;

    for(int i=maxN;i>=0;--i)
        if(LCA[a][i]!=-1 && (LCA[a][i] != LCA[b][i]))
            a = LCA[a][i] , b = LCA[b][i];
 
    return LCA[a][0];
}

int getDist(int a,int b)
{
    int lca = getLCA(a,b);
    return level[a]+level[b] - 2*level[lca];
}

int main()
{

    int n;
    cin>>n;
    N = n;
    maxN = ceil(double(log2(N)));
    //cout<<maxN<<"\n";
    g.resize(N+1);
    level.resize(N+1);
    LCA.assign(N+1,vector<int>(maxN+1,-1));
    for(int i=0;i<n-1;++i)
    {
        int f,s;
        cin>>f>>s;
        g[f].emplace_back(s);
        g[s].emplace_back(f);
    }
    init();
    int q;
    cin>>q;
    while(q--)
    {
        int f,s;
        cin>>f>>s;
        cout<<getDist(f,s)<<"\n";
    }

}
