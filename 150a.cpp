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
    int a , total = 0;
    cin >> a ;
    vi cnt;
    bool ok = true ;
    for(int j = 2 ; j * j <= a ; j++)
    {    
        if(a % j == 0)
        {  
            ok = false ;
            while(a % j == 0)
            {
                   a /= j ;
            }
            cnt.push_back(j);
        }
    }
    if( a != 1)
    cnt.push_back(a);
    int l = cnt.size();
    if( l % 2 == 0 )
    {
            cout <<"1\n" ;
            if(l == 0 || ok )
            cout <<"0\n";
            else
            {  
               int ans = 1 , need_div =  l  / 2;
               for(auto y : cnt)
               {
                    if(need_div == 0) 
                        break ; 
                    ans *= y ; 
                    need_div -- ;
               }
               cout << ans ;
            }
    }
    else 
    cout <<"2\n";
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