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
int fact[100000] ;
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
    for(int i = 0 ; i < )
    while(t -- )
    {
        int n ; 
        vi v(n);
        int annd = (1 << 30 ) - 1;
        int bit[30] = { };
        map<int,int> m ;
        for(auto &x : v) 
        {
            cin >> x ;
            annd &= x ;
            m[x] ++ ;
            int c = x ;
            int j = 0 ;
            while(c ) 
            {
                if(c & (1 << j )) 
                bit[j] ++ ;
                c >>= 1 ;
                j ++ ;

            }
        }
        int ans = 0 ;
        int mod = 1e9 + 7 ;
        for(auto x : m) 
        {
            if(x.second >= 2) 
            {   
                bool ok = true ;
                for(int i = 0 ; i < 30 ; i ++ ) 
                {
                    int c = x.first ;
                    if(c & (1 << i) && bit[i] != n)
                    {
                      ok = false; 
                      break ;
                    }
         
                }
                if(ok) 
                {

                }
            }
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