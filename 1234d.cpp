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
string st ;
vector<vector<int>> tree ;
vi ans;
void sum(int s , int r , int qe  , int qr , int idx) 
{
    if(qe > qr )  
       return ;                                                 ///// using segment tree
    if( s == qe && r == qr) 
    {   
        for(int i = 0 ; i < 26 ; i ++) 
        ans[i] += tree[idx][i];
        return ;
    }
    int m = ( s + r ) / 2 ; 
    sum(s , m , qe , min ( qr , m) , 2 * idx) ;
    sum(m + 1 , r , max( qe , m + 1) , qr , 2 * idx + 1) ;
}
void build(int s, int e , int idx )
{
        if(s == e) 
        { 
           tree[idx][st[s] - 'a'] ++;
           return  ;
        }
        int m = (s + e) /2 ;
        build(s , m , 2 * idx ) ;
        build( m + 1 , e , 2 * idx + 1 );

        for(int i = 0 ; i < 26 ; i ++ ) 
        tree[idx][i] = tree[2 * idx ][i] + tree[2 * idx + 1][i];
}
void update( int pos ,char val , int s ,int e ,int idx  )
{
         if(s == e) 
         {   

             tree[idx][st[pos] - 'a'] -- ;
             st[pos] = val;
             tree[idx][val - 'a'] ++ ;
             return ;
         }
         int m = (s + e) /2 ;
         if(pos <= m)  
            update(pos , val , s , m , 2 * idx  );
         else 
            update(pos , val , m + 1 , e , 2 * idx + 1 );
        
        for(int i = 0 ; i < 26 ; i ++ ) 
        tree[idx][i] = tree[2 * idx ][i] + tree[2 * idx + 1][i];
         
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
    int q ;
    cin >> st >> q;
    int n = st.length();
    tree.resize(4 * n + 1 , vi (26 , 0)) ;
    build(0 , n -1 , 1 );
    
    while(q -- )
    {
        int a ;
        cin >> a ; 
        if ( a == 1) 
        {    
             int pos ;
             char val ;
             cin >> pos >> val; 
             update(pos -1 , val ,0 , n - 1 , 1);
        }
        else 
        {   
            int l , r ;
            cin >> l >> r ; 
            ans.resize(26 , 0);
            sum(0 , n - 1 , l - 1 , r - 1 , 1 ) ;
            int cnt = 0 ;
            for(int i = 0 ; i < 26 ; i ++) 
            {
                if(ans[i] > 0) 
                cnt ++ ;
            }
            cout << cnt << endl;
            ans.clear();
        }
                   

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