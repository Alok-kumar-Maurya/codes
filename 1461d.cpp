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
vi a ,pre_sum;
set<int> s; 
void fun(int start ,int end)
{    
    if(start == end )
    { 
        s.insert(a[start]);
        return ;
    }
    int mid = (a[start] + a[end])/2 ;
    auto x  = upper_bound(a.begin() , a.end() , mid) ;
    if(a[start] == a[end]) 
    {
       return ;
    }
    int index = x - a.begin() ;
    if(start == 0)
        s.insert(pre_sum[index - 1 ]);
    else if(start != 0) 
        s.insert( pre_sum[index -1] - pre_sum[start - 1] ) ;

    s.insert(pre_sum[end] - pre_sum[index -1]);

    fun(start , index - 1) ;
    fun(index , end ) ;
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
        int n ,sum;
        cin >> n >> sum ;
        pre_sum.resize(n) ;
        a.resize(n);

        for(auto &x : a)
        cin >> x ;

        sort(a.begin() , a.end()) ;
        pre_sum[0] = a[0] ;
        for(int i =1 ; i< n ; i++) 
        {
            pre_sum [i] = pre_sum[i-1] + a[i];
        }
        fun(0 , n-1);
        s.insert(pre_sum[n-1]);
        for(int i = 0 ; i < sum ; i++)
        {  
            int b ;
            cin >> b ;
            if(s.find(b) != s.end())
            cout <<"Yes\n" ;
            else 
            cout <<"No\n";
        }
        a.clear() ;
        pre_sum.clear();
        s.clear(); 
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