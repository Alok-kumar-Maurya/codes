#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PI 3.1415926535897932384626 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
#define debugxy(x,y) cout<<"[ "<<x<<"  "<<y<<" ]"<< endl5
#define debugx(x) cout <<"[ "<< x <<" ]"<<endl
vi v;
vector<vector<int>> memot;
int alice_win(int i ,int  j ) 
{
    if( i > j ) 
    return 0 ;
    if(memot[i][j] != -1)
    return memot[i][j];
    if( j == i+1) 
    {
        memot[i][j] = max(v[i] , v[j]) ;
        return memot[i][j];
    }
    memot[i][j] = max( v[i] + min(alice_win(i+2 ,j) , alice_win(i+1 , j-1)) , v[j] + min(alice_win(i+1 ,j-1) , alice_win(i , j-2) ) ) ;
    return memot[i][j];
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
    v.resize(n);
    memot.resize( n , vi ( n , -1));
    for(auto &x :v)
    cin >> x ;
    cout << alice_win(0 , n-1);
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