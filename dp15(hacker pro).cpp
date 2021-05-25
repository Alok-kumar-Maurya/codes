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
int dp[50][1 << 15] ;
int n ;
vi v ,prime{2,3,5,7,11,13,17,19,23,29,31,37,41,43,47}; 
vector<vector<int>> pfs(51) ;
int f(int cur , int mask) 
{
      if(cur < 0 )
      {
          return  0;
      }
      if(dp[cur][mask] != -1)
      { 
          return dp[cur][mask];
      } 
      if(v[cur] == 1) 
      {
          int ans = 1 + f(cur - 1 , mask) ;
          dp[cur][mask] = ans ;
          return ans ;
      }
      int ans =  f(cur-1 , mask) ;
      int newmask = mask ;
      for(auto x : pfs[v[cur]])
      {
          if( newmask & (1 << x) ) 
          return dp[cur][mask] = ans ; 
          newmask |= (1 << x ) ;
      }
      ans = max (ans , 1 + f(cur-1 , newmask));
      dp[cur][mask] = ans ;
      return ans ;

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
    for(int i = 1 ; i <= 50 ; i++) 
    {
        for(int j = 0 ; j < 15 ;j ++)
        {
            if(i % prime[j] == 0) 
            pfs[i].push_back(j) ;
        }
    }
    while(t--)
    {
        cin >> n  ;
        v.resize(n);
        for(auto &x : v) 
        cin >> x ; 
        memset(dp , -1 , sizeof(dp)) ;
        cout << f(n-1 , 0) << endl;
        v.clear(); 
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