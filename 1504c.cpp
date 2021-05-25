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
void solve()
{
    int n ;
    string s ;
    cin >> n >> s ; 
    int one = 0 , zero = 0 ; 
    for(int i = 0 ; i < n ; i ++ ) 
    {
        s[i] == '1' ? one++ : zero ++ ; 
    }
    // cout << one << zero << endl ;
    if( one % 2 != 0 || zero  % 2 != 0 || s[n - 1] == '0' ||  s[0] == '0')
    {
        cout << "NO\n" ;
        return ;
    }
    string a , b ;
    int c1 = 0 , k = 1 ;
    for(int i = 0 ; i < n ; i ++ ) 
    {
        if(s[i] == '1')
        {
            if(c1 < one / 2) 
            {
                a += '(' ;
                b += '(' ;
            }
            else
            {
                a += ')' ;
                b += ')' ;
            }
            c1 ++ ;
        }
        else 
        {
            if(k) 
            {
                a += '(' ;
                b += ')' ;
            }
            else
            {
                a += ')' ;
                b += '(' ;
            }
            k = 1 - k ;
        }
    }
    cout << "YES\n" << a << endl << b << endl;
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
    int t ;
    cin >> t ;
    while(t -- ) 
    {
        solve();
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