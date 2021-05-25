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
map<int,int> mp ;
string ans ;
void set_ans( int n , vector<int> v  , int done , int extra) 
{
        for(int i = 0 ; i < n ; i ++)
        {
            if(mp[v[i]] == 1 && done )
            {
               ans += 'A';
               done -- ;
            }
            else if(mp[v[i]] == 1 )
            ans += 'B' ;
            else 
            ans += 'A';
          
        }
        if(extra)
        for(int i = 0 ; i < n ; i ++) 
        {
            if(mp[v[i]] >= 3) 
            {   
                ans[i] = 'B';
                break ;

            }
        }
        
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
    int n ;
    cin >> n ;
    vi v ;
    for(int i = 0 ; i < n ; i ++)
    {    
         int a ;
         cin >> a ;
         v.push_back(a) ;
         mp[a] ++ ;
    }
    int cnt1 = 0 , cnt = 0 ;
    for(auto x : mp) 
    {   
        if(x.second == 1)
        cnt1 ++ ;
        else if( x.second >= 3)
        cnt ++ ;
    }
    bool ok = false  ;
    if( cnt1 % 2 == 0) 
    {
        ok = true ;
        set_ans( n , v , cnt1 / 2 , 0) ;
    }
    else if( cnt )
    {
        ok = true ; 
        set_ans( n , v , (cnt1 + 1 ) / 2 , 1 ) ;
    }
    if( ok ) 
       cout << "YES\n" << ans << endl;
    else 
       cout <<"NO";
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