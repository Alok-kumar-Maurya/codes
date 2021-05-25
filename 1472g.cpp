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
vector<vector<int>> adj;
vi dis;
void dis_cal(int cur)
{     
    queue<int> q;
    q.push(0);
    dis[0] = 0;
    while(q.size())
    {
        auto top = q.front();
        q.pop() ;
        for(auto x : adj[top]) 
        {
            if(dis[x] == INT16_MAX) 
            {
                dis[x] = dis[top] + 1 ;
                q.push( x );
            }
        }
    }
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
    int t ;
    cin >> t ;
    while(t--)
    {
        int n , m ; 
        cin >> n >> m ;
        adj.resize(n);
        dis.resize(n , INT16_MAX);
        for(int i = 0 ; i < m ; i++)
        {
            int a , b ;
            a-- ,b--;
            cin >> a >> b ;
            adj[a].push_back(b); 
        }
        dis_cal(0);
        adj.clear();
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