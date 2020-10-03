#include<bits/stdc++.h> 
using namespace std;
 
#define ull unsigned long long
#define int long long
#define ld long double
#define pb push_back
#define pi  pair< int,int >
#define ff first
#define ss second
#define mod 1000000007
#define inf 100000000000000009
#define endl "\n"

const int N = 1e5+5;

int vis[N], dist[N], in_deg[N];

vector<int>arr[N];

void dfs(int p)
{
    vis[p] = 1;
    for(int child : arr[p])
    {
        dist[child] = max(dist[child], dist[p]+1);
        in_deg[child]--;
        if(in_deg[child] == 0)
            dfs(child);
    }
}

signed main()
{
 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
 
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
 
    int n,m,u,v;
    cin>>n>>m;

    for(int i=0; i<=n; i++)
    {
        vis[i] = 0;
        dist[i] = 0;
        in_deg[i] = 0;
    }

    for(int i=0; i<m; i++)
    {
        cin>>u>>v;
        arr[u].pb(v);
        in_deg[v]++;
    }

    for(int i=1; i<=n; i++)
    {
        if(!vis[i] && in_deg[i]==0)
            dfs(i);
    }

    int answer = -1;

    for(int i=1; i<=n; i++)
        answer = max(answer, dist[i]);

    cout<<answer<<endl;
 
    return 0;
   
}