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
int n ,  m ,k ;
bool ok ;
int srt_x , srt_y , end_x , end_y;
vector<vector<int>> adj;
struct cell
{
    int x , y , cnt ;
};
int dx[] = { 0 , -1 , 0 , 1} ;
int dy[] = { 1 , 0 , -1 ,0} ;
bool checker(int x ,int y) 
{
    if( x >= 0 && x < n && y >= 0 && y < m && adj[x][y] ) 
    return true ;
    return false ;
}
void bfs(int x ,int y)
{
    queue<cell> que ;
    int path = 0;
    for(int i = 0 ; i < 4  ; i++) 
    {
        if(checker(dx[i] + x , dy[i] + y)) 
        path  ++ ;
    }
    path = (  path >= 2 ? 1 : 0 ) ;
    que.push({ x , y , path});
    while(que.size()) 
    {
        auto top = que.front() ;
        que.pop() ;
        //debugx(top.cnt);
        for(int i = 0 ; i < 4 ; i++) 
        {
            int newx = top.x + dx[i] ;
            int newy = top.y + dy[i];
            if(checker(newx ,newy)) 
            {         
                    path = 0;
                    if(newx == end_x && newy == end_y && top.cnt == k) 
                    {
                          ok   = true ;
                    }
                    adj[newx][newy] = 0 ;
                    for(int i = 0 ; i < 4 ; i ++) 
                    {
                       if(checker(dx[i] + newx ,dy[i] + newy) )
                       path ++;
                    }
                    path = (  path >= 2 ? 1 : 0 ) ;
                    que.push({newx,newy , top.cnt + path});
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
        cin >> n  >> m ;
        ok = false ;
        adj.resize(n , vi ( m , 1 ));
        for(int i = 0 ; i < n ; i ++) 
        {
            for(int j = 0 ; j < m ; j ++) 
            {
                char c ;
                cin >> c ;
                if( c == 'X' )
                {
                   adj[i][j] = 0 ;
                }
                else if( c == 'M' ) 
                {
                   adj[i][j] = 0 ;
                   srt_x = i ; 
                   srt_y = j;
                }
                else if( c == '*') 
                {
                   adj[i][j] = 1 ;
                   end_x = i ; 
                   end_y = j;
                }
        
            }
        }
        cin >> k;
        bfs(srt_x , srt_y);
        adj.clear(); 
        if(ok) 
        cout <<"Impressed\n" ;
        else 
        cout <<"Oops!\n";

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