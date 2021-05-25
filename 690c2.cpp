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
int total_dis ;
set
int cal_dis(int a ,int par) 
{    
    int to = 0;
    for(auto x : adj[a]) 
    {   
        if( x == par) 
        continue ;
        to  = max(to , cal_dis(x ,a) );
    }
    dis[a] = to + 1;
    return dis[a];
}
void ans_cal(int a ,int par)
{
     multiset<int ,greater<int>> s ;
     for(auto x : adj[a])
     {
         if(x == par) 
         continue ;
         s.insert(dis[x]);
     }
     if(s.size() == 1)
     {
        total_dis = max(total_dis , *s.begin()) ;
     }
     else if(s.size() >= 2)
     {  
        int c  = *s.begin();
        s.erase(s.begin()) ;
        int b = *s.begin();
        total_dis = max(total_dis , c + b) ;
     }
     for(auto x : adj[a]) 
     {
         if(x == par)
          continue ;
         ans_cal(x , a) ;
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
    int n , m ;
    cin >> n >> m ;
    adj.resize(n + 1);
    dis.resize(n + 1);
    total_dis = 0 ;
    while (m--)
    {
        int a , b ;
        cin >> a >> b ;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cal_dis(1 , -1);
    ans_cal(1 ,-1);
    cout << total_dis ;
    
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