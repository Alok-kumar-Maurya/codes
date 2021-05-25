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
bool sum_check(int x , int i) 
{  
    int sum = 0 ;
    while(x) 
    {
        sum += x % 10 ;
        x /= 10 ;
    }
    if(sum == i) 
    return true;
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
    int n ;
    cin >> n ;
    int ans = INT32_MAX;
    for(int i = 1 ; i <= 279 ; i ++)
    {
            int c = i*i + 4*n ;
            double a = sqrt(c) ;
            c = sqrt(c) ;
           // debugxy(a , c);
            if( a == c) 
            {
                int x1 = (-i + a )/ 2 ;
                if(x1 > 0 && sum_check(x1 , i) ) 
                ans = min ( ans ,x1) ;
            }  
        
    }
    if( ans == INT32_MAX ) 
    cout <<"-1" ;
    else 
    cout << ans ;

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