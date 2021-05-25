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
int memot[1005][1005];
int lps(int l ,int r , string s) 
{   
    if(l >  r) 
        return 0;
    if(memot[l][r] != -1) 
        return memot[l][r] ;
        debugxy( l , r);

    if(s[l] == s[r]) 
    {    
        if(l == r)
        memot[l][r] = 1+ lps(l+1 , r-1 , s); 
        else 
        memot[l][r] = 2+ lps(l+1 , r-1 ,s);
    }
    else 
    {                                                                       // // top down 
        memot[l][r] = max(lps(l+1 , r , s ) ,lps (l , r-1 , s ) );
    }
    return memot[l][r];
}
int lps(string s)
{
        int n = s.length() ;
        int dp[n][n] ;
        memset(dp , 0 , sizeof(dp));

        for(int k = 0 ; k < n ; k ++ ) 
        {    
           int i = 0 ;
           for(int j = k ; j < n ; j ++ , i++)
            {    
                   
                if( i == j ) 
                {
                    dp[i][j] = 1 ;
                    continue;
                }                                   /// bottom up dp
                if(s[i] == s[j])
                { 
                   dp[i][j] =  2 + dp[i+1][j-1] ; 
                }
                else
                {
                    dp[i][j] = max(dp[i+1][j] , dp[i][j-1] ) ;
                }
            }
       }
    //   
       return dp[0][n-1];
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
       
        string s ;
        cin >> s;
        memset(memot, 1 ,sizeof(memot));
        cout << lps(s) ;
       // cout << lps( 0 , s.length()-1 , s) ;
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