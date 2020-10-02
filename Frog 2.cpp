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

    int n,k;
    cin>>n>>k;
    for(int i=0; i<n; i++)
        cin>>h[i];

    int dp[n+1];

    dp[0] = 0;

    for(int i=1; i<n; i++)
    {
        int x = min(i,k);
        int temp = inf;
        for(int j=1; j<=x; j++)
            temp = min(temp, dp[i-j]+abs(h[i]-h[i-j]));
        dp[i] = temp;
    }

    cout<<dp[n-1]<<endl;
 
    return 0;
   
}