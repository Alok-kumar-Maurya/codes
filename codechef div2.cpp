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
    int t ;
    cin >> t;
    while(t--)
    {    
         
        int n , l ,r ,ans= 0,find =0 ,cnt =0;
        cin >> l >> r >> n;
        for(int i = 0;i<=n;i++)
         {
             if((l^i) < (r^i))
             cnt++;
         }
      
         if( l > r) 
          {        
                  int  j = 0;
                  while (find < l) 
                  {
                      find= 1 << j;
                      j++;
                  }
                  find = find >>1 ;
                  if(find == 0) 
                  {
                    find = 1;
                  } 
                  int b = (n+1) / find;
                  if(b%2 != 0)
                  ans = (n+1) % find;
                  ans += ((b/2) * find);

          }
          else if( l< r)
          {
                 int  j = 0;
                  while (find < r) 
                  {
                      find = 1 << j;
                      j ++;
                  }
                  find = find >> 1 ;
                  if(find == 0) 
                  {
                        find = 1;
    
                  } 
                  int b = (n+1)/find;
                  if(b%2 == 0)
                  ans = (n+1) % find;
                  ans += (((b+1) / 2) * find);
          } 
          cout << ans <<" "<<cnt <<endl;
    }
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