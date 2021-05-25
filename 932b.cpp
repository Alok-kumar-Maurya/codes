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
int calculate(int a) 
{
     int product = 1;
     while(a) 
     {
         if(a % 10) 
         product *= ( a % 10); 
         a /= 10 ;
     }
     return product ;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
    vector<vi> ans(1e6 + 1 , vi(10 , 0) ) ;
    for(int i = 1 ; i <= 1e6 ; i ++) 
    {    
         int c = i ;
         while(c >= 10) 
         c = calculate(c);
         ans[i][c] ++ ;
    }
    for(int i = 1 ; i <= 1e6 ; i ++)
    {
          for(int j = 1 ; j <= 9 ; j ++ )
          ans[i][j] += ans[i - 1][j] ;
          
    }
    int q ;
    cin >> q ;
    while (q --)
    {
        int l , r, k ;
        cin >> l >> r >> k ;
        cout << ans[r][k] - ans[l - 1][k] <<endl;
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