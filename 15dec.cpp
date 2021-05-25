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
#define max 3e5 + 1
#define mod 1000000007
vi fact(max) , inve_fact(max);
int fast_po(int a ,int b)
{
     int ans = 1 ;
     while(b)
     {
          if(b%2 == 0) 
          {
             a = (a * a )% mod ;
             b /= 2 ;
          }
          else 
          {
               ans = (ans * a ) % mod;
               b-- ;
          }
     }
     return ans ;
}
void set_vec()
{
     for(int i = 1 ; i < max ; i++)
     {
          fact[i] = (fact[i-1] * i) % mod ;
          inve_fact[i] = fast_po ( fact[i] , mod -2 ) ;
          
     }
}
int calculate(int n ,int r)
{
        if( r > n)
        return 0 ;
        int ans = fact[n] * inve_fact[n - r] % mod * inve_fact[r] % mod;
        return ans%mod ;
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
    fact[0] = 1 ;
    inve_fact[0] =1 ;
    set_vec() ;
    while(t--)
    {         
           int n ,m, k ;
           cin >> n >> m >> k ;
           vi v(n) ;
           for(auto &x : v) 
           cin >> x ;
           sort(v.begin() ,v.end());
           int ans = 0 ;
           for(int i = 0 ; i <= n-m ; i++)
           {
                int c = upper_bound(v.begin() , v.end() , v[i] + k) - v.begin() ; 
                int pos = c - i -1;
                ans = ( ans + calculate(pos , m -1 )) % mod;

           } 
           cout << ans << endl;
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
