#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PI 3.1415926535897932384626 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
#define debugxy(x,y) cout<<x<<"  "<<y<< endl
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
    int x ;
    cin >> x; 
    vi v;
    if( x == 1 )
    {
        cout << "1 1";
        return 0;
    }
    for(int i = 2 ; i*i<= x ;i++)
    {
        if(x % i == 0) 
        {    
            int cnt = 1 ;
            while(x%i == 0)
            {
                x/=i ;
                cnt *= i;

            }
            v.push_back( cnt );
        }

    }

    int a,b;
    if(x!=1) 
    v.push_back( x );
    sort( v.begin() , v.end()) ;
    if( v.size() == 1) 
    {
       a = 1 ;
       b = v[0];
    }
    else 
    {
         int n = v.size() ;
         a = INT64_MAX ;
         b = a;
        for(int i = 0 ; i < (1<<n) ; i ++)
         {    
                int l = 1 , m = 1;
                for(int j = 0 ; j < n ;j++)
                {
                    if( i & (1<<j)) 
                    {
                          l *= v[j] ;
                    }
                    else 
                    {
                          m *= v[j] ;
                    }
                }
                if ( max( l , m) < max ( a , b)) 
                {
                       a = l; 
                       b = m ;
                }

         }
    }
    cout << a << " " << b ;
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