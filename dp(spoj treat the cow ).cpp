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
vi v;
vector<vector<int>>memo ;
int dp(int st , int end )
{
    if(st > end) 
    return 0 ;
    if(memo[st][end] != -1)           //top down 
    return memo[st][end];
    int factr = v.size() - (end - st);
    int profit = max (v[st] * factr + dp(st+1 , end) , v[end] * factr + dp(st , end - 1) );
    memo[st][end] = profit ;
    return profit ;
}
int dp()
{
    int tb[v.size()+1][v.size()+1] ;
    memset(tb ,-1 , sizeof(tb)) ;
    for(int k = 0 ; k < v.size() ; k ++)
    {
        int i = 0 ;
        for(int j = k ; j < v.size() ; i++ , j++)
        {                                                  // bottom up 
            int df = v.size() - ( j - i) ;
            if( i == j)
            tb[i][j] = df * v[i]; 
            else 
            tb[i][j] = max( df * v[i] + tb[i+1][j] , df * v[j] + tb[i][j-1]);
            
        }
    }
    return tb[0][v.size()-1];

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
    v.resize(n) ;
    for(auto &x : v)
    cin >> x ;
    memo.resize(n , vi(n , -1));
    cout << dp() << endl;
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