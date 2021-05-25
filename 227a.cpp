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
vi parent,rnk,vis ;
int find(int a )
{ 
    if(parent[a] == -1)
    return a ;
    parent[a] = find (parent[a]) ;
    return parent[a] ;
}
void unite(int a , int b)
{
    int s1 = find(a) ;
    int s2 = find(b) ;
    if(s1 == s2) 
    return ;
    if( rnk[s1] > rnk[s2])
    {
              parent[s2] = s1 ;
              rnk[s1] += rnk[s2];
    }
    else
    {
             parent[s1] = s2 ;
             rnk [s2] += rnk[s1] ;
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
    parent.resize(m+1 , -1) ;
    vis.resize(m+1,0);
    int cnt = 0;
    rnk.resize(m+1 , 1) ;
    for(int i = 0 ; i < n ; i++)
    {
        int a ;
        cin >> a ;
        vi store ;
        if(a == 0) 
        cnt++;
        while (a--)
        { 
            int lng ; 
            cin >> lng ;
            vis[lng] = 1;
            store.push_back(lng) ;             
        }
        int si = store.size();
        for(int j = 0 ; j < si -1 ; j++)
        {
            unite(store[j] , store[j+1]);
        }
        
    }
    int cnt2 = 0 ;
    for(int i = 1 ; i <= m ; i++) 
    {
        if (parent[i] == -1 && vis[i])
        cnt2++;
    }
    cout << cnt + max( (int)0 , cnt2-1) << endl;
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