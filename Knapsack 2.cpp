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
 
signed main()
{
 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
 
    int N,W;
    int w[105];
    int v[105];
    cin>>N>>W;

    int sum = 0;
    for(int i=1; i<=N; i++)
    {
        cin>>w[i];
        cin>>v[i];
        sum += v[i];
    }
 
    int dp[sum+1][N+1];

    for(int i=0; i<=sum; i++)
        for(int j=0; j<=N; j++)
            dp[i][j] = inf;

    for(int i=0; i<=N; i++)
        dp[0][i] = 0;
 
    for(int i=1; i<=sum; i++)
    {
        for(int j=1; j<=N; j++)
        {
            if(i-v[j]>=0)
                dp[i][j] = min(dp[i-v[j]][j-1] + w[j], dp[i][j-1]);
            else
                dp[i][j] = dp[i][j-1];
        }
    }

    int ans = 0;
 
    for(int i=0; i<=sum; i++)
    {
        for(int j=0; j<=N; j++)
        {
            if(dp[i][j] <= W)
                ans = max(ans,i);
        }
    }

    cout<<ans<<endl;
 
    return 0;
   
}