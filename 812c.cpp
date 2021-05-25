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
int n , s;
vi a;
pair<bool , int> Is_possible(int total)
{
    vi v;
    for(int i = 0 ; i < n ; i++)
    {
        v.push_back( (i+1) * total +  a[i] ) ;
    }
    sort( v.begin() , v.end()) ;
    int sum = 0 ,cnt = 0 ;
    for(int  i = 0 ; i <  n ; i++)
    {   
        if(sum + v[i] <= s && cnt < total)
        {
            sum += v[i] ;
            cnt ++ ;
        }
    }
    if(cnt == total) 
    return {true , sum} ;
    return {false , -1};
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif
    cin >> n >> s ;
    a.resize(n);
    for(auto &x : a) 
    cin  >> x ;
    int ans =0 , maxii = 0 , l = 0 , r = 1e6 ;
    while( l <= r) 
    {
        int mid = l + ( r - l) / 2 ;
        //debugx(mid);
        auto it = Is_possible(mid) ;
        if(it.first) 
        {
             if( maxii < mid) 
             {
                 ans = it.second ;
                 maxii = mid ;
             }
             l = mid + 1;
        }
        else 
             r = mid - 1 ;
    }
    cout << maxii << " "<< ans ;
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