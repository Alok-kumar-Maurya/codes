#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PI 3.1415926535897932384626 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
#define debugxy(x,y) cout<<"[ "<<x<<"  "<<y<<" ]"<< endl
#define debugx(x) cout <<"[ "<< x <<" ]"<<endl
vector<int> v;
int k;
// int dp[90000][90000];
int f(int cur , int moves ,int sum1 ,int sum2 ) 
{
    if(cur == v.size()) 
    return INT32_MAX ;
    if(sum1 >= k && sum2 >= k) 
    return moves ;
    // if(dp[sum1][sum2] != -1) 
    // return dp[sum1][sum2];
    int c = min( f(cur + 1 , moves+1 , sum1 + v[cur] ,sum2) , f(cur + 1 , moves+1 , sum1 , sum2 + v[cur]) ) ;
    // dp[sum1][sum2] = c ;
    return c ;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int t ; 
    cin >> t ;
    while(t--)
    {
        int n  ;
        cin >> n >> k;
        v.resize(n);
        // memset(dp ,-1 ,sizeof(dp));
        for(int i = 0 ; i < n ; i++)
        {
            cin >> v[i];
        }
        sort(v.begin() , v.end() ,greater<int>()) ;
        int c = f(0,0,0,0);
        if(c == INT32_MAX)
        cout <<"-1\n" ;
        else 
        cout << c << endl;
    }
 return 0;
// THINGS TO KEEP IN MIND
//   * int overflow, time and memory limits
//   * Special case (n = 1?)
//   * Do something instead of nothing and stay organized
//   * Don't get stuck in one focus
//   * int l=s.length()-x (s.length()<x) garbage value
// TIME AND MEMORY LIMITS
//   * 1 second is approximately 10^8 operations (c++)
//   * 10^6 Elements of 32 Bit (4 bytes) is equal to 4 MB
//   * 62x10^6 Elements of 32 Bit (4 bytes) is equal to 250 MB
//   * 10^6 Elements of 64 Bits (8 bytes) is equal to 8 MB
//   * 31x10^6 Elements of 64 Bit (8 bytes) is equal to 250 MB
}
