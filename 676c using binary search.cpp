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
string s ;
int k , n;
bool maximum_beauty(int mid ,int fre[][2]) 
{  
     int maxii = 0 ;
     for(int i = 0 ; i <= s.length() - mid ; i ++)
     {
          if( i == 0)
          {     
                maxii = max (fre[mid - 1][0] , fre[mid - 1][1] ) ;
                if( mid - maxii <= k )
                return true ;
          }
          else 
          {    
                int c = fre[i + mid - 1][0] - fre[i - 1][0] ;
                int d = fre[i + mid - 1][1] - fre[i - 1][1]; 
                maxii = max ( c ,d) ;
                if( mid - maxii <= k) 
                return true ;
          }
     }
     return false;
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
    cin >> n >> k ;
    int fre [n][2] = {0};
    cin >> s;
    if( s[0] == 'a') 
    fre[0][0] ++ ;
    else 
    fre[0][1] ++;
    for(int i = 1 ; i < s.length() ; i ++)
    {
        fre[i][0] =  fre[i - 1][0] ;
        fre[i][1] =  fre[i - 1][1] ;
        if( s[i] == 'a') 
        fre[i][0] ++ ;
        else 
        fre[i][1] ++;
    }
    int l = 1 , r = n ,ans= 1;
    while( l <= r)
    {        
            int  mid = l + (r - l) / 2;
            if( maximum_beauty( mid , fre))
            {
                ans = max( ans , mid) ;
                l = mid + 1 ;
            }
            else 
            {
                r = mid - 1 ;
            }

    }
    cout << ans << endl;
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