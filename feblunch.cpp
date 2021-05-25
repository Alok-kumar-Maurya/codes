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
#define endl  "\n" 
#define mod  1000000007
int cal(int a , int b) 
{
     int ans = 1 ;
     while(b) 
     {
           if( b % 2 == 0 ) 
           {
               a = (a * a) % mod ;
               b /= 2 ;
           }
           else 
           {
               ans = (ans * a ) % mod ;
               b -- ;
           }
     }
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
    int n , m ;
    cin >> n >> m ;
    vi arr(n) ,pre(n) , suf(n) ;
    for(int i = 0 ;i < n ; i++) 
    cin >> arr[i];
    pre[0] = arr[0];
    for(int i = 1 ; i < n ; i ++ ) 
    {   

        pre[i] = __gcd(arr[i] , pre[i-1]);
        pre[i] = cal(pre[i] , 1000000005) ;
    }
    suf[n-1] = arr[n-1] ;
    for(int i = n - 2 ; i >= 0 ; i --) 
    {
        suf[i] = __gcd(suf[i+1] , arr[i]); 
        suf[i] = cal(suf[i] , 1000000005) ;
    }
    while(m--) 
    {
        int l , x ;
        cin >>  l >> x ;
        l -- ;
        arr[l] *= x ;
        arr[l] %= mod ;
        if( l == 0 ) 
        {   
            if( n == 1)
            cout << arr[l] << endl;
            else 
            {
                int c = __gcd(arr[l] ,suf[1]); 
                cout << cal(c, 1000000005) << endl;
            }
        }
        else if(l == n - 1) 
        {
            int c  = __gcd(pre[l - 1] , arr[l]) ;
            cout << cal(c , 1000000005) << endl;
        }
        else 
        {
              int c = __gcd(pre[l - 1] , suf[l + 1]) ;
              c = cal(c , 1000000005) ;
              c = __gcd(c , arr[l]) ;
              cout << cal(c ,1000000005) << endl;
        }
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