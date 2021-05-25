#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PI 3.1415926535897932384626
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
#define debugxy(x, y) cout << "[ " << x << "  " << y << " ]" << endl
#define debugx(x) cout << "[ " << x << " ]" << endl
#define endl "\n"
//#include<ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree <int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update > ordered_set;
int query(int l , int r) 
{  
    int x ;
    cout << "? " << l << " "<< r << endl ;
    cin >> x;
    return x ; 
}
int32_t main()
{  

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
#endif
    
    int n  , ,t , k ;
    cin >> n >>t >>  k ;
    int l = 1 , r = n ;
    while( l <= r ) 
    {
        int m = ( l + r ) / 2 ; 
        int left = ( m - l + 1 ) - query(l , m) ;
        // int right = r - m + 1 - query(m , r) ;
        if(have + left < k) 
        {     
               have += left ;
               l = m + 1;
        }
        else 
        {
               r = m - 1;
        }
    } 
    cout <<"! " << l << endl;
    return 0;
    // THINGS TO KEEP IN MIND
    //   * int overflow, time and memory limits
    //   * Special case (n = 1?)
    //   * Do something instead of nothing and stay organized
    //   * Don't get stuck in one focus
    //   * int l=s.len)gth()-x (s.length()<x) garbage value
    // TIME AND MEMORY LIMITS
    //   * 1 second is approximately 10^8 operations (c++)
    //   * 10^6 Elements of 32 Bit (4 bytes) is equal to 4 MB
    //   * 62x10^6 Elements of 32 Bit (4 bytes) is equal to 250 MB
    //   * 10^6 Elements of 64 Bits (8 bytes) is equal to 8 MB
    //   * 31x10^6 Elements of 64 Bit (8 bytes) is equal to 250 MB
}