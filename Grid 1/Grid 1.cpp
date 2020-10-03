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
#define inf 9223372036854775807
#define endl "\n"

const int N = 1e5+5;

signed main()
{
 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
 
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    int n,m;
    cin>>n>>m;
    char a[n][m];

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>a[i][j];

    int dp[n][m];

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            dp[i][j] = 0;

    dp[0][0] = 1;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(a[i][j] == '#')
                continue;
            if(i==0 && j==0)
                continue;
            if(i==0)
                dp[i][j] = dp[i][j-1];
            else if(j==0)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] += (dp[i-1][j]%mod + dp[i][j-1]%mod) % mod;
        }
    }

    cout<<dp[n-1][m-1]%mod<<endl;
 
    return 0;
   
}