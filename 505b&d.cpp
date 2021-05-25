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
const int N = 100001 ;
class dsu
{
        vi parent ;
        public: 
        dsu(void);
        int find(int);
        void unite(int ,int) ;
};
dsu::dsu()
{
     parent.resize(105 , -1) ;
}
int dsu::find(int a)
{
        if(parent[a] == -1)
        return a;
        return (parent[a] = find(parent[a])) ;
}
void dsu::unite(int a, int b )
{
       int gr1 = find(a) ;
       int gr2 = find(b) ;
       if(gr1 != gr2)
       {
           parent[gr1] = gr2 ;
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
    vector<dsu> color(N ) ;
    for(int i = 0 ; i < m ; i++)
    {
        int a, b , c ;
        cin >> a >> b >> c;
        color[c].unite(a ,b);
    }
    int q;
    cin >> q ;
    while (q--)
    {
        int u ,v ;
        int ans = 0 ;

        cin >> u >> v;
        for(int i = 1 ; i < N ; i++)
        {
            int gr1 = color[i].find(u) ;
            int gr2 = color[i].find(v);
            if(gr1 == gr2) 
            ans++;
        }
        cout << ans  << endl;
    }
    
 return 0;
// THINGS TO KEEP IN MIND
//   * int overflow, time and memory limits
//   * Special case (n = 1?)AA
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