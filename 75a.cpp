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
int without_zro(string s ) 
{    
    int ans = 0 ;
    for(int i = 0; i < s.length() ;i ++ )
    {
        if(s[i] != '0') 
        {
             ans = ans*10 + (int)(s[i] - '0');
        }
    }
    return ans ;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output3.txt","w",stdout);
    int a , b ;
    cin >> a >> b ;
    string s1 , s2 ;
    s1 = to_string (a) ;
    s2 = to_string (b);
    int x = without_zro(s1) ;
    int y = without_zro(s2);
    string s3 = to_string(a + b);
    if( without_zro(s3) == x + y )
    cout <<"YES\n" ; 
    else 
    cout <<"NO\n";
    #endif
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