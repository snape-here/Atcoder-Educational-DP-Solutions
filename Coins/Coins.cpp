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

    ld a[n];

    for(int i=0; i<n; i++)
        cin>>a[i];

    ld dp[n+1]={0};

    dp[0] = 1;

    for(int i=0; i<n; i++)
        for(int j=i+1; j>=0; j--)
            dp[j] = (j == 0 ? 0 : dp[j-1]*a[i]) + dp[j]*(1-a[i]);

    ld ans = 0;

    for(int i=n/2+1; i<=n; i++)
        ans += dp[i];

    cout<< fixed << setprecision(10) << ans;
 
    return 0;
   
}