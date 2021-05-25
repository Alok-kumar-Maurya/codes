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
struct querry
{
    public : 
    int l ,r, val ;
};
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n , m , k ;
    cin >> n >> m >> k ;
    int arr[n + 2] ;
    for(int i = 0 ; i <  n ;  i ++ )
    cin >> arr[i];
    vector<querry> use_later;
    for(int i = 0 ; i < m ; i ++ )
    {   

        int l , r ,  val ;
        cin >> l >> r >> val ;
        l -- ; r -- ;
        use_later.push_back({ l , r , val});
    }
    vi repeat( m + 2, 0);
    while( k--) 
    {
         int  l , r ;
         cin >> l >> r ;
         l-- ; r -- ;
         repeat[l] ++ ;
         repeat[r + 1] -- ;
    }
    for(int i = 1 ; i < m ; i ++ ) 
    repeat[i] += repeat[i - 1] ;

    vi pre_sum( n + 2 ,0) ;
    for(int i = 0 ; i < m ; i ++ ) 
    {
        auto x = use_later[i] ;
        pre_sum[x.l] +=  ( x.val * repeat[i] ) ;
        pre_sum[x.r + 1] -= ( x.val * repeat[i] ) ;
    }
    for(int i = 1 ; i < n ; i ++) 
    pre_sum[i] += pre_sum[i - 1] ;
    
    for(int i = 0 ; i < n ; i ++) 
    cout << arr[i] + pre_sum[i] <<" "; 
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