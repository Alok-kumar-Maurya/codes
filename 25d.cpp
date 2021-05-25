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
vi parent,rnk;
int find( int a)
{
    if(parent[a] == -1)
    return a;
    return (parent[a] = find(parent[a]));
}
void unite(int a,int b)
{
    int gr1 = find(a);
    int gr2 = find(b);
    if( gr1 == gr2) 
    return ;
    if(rnk[gr1] >= rnk [gr2])
    {
        parent[gr2] = gr1;
        rnk[gr1] += rnk[gr2] ; 
    }
    else 
    {
        parent[gr1] = gr2 ;
        rnk[gr2] += rnk[gr1] ;
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
    int n ;
    cin >> n ; 
    parent.resize(n+1 , -1) ;
    rnk.resize(n+1 ,1);
    queue<pair<int,int>> extra ;
    queue<int> disj;
    for(int i = 1 ; i <= n-1 ; i ++)
    {
        int a , b ;
        cin >> a >> b ;
        int gr1 = find(a) ;
        int gr2 = find(b) ;
        if(gr1 == gr2) 
        {
            extra.push({a,b}) ;  
        }
        else 
        {
            unite( a, b) ;
        }
    }
    int cnt = 0;
    for(int i = 1; i <= n ;i ++) 
    {
       if( parent[i] == -1 ) 
       {
        disj.push(i);
        cnt++ ;
       }
    }
    cnt--;
    cout << cnt << endl;
    while (cnt)
    { 
            auto u = extra.front() ;
            int first = disj.front();
            disj.pop() ; 
            int second = disj.front();
            extra.pop();
            cout << u.first <<" "<< u.second <<" " << first <<" " <<second << endl;
            cnt--;
            
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