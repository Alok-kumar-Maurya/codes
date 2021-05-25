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
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree <long int, null_type, less<long int>, rb_tree_tag,tree_order_statistics_node_update > ordered_set;  
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n ;
    ordered_set s ;
    cin >> n ;
    vpii a(n) ;
	vi b(n);
    for(int i = 0; i < n ; i ++ ) 
	{
		cin >> a[i].first ; 
		a[i].second = i ; 
	}
	for(auto &x : b)
	{
		cin >> x ;
	}
	sort(a.begin() , a.end()) ;
    vi ans(n) ;
    for(int i = n - 1 ; i >= 0 ; i -- )
    { 
		   int x = a[i].second ;
           s.insert(x) ;
           int idx = s.order_of_key(x);
           int sz = s.size() ;
           if(sz - idx >= b[x]) 
           {
                 int l = *s.find_by_order(idx) ;
                 int r = *s.find_by_order(idx + b[x] - 1 ) ;
                 ans[x] = r - l + 1 ;
           }
           else 
           ans[x] = -1 ;

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