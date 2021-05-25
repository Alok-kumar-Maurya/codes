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
    int t ;
    cin >> t ;
    while(t--) 
    {
        int a ,b , n ;
        cin >> a >> b >> n ;
        vi x(n) , y(n);
        for(int i = 0 ; i < n ; i ++) 
        {
            cin >> x[i];
        }
        for(int i = 0 ; i < n ; i ++) 
        {
            cin >> y[i];
            y[i] =  ceil( y[i] / float(a)) ;
        }
        bool  ok = true ;
        vector<pair<int,pair<int,int>>> v ;
        for(int i = 0 ; i < n ; i ++ )
        {
            v.push_back({y[i] * x[i] , {x[i] , y[i]}}  ) ;
        }
        sort(v.begin() , v.end() ) ;
        for(int i = 0 ; i < n - 1; i ++)  
        {
            b -= ( v[i].first ) ;
            if( b <= 0) 
            {
               ok = false ;
               break ;
            }
        }
        if(ok)
        { 
             int fight = v[n-1].second.second ;
             int did = ceil( float(b) / v[n-1].second.first) ;
             if( fight > did ) 
             ok = false;
        }
        if(ok) 
        cout <<"YES\n";
        else
        cout <<"NO\n";

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