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
    for(auto &x : v)
    cin >> x ;
    map<int,int> m ;
    for(int i = 0 ; i < n ; i++) 
    {
        if(v[i] == 4) 
        m[4] ++ ;
        if(v[i] == 8 )
        {
            if(m[4] - 1 >= m[8]) 
            m[8]++;
        }
        if(v[i] == 15)
        {
            if(m[8] - 1 >= m[15]) 
            m[15]++;
        }
        if(v[i] == 16)
        {
           if(m[15] - 1 >= m[16]) 
            m[16]++;
        }
        if(v[i] == 23)
        {
            if(m[16] - 1 >= m[23]) 
            m[23]++;
        }
        if(v[i] == 42)
        {
            if(m[23] - 1 >= m[42]) 
            m[42]++;
        }    
    }
    cout << n - m[42] * 6 ;

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