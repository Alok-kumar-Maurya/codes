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
    int n ;
    cin >> n ; 
    vi v(n);
    for(int i = 0 ; i < n ; i ++)
    {
        cin >> v[i] ;
    }
    vi suf(n ,-1) ;
    if(v[n-1] > 0);
    suf[n-1] = 1 ;
    for(int i = n-2 ; i >= 0 ; i--)
    {
         suf[i] = suf[i-1];
         if(v[i] < 0) 
         suf[i] *= -1;
    }
    vector<pair<int,int>>ans ;
    int pos = 0 , neg = 0;
    for(int i = n-1 ; i >=0 ; i--) 
    {
            if(suf[i] > 0) 
            pos++ ;
            else 
            neg++ ;
            ans[i].first = pos ;
            ans[i].second = neg;
    }
    int total1 = 0 , total2 = 0;
    for(int i = 0 ; i < n ; i++)
    {
          total1 += ans[i].first ;
          total2 += ans[i].second;

    }
    cout << total1 << " "<< total2 ;
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