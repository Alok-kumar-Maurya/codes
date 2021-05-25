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
    freopen("output.txt","w",stdout);
    #endif
    int n ,m;
    cin >> n >> m ;
    vi sw(n) ;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> sw[i] ;
    }
    sort(sw.begin() , sw.end()) ;
    vi a(n);
    a[0] = sw[0] ;
    for(int i = 1 ; i < n ; i ++ )
    {   
        if(i - m < 0 ) 
        a[i] =  sw[i] ;
        else
        a[i] =  sw[i] + a[i - m ] ;

    }
    cout << a[0] <<" ";
    for(int i =  1 ; i < n ; i++) 
    {      
        a[i] = a[i-1] + a[i] ;
        cout << a[i] <<" ";
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