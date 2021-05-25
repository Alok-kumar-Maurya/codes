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
        int n , m ;
        cin >> n >> m ;
        vi one ,two , v(n);
        for(int i = 0 ; i < n ; i ++)
        {
             cin >> v[i] ;
        } 
        for(int i = 0 ; i < n ; i ++)
        {
            int a ;
            cin >> a;
            if(a == 1) 
            one.push_back(v[i]);
            else 
            two.push_back(v[i]);
            
        }
        sort(one.begin() , one.end() ,greater<int>()) ;
        sort(two.begin() , two.end() , greater<int>()) ;
        int ans = INT32_MAX;
        if(one.size() && one[0] >= m )
        ans = 1 ;
        if(two.size() && two[0] >= m )
        ans = min(ans, (int)2 );
        for(int i = 1 ; i < one.size() ; i++)
        {
            one[i] += one[i-1];
            if(one[i] >= m )
            ans = min ( i + 1 , ans) ;
        }
        for(int i = 1 ; i < two.size() ; i++)
        {
           two[i] += two[i-1]; 
           if(two[i] >= m) 
           ans = min (ans , 2 * (i + 1) ) ;
        }
        for(int i = 0 ; i < one.size() ; i ++) 
        {
               
              int l = 0 , r = (int) two.size() - 1;
              while (l <= r)
               {    
                 //   debugxy(l ,r);
                    int mid = l + ( r - l ) / 2 ;
                    if(two[mid] + one[i] >= m ) 
                    {
                     ans = min ( ans , 2 * (mid + 1 ) +  i + 1 ) ;
                     r = mid - 1;
                    }
                    else 
                     l = mid + 1;
                    
               }
              
        } 
        cout << (ans == INT32_MAX ? -1 : ans ) << endl;
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