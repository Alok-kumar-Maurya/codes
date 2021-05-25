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
    int n , k;
    priority_queue<int> pq ;

    cin >> n >> k;
    int copy = n, mask = 0 ,max_k = 0 , min_k = 0;
    while (copy)
    {
         if( copy & 1 ) 
         { 
            max_k += (1 << mask);
            min_k ++;
            pq.push( 1 << mask );
         }
         copy >>= 1 ;
         mask++;
    }
    if ( min_k <= k && max_k >= k)
    {
                 while ( pq.size() != k )
                 {
                     int top = pq.top() ;
                     pq.pop();
                     top >>= 1;
                     pq.push( top ); 
                     pq.push( top );
                 }
                 cout << "YES" << endl;
                 while ( pq.size() )
                 {
                     cout << pq.top() << " ";
                     pq.pop();
                 }
                 
    }
    else 
    {
        cout << "NO" ;
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