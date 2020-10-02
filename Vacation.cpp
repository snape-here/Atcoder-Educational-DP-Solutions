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
#define inf 300000000000000007
#define endl "\n"

const int N = 1e5+5;

int a[N], b[N], c[N];

signed main()
{
 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
 
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    int n;
    cin>>n;

    for(int i=0; i<n; i++)
        cin>>a[i]>>b[i]>>c[i];

    int dp[n][3];

    dp[0][0] = a[0];
    dp[0][1] = b[0];
    dp[0][2] = c[0];

    for(int i=1; i<n; i++)
    {
        dp[i][0] = a[i] + max(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = b[i] + max(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = c[i] + max(dp[i-1][0], dp[i-1][1]);
    }

    int ans = max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]));

    cout<<ans<<endl;

    return 0;
   
}