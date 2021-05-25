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
    int n , k1 ,k2;
    cin >> n >> k1 >> k2 ;
       
    vi va(n);
    for( auto &x: va)
    {
           cin >> x;
    }
    priority_queue<int>pq;
    for(int i = 0 ; i < n;i++)
    {
        int a ;
        cin >> a;
        pq.push(abs(va[i]-a));
    }
    int k = k1 + k2;
    //int l=-1;
    for( int i = 0 ; i< k ; i++)
    {
         int top = pq.top();
         pq.pop();
         pq.push(abs(top-1));
    }

    int ans = 0;
    while ( !pq.empty())
    {
         ans+=(pq.top()*pq.top());
         pq.pop();
    } 
         cout << ans;
         
    

    
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