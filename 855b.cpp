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
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n , p ,q,r ;
    cin >> n >> p >> q >> r ;
    vi v(n);
    for(int i = 0 ; i < n; i++) 
    cin >> v[i] ;
    vector<pair<int,int>> left_right (n) ;
    left_right[0].first = p * v[0] ;
    for(int i = 1 ; i < n ; i ++ )
    {
        left_right[i] .first  = max ( left_right[i - 1].first , p*v[i]) ; 
    }
    left_right[n-1].second = r * v[n-1] ;
    for(int i = n - 2 ; i >= 0 ; i -- )
    {
        left_right[i] .second  = max ( left_right[i + 1].second , r*v[i]) ; 
    }
    int ans = INT64_MIN ;
    for(int i = 0 ; i < n  ; i++) 
    {    
        int c = 0 , d = 0,m = 0 ;
        if( i > 0 )
        c =  left_right[i-1].first ;
        else 
        c = p * v[0] ;
        if(i < n-1)
        d = left_right[i+1].second ;
        else 
        d = v[n-1] * r ;
        
        m = q * v[i] ;
        ans = max ({  ans , c + d + m , m + p * v[i] + d , m + r * v[i] + c  , m + p * v[i] + r * v[i] }) ;
    }
    cout << ans ;
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