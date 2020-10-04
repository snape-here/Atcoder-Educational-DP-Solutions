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

    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];

    int dp[n+1][n+1];

    for(int i=0; i<=n; i++)
        for(int j=0; j<=n; j++)
            dp[i][j] = 0;

    for(int i=0; i<n; i++)
    {
        for(int j=i; j>=0; j--)
        {
            if(i==j)
                dp[i][j] = a[i];
            else
                dp[i][j] = max(a[i]-dp[i-1][j], a[j]-dp[i][j+1]);
        }
    }

    cout<<dp[n-1][0];
 
    return 0;
   
}