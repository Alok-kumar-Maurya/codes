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
    vi cost(n + 1);
    for(int i = 1 ; i <= n ; i ++ ) 
    {
        cin >> cost[i];
    }
    set<pii> v;
    for(int i = 0 ; i < m; i ++ ) 
    {
       int a , b ;
       cin >> a >> b ;
       if(a > b) 
       swap(a , b);
       v.insert({a, b}) ;
    }
    int ans = INT32_MAX;
    for(auto it = v.begin() ; it != v.end() ; it ++)
    {   
        auto temp = it; 
        temp ++ ;
        for(auto it2 = temp ; it2 != v.end() ; it2 ++ ) 
        {
            if(it->first == it2->first ) 
            { 
                 int c = it->second ;
                 int d = it2->second ;
                 if(c > d ) 
                 swap( c , d ) ;
                 if(v.find({c,d}) != v.end()) 
                 ans = min ( ans , cost[it->first] + cost[c] + cost[d] ) ; 
            }
            else if(it->second == it2->second) 
            {
                 int c = it->first ;
                 int d = it2->first ;
                 if(c > d ) 
                 swap( c , d ) ;
                 if(v.find({c,d}) != v.end()) 
                 ans = min ( ans , cost[it->second] + cost[c] + cost[d] ) ; 
            }
        }
    }
    cout << (ans == INT32_MAX ? -1 : ans ) ;
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