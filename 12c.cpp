#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PI 3.1415926535897932384626 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n,m;
    cin >> n >> m;
    vi v(n),ne;
    for(auto &x : v)
    cin >> x;
    map<string,int> ma;
    while (m --)
    {
        string s;
        cin >> s;
        ma[s] ++;
    }
    for(auto x : ma)
    ne.push_back( x.second ) ;
    sort(v.begin(),v.end());
    sort(ne.begin(),ne.end());
      
    int min = 0 ,max = 0;
    for( int i = 0 ; i < ne.size();i++) 
    {
         min+=(ne[ne.size()-1-i]*v[i]);
         max+=(ne[ne.size()-1-i]*v[n-1-i]);
    }
    cout << min <<" "<< max;
    

    
 return 0;
// THINGS TO KEEP IN MIND
//   * int overflow, time and memory limits
//   * Special case (n = 1?)
//   * Do something instead of nothing and stay organized
//   * Don't get stuck in one focus
//   * int l=s.length()-x (s.length()<x) runtime error
// TIME AND MEMORY LIMITS
//   * 1 second is approximately 10^8 operations (c++)
//   * 10^6 Elements of 32 Bit (4 bytes) is equal to 4 MB
//   * 62x10^6 Elements of 32 Bit (4 bytes) is equal to 250 MB
//   * 10^6 Elements of 64 Bits (8 bytes) is equal to 8 MB
//   * 31x10^6 Elements of 64 Bit (8 bytes) is equal to 250 MB
}