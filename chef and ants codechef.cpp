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
bool mycomp(pii a ,pii b)
{
    int dis1 = abs(a.first) ;
    int  dis2 =  abs(b.first);
    return dis1 < dis2 ;
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
        int n ; 
        cin >> n ;
        vector<pair<int,int>> v(n) , dis ;
        for(int i = 0 ; i < n ; i ++) 
        {
            int m , pos = 0 , neg = 0;
            cin >> m ;
            while(m--)
            {
                int a ;
                cin >> a ;
                if(a >= 0)
                pos++ ;
                else 
                neg++ ;
                dis.push_back({a , i});
            }
            v[i] = {pos ,neg} ;
        } 
        sort(dis.begin() , dis.end() , mycomp ) ;
        bool ok  = false ;
        int ans = 0 ;
        for(int i = 0 ; i < dis.size() ; i ++) 
        {  
            if(abs(dis[i].first) == abs(dis[i+1].first))
            {
                 ok = true ;
                 int index = dis[i].second ;
                 if(dis[i].first > 0)
                 { 
                     ans += ( -- v[index].first ) ;
                 }
                 else 
                 {
                     ans += ( -- v[index].second ) ;
                 }

            }
            else if(abs(dis[i].first) != abs(dis[i+1].first) && ok )
            {
                 int index = dis[i].second ;
                 if(dis[i].first > 0)
                 { 
                    ans += ( -- v[index].first ) ;
                 }
                 else 
                 {
                    ans += ( -- v[index].second ) ;
                 }
                 ok  = false ;
                 ans ++ ;
            }
            else if(abs(dis[i].first) != abs(dis[i+1].first))
            {
                int index = dis[i].second ;
                if(dis[i].first > 0)
                 { 
                    ans  += ( v[index].second ) ;
                    v[index].first -- ;                
                 }
                 else 
                 {
                    ans += ( v[index].first ) ;
                    v[index].second -- ;
                 }
            }
        }
        cout << ans << endl;
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