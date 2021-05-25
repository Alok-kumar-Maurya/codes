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
    int n = s.length() ,ans = 0 ,arr[26] ={};
    for(int i = 0 ; i < n ;i ++) 
    {
       arr[s[i] - 'a'] ++ ;
       ans = max(ans, arr[s[i] - 'a']) ;
    }
    for(int i = 0 ; i < 26 ;i ++) 
    {    
             char a = char(97 + i) ;
        for(int j = 0 ; j < 26 ; j ++) 
        {     
             char b = char(97 + j) ;
             int cnt = 0 , cnt2  = 0;
             for(int  k = 0 ; k < n ; k ++) 
             {
                 if(s[k] == a) 
                 cnt ++ ;
                 else if(s[k] == b) 
                 cnt2 += cnt ;
             }
             if( a == b) 
             {  
                cnt -- ;
                ans = max(ans , cnt * ( cnt + 1) / 2) ;
             }
             else
                ans = max(ans , cnt2) ;
            
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