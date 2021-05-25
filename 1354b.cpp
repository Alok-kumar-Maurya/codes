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
        string s ;
        cin >> s ;
        int cnt3 = -1 , cnt2 = -1  ,n  = s.length() ;
        int two[n][2] = { } , three[n][2] = { };
        memset(two , -1 ,sizeof(two)) ;
        memset(three , -1 ,sizeof(three)) ;

        for(int i = 0 ; i < n ; i ++)
        {   
            if(s[i] == '1') 
            {
                two[i][0] = cnt2 ;
                three[i][0] = cnt3 ;
            }
            if(s[i] == '2')
            cnt2 = i ;
            if(s[i] == '3') 
            cnt3 = i ;
        }
        cnt2 = -1 ,cnt3 = -1;
        for(int i = n - 1 ; i >= 0 ; i --)
        {   
            if(s[i] == '1') 
            {
                two[i][1] = cnt2;
                three[i][1] = cnt3;
            }
            if(s[i] == '2')
            cnt2 = i ;
            if(s[i] == '3') 
            cnt3 = i ;
        }
        int ans = INT32_MAX ;
        for(int i = 0 ; i < n ; i ++)
        {
                if(s[i] == '1' && (two[i][0] != -1 && three[i][0] != -1) )
                {
                    ans = min (ans , i - min(two[i][0] , three[i][0]) ) ;
                }
                if(s[i] == '1' && (two[i][1] != -1 && three[i][1] != -1))
                {   
                    ans = min (ans ,  max(two[i][1] , three[i][1]) - i ) ;
                }
                if(s[i] == '1' && (two[i][0] != -1 && three[i][1] != -1)) 
                {
                    ans = min( ans , three[i][1] - two[i][0] ) ;
                }
                if(s[i] == '1' && (two[i][1] != -1 && three[i][0] != -1))
                {
                    ans = min( ans , two[i][1] - three[i][0] ) ;
                }
        }
        cout << ( ans == INT32_MAX ? 0 : ans + 1 )<< endl;
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