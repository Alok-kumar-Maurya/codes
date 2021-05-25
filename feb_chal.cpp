#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PI 3.1415926535897932384626 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
#define debugxy(x,y) cout<<"[ "<<x<<"  "<<y<<" ]"<< endl
#define debugx(x) cout <<"[ "<< x <<" ]" << endl
#define mod 998244353
#define mx 200005
int fact[mx] , inve_fact[mx] ;
int fast_po(int a ,int b)
{
     int ans = 1 ;
     while(b)
     {                        
          if(b % 2 == 0) 
          {
             a = (a * a ) % mod ;
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
     for(int i = 1 ; i < mx ; i++)
     {
          fact[i] = (fact[i-1] * i) % mod ;
          inve_fact[i] = fast_po ( fact[i] , mod -2 ) ;
          
     }
}
int calculate(int n ,int r)
{   
    if( r > n )
      return  0;
    int ans = ( inve_fact[n - r] * inve_fact[r] ) % mod;
    ans = ( ans * fact[n] ) % mod ;
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
    fact[0] = 1 ;
    inve_fact[0] = 1;
    set_vec() ;

        int n ;
        cin >> n ;
        int set_bit[30] = { };
        int maaax = 0;
        for(int i = 0 ; i < n ; i ++ )
        {
            int a ;
            cin >> a ;
            int mask = 0 ;
            while(a) 
            {
                if(a & 1) 
                set_bit[mask] ++ ; 
                a >>= 1 ;
                mask ++ ;
            }
        }
        int ans[n + 2] = { 0 };
        for(int  i = 0 ; i <= 29 ; i ++ )
        {
            int p = set_bit[i] ;
            int q = n - p ;
            vi f1( n + 1 , 0) , f2( n + 1 , 0) ;
            for(int i = 0 ; i <= p ; i ++ )
            {
                if ( i & 1)                      /// function 1
                f1[i] = calculate(n , i);
            }

            for(int i = 0 ; i <= q ; i ++ ) 
            f2[i] = calculate( n , i) ;             /// function 2

            for
            
        }


        for(int i = 2 ; i <= n ; i++) 
        ans[i] = (ans[i] + ans[i-1]) % mod ;          //// pre sum 

        int q ;
        cin >> q ;
        while(q--) 
        {
           int l ;
           cin >> l ;
           cout << ans[l] << endl;
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