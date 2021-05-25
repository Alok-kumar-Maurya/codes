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
    string s ;
    cin >> s ;
    int n = s.length();
    int dp[n][2] = { };
    if(s[n - 1] >= 'a') 
    dp[n - 1][0] ++ ;
    else 
    dp[n- 1][1] ++ ;
    for(int i = n-2 ; i >=0  ; i --) 
    {   
           if(s[i] <= 'Z')
           {
                 dp[i][0] = dp[i + 1][0] ;
                 dp[i][1] = dp[i+1][1] + 1 ;
           }
           else 
           {
                 dp[i][0] = dp[i + 1][0] + 1 ;
                 dp[i][1] = dp[i+1][1] ;
           }
    }
    int ans = INT32_MAX ,cnt = 0;
    for(int i = 0 ; i < n - 1 ; i ++ )
    {
           if(s[i] >= 'a') 
           cnt ++ ;
           ans = min ( { ans , dp[i+1][1] + cnt , dp[i+1][0] + cnt } ) ;
           
    }
    if(s[n-1] >= 'a') 
    {
        cnt ++ ;
        ans = min ( ans , cnt);
    }
    ans = min({ans , dp[0][1] ,dp[0][0]});
    cout << ans;
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