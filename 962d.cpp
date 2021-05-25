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
class mycomp 
{
     public :
     bool operator() ( pii a , pii b) 
     {
         if( a.first < b.first) 
         return true ;
         if(a.first == b.first)
         return a.second < b.second ; 
         return false ;
      }
} ;
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int  n ;
    cin >> n ;
    vi v(n) ;
    set <pair<int,int>, mycomp> se;

    for( int  i = 0 ; i < n ; i++ )
    {
       cin >> v[i] ;
       se.insert({v[i] , i}) ;
    } 
    int cnt = 0;
    while(se.size() > 1) 
    {
         
              auto x = *se.begin(); 
              auto y =  *(++se.begin());
              if(x.first == y .first) 
              {
                  v[x.second] = -1 ;
                  cnt ++ ;
                  v[y.second] = 2*x.first ;
                  se.insert({2*x.first , y.second});
                  se.erase(x) ;
                  se.erase(y);
              }
              else 
              {     
                  se.erase(se.begin()) ;
              } 

    }
    cout << n - cnt << endl;
    for(int i = 0 ; i < n ; i ++)
    {
         if(v[i] != -1)
         cout << v[i] <<" ";
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