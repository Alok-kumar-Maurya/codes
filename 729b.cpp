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
    cin.tie(0) ;
    cout.tie(0) ;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin) ;
    freopen("output.txt","w",stdout) ;
    #endif
    int n , m ;
    cin >> n >> m ;
    int b = 0;
    int a[n+1][m+1] , ver[n+1][m+1] = {0} , hor[n+1][m+1] = {0}; 
    for(int i = 1 ; i <= n ; i ++)
    {
        for(int j =1 ; j <= m; j++) 
        {
            cin >> a[i][j] ;
            if(a[i][j] == 1) 
            b++;
            hor[i][j] = b;

        } 
    }
    b = 0 ;
    int ans = 0 ;
    for(int i = 1 ; i <= m ; i ++)
    {      
          bool l = 0;
        for(int j = 1 ; j <= n; j++) 
        {
            if(a[j][i] == 1) 
            {
               b++;
               l = 1;
            }
            else if(l) 
            ans ++ ;
            ver[j][i] = b;

        } 
    }
    for(int i = 1 ; i <= n ; i ++)
    {  
        bool l = false;
        for(int j = 1 ; j <= m; j++) 
        { 
            if( a[i][j] == 0)
            {
                if(hor[i][j] != hor[i][m] )
                ans ++ ; 
                if( ver[i][j] != ver[n][j] ) 
                ans ++ ; 
                if(l) 
                ans ++ ;
            }
            else 
            l = true;
        } 
    } 
    cout << ans  << endl;
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