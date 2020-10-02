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

int h[N];

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
        cin>>h[i];

    int dp[n+1];

    dp[0] = 0;

    for(int i=1; i<n; i++)
    {
        if(i==1)
            dp[i] = dp[i-1]+abs(h[i]-h[i-1]);
        else
            dp[i] = min(dp[i-1]+abs(h[i]-h[i-1]), dp[i-2]+abs(h[i]-h[i-2]));
    }

    cout<<dp[n-1]<<endl;
 
    return 0;
   
}