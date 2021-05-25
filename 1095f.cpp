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
vi parent;
int find(int a)
{
        if(parent[a] == -1)
        return a;
        parent[a] = find(parent[a]);   // path compressin
        return parent[a] ; 
}
void unite(int a, int b )
{
       int gr1 = find(a) ;
       int gr2 = find(b) ;
       if(gr1 != gr2)
       {
             parent[gr2] = gr1;
       }
}

class comp 
{
   public:
   bool operator()(pair<pii,int>a , pair<pii,int>b) 
   {
    return b.second < a.second ;
   }
};
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
    cin >>  n >> m ;
    vi price(n+1) ;
    parent.resize(n+1 , -1);
    int mini = INT64_MAX;
    int index = -1;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> price[i];
        if(mini > price[i])
        {      
             index = i ;
             mini = min (mini , price[i]) ;
        }
    }
    priority_queue < pair<pii,int>,vector<pair<pii,int>> , comp > pq ;
    for(int i = 1 ;i <= n ;i++)
    {    
        if(index != i)
        pq.push({{index,i},price[i]+price[index]});
    }

    while(m--)
    {
        int a , b ,w ;
        cin >> a >> b >> w ;
        if(price[a] + price[b] > w) 
        {
            pq.push({{a,b} ,w});
        }
        else 
        {
           pq.push({{a,b} , price[a]+price[b]}) ;
        }
    }
    int ans = 0;
    while (pq.size())
    {
        auto u = pq.top() ;
        pq.pop();
        if(find(u.first.first) != find(u.first.second))
        {
            unite(u.first.first , u.first.second);
            ans += u.second ;
        }
    }
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