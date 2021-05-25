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
bitset<501> a[501];
vector<int> ans(501 , 0) ;
int find_ans(int i ,int m)
{  
   int cnt = 0 , maxi = 0;
   for(int j = 0 ; j < m ; j++) 
   {
        if(a[i][j])
        cnt ++ ;
        else 
        cnt = 0 ; 
        maxi = max( cnt , maxi);
   }
   //cout << endl;
   ans[i] = maxi ; 
   return *max_element(ans.begin() , ans.end());
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
    int n , m ,q; 
    cin >> n >> m >> q ;
    for(int i = 0 ; i < n ; i++  )
    {
        for(int j = 0 ; j < m ; j ++)
        {   
            int b ;
            cin >> b;
            a[i][j] = b ;
        }
    }
    for(int i = 0 ; i < n ; i ++)
    find_ans(i , m);
    while(q--) 
    {
        int i , j ; 
        cin >> i >> j ;
        i-- ; j--;
        a[i][j] = 1 - a[i][j] ;
        cout << find_ans( i , m) << endl;
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