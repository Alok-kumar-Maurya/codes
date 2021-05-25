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

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
     vector<int> v;

    for (int i = 0; i < 11 ; i++)
        v.push_back(pow(3, i)) ;
    set<int> ans ;
    for(int i = 0 ; i < (1 << 11) ; i ++ ) 
    {      
           int sum = 0 ;
           for(int j = 0 ; j < 11 ; j ++ ) 
           {
               if(i & (1 << j)) 
               {
                   sum += v[j] ;
               }
           }
           ans.insert(sum); 
    }

    int q ;
    cin >> q ;
    while(q -- ) 
    {
        int n ;
        cin >> n ;
        cout << *ans.lower_bound(n)<< endl;
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
