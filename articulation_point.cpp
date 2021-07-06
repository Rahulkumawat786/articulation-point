#include<bits//stdc++.h>
#define pb push_back
#define endl "\n"
using namespace std;
vector<int> adj[1000];
int visited[1000],in[1000],low[1000],timer;
set<int> AP;
void dfs(int node,int par=-1)
{
    visited[node] = 1;
    in[node]= low[node] = timer++;
    int children = 0;
    for(int child : adj[node])
    {
        if(child==par) continue;
        else if(visited[node])
        {
            low[node] = min(low[node],in[child]);
        }
        else{
            dfs(child,node);
            children++;
            low[node] = min(low[node],low[child]);
            if(in[node]<=low[child] && par!=-1)
                AP.insert(node);
        }
    }
    if(par==-1 && children>1)
        AP.insert(node);
}
int main()
{
    int n,m,a,b;
    cin>>n>>m;
    while(m--){
        cin>>a>>b , adj[a].pb(b),adj[b].pb(a);
    }
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==0){
            dfs(i);
        }
    }
    cout<<AP.size()<<endl;
}
