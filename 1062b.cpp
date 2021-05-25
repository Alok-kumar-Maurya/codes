#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PI 3.1415926535897932384626 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
#define debugxy(x,y) cout<<x<<"  "<<y<< endl
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
    int n;
    cin >> n;
    int clone = n;
    int ans = 1 , moves =  0;
    set< int , greater<int>>s;

    for(int i = 2 ; i*i<= n ;i++)
    {
        if(n%i == 0) 
        {    
            int cnt = 0 ;
            while(n%i == 0)
            {
                n/=i ;
                cnt ++;

            }
            ans *= i;
            s.insert( cnt );
        }
    } 
    if( n!=1 ) 
    {
        ans *= n;
        s.insert( 1 );
    }
    int top = *s.begin() ;
    int cnt = 0,cnt1 = 0;
    if( top == 1 || clone == 1) 
    {
     cout << ans << " 0" ;
     return 0 ;
    }
    while ( top ) 
    {
       
       if ( top & 1) 
       cnt1++;
       top = top >> 1;
       cnt ++ ;
    }
   
    if(s.size() > 1)
             {
                   if( cnt1 == 1)
                   moves = cnt  ;
                   else 
                   moves = cnt + 1;
             }
    else if ( cnt1 > 1 ) 
    moves = cnt +1 ;
    else if( cnt1 == 1)
    moves = cnt-1;

    cout << ans << " " << moves  ;


    

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