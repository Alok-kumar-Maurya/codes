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
    freopen("output3.txt","w",stdout);
    #endif
    int n ;
    cin >> n ;
    vector<vector<int>> adj( n + 1 ) ;
    for(int i = 2 ; i <= n ; i ++)
    {
        int a ;
        cin >> a ;
        adj[a].push_back(i);
        adj[i].push_back(a);
    }
    queue<pair<int,int>> q ;
    q.push({1 , -1});
    bool ok = true;
    while(q.size())
    {
        auto top = q.front() ;
        q.pop();
        int cnt  = 0 ;
        for(auto x : adj[top.first]) 
        {        
                if(x == top.second ) 
                continue ;
                if( adj[x].size() == 1) 
                cnt ++ ;
                else 
                q.push({x , top.first});
        }
       
        if(cnt < 3) 
        {
          ok = false ;
          break;
        }
    }
    if(ok )
    cout << "yes\n" ;
    else 
    cout<< "no\n";
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