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
#define mod 998244353
int fast_po(int a ,int b)
{
     int ans = 1 ;
     while(b)
     {                        
          if(b % 2 == 0) 
          {
             a = (a * a ) % mod ;
             b /= 2 ;
          }
          else 
          {
               ans = (ans * a ) % mod;
               b-- ;
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
    freopen("output.txt","w",stdout);
    #endif
    

    int a[10] = {1,2,3} ;
   
     return 0;
}