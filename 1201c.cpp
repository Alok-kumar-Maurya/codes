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
    int n , k ;
    cin >> n >> k ;
    vi v(n) ;
    for(int  i = 0 ; i < n ; i ++) 
    cin >> v[i] ;
    sort(v.begin() , v.end()) ;
    map<int,int > m ;
    for(int i = n/2 ; i < n ; i ++)
    m[v[i]] ++ ;
    int middle = v[ n / 2] ;
    for(auto it = m.begin() ; it != m.end() ; it ++)
    {   
         auto it2 = it ;
         it2 ++ ;
         if(it2 == m.end()) 
         break ;
         int x = (it2->first - it->first) * it->second ;
         if( x <= k)
         {
               k -= x ;
               m[it2->first] += it->second ;
               middle = it2->first;
         }
         else 
         {
                middle += k / it->second ;
                k = 0;
         }
     }
         middle += k / ( (n+1)/2) ;
         cout << middle << endl;
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