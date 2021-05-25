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
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif
    int n ;
    cin >> n ;
    vi v(n) ;
    queue<int> s;
    vpii temp(n , {-1 , -1}) ;
    for(int i = 0 ; i < n ; i ++ ) 
    {
        cin >> v[i];
        if(v[i] == 0) 
           s.push(i);
        else if(s.size() && v[i] == 1)
        {
            temp[i].first = s.front() ;
            s.pop() ;
        }          
    }
    for(int i = n - 1 ; i >= 0  ; i -- ) 
    {
        if(v[i] == 0) 
           s.push(i);
        else if(s.size() && v[i] == 1)
        {
            temp[i].second = s.front() ;
            s.pop() ;
        }          
    }
    int i = 0 ;
    vi check(50010 , -1);
    int ans = 0;
    while(i < n && temp[i].first == -1 ) 
    {    
          if(v[i] == 1) 
          {
              ans += abs ( i - temp[i].second ) ;
              check[temp[i].second] = 1 ;
              v[i] = 0 ;
          }
          i ++ ;
    }
    int j = n - 1;
    while(j >= 0 && temp[i].second == -1) 
    {
          if(v[j] == 1) 
          {
              ans += abs ( j - temp[j].first ) ;
              check[temp[i].second] = 1 ;
              v[j] = 0 ;
          }
          j -- ;
    }
    for(int i = 0 ; i < )
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
