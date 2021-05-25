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
    int t;
    cin >> t ;
    while (t--) 
    {
        int n , m ; 
        cin >> n >> m;
        vector<vector<int>> adj( n , vi (m ,0)) ;
        int num = 1;
        for(int i =0 ; i < n ; i++)
        {
            for(int j = 0 ; j <m ;j ++)
            {
                char c ;
                cin >> c ;
                if(c == '*') 
                {
                    adj[i][j] = num ;
                    num++;
                }
            }
       }
       int ans = 0 ;
       for(int i = 0 ; i < n ; i++) 
       {
           for(int j = 0 ; j < m ; j++)
           {
               if(adj[i][j]) 
               {      
                     int l = 1;
                     bool ok = true ;
                    for(int k = 0 ; k < n-i && ok; k++)
                    {
                       if( (i+k)>=0 && (j-k) >= 0 && (i+ k) <n && (j + k) < m)
                       {
                           int c = adj[i+k][j+k] - adj[i+k][j-k] + 1;
                           if(c == l)
                           ans++;
                           else 
                            {
                                ok = false ;
                                break;
                            }
                            l += 2;
                       }
                       else 
                       break;
                    }
            
                }
           }
       } 
       cout << ans << endl;
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