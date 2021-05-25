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
void lsi_n2()
{
    int n ;
    cin >> n ;
    vi v(n);
    for(auto &x : v)
    {
        cin >> x ;
    }
    vi lsi(n,1) ;
    for(int i = 1 ; i < n ; i++)
    {
        for(int j = i -1 ; j >=0 ; j--)
        {
            if(v[j] < v[i])
            {
                lsi[i] = max(lsi[j] + 1 , lsi[i] );
            }
        }
    } 
    int ans = *max_element(lsi.begin() , lsi.end());
    cout << ans ;
}
void lsi_nlon_n()
{
    int n ;
    cin >> n ;
    vi v(n + 1);
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> v[i] ;
    }
    vi lsi(n+1 , INT64_MAX) ;
    lsi[0] = INT64_MIN ;
    int ans = 0 ;
    for(int i = 1 ; i <= n ; i++)
    {
       auto it = upper_bound(lsi.begin() , lsi.end() , v[i] ) ;
       int pos = it - lsi.begin() ;
       if( lsi[pos] > v[i] && lsi[pos-1] < v[i]) 
       {
           lsi[pos] = v[i] ;
       }
    } 
    for(int i = 1 ; i <=n ; i ++ )
    {
        if(lsi[i] != INT64_MAX )
        {
            ans = i ;
        }
        debugx(lsi[i]) ;
    }
    cout << ans ;
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
    lsi_n2() ;
    lsi_nlon_n();
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
