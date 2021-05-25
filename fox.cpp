#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PI 3.1415926535897932384626 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
#define debug(yx,y) cout<<x<<"  "<<y<< endl
#define debugx(x) cout <<"[ "<< x <<" ]"<<endl
int a[6] ={0} ,b[6] ={0};
int cntDi(bool ok,int n)
{
     for( int i= 2;i<=5 && i<=n;i++)
     {
           if(n%i == 0)
           {          
                   int cnt = 0;
                   while(n%i==0)
                   {
                         n/=i;
                         cnt++;
                   }
                if(ok)
                a[i] = cnt ;
                else 
                b[i] = cnt ; 
           }           
    }
    return n;
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
    int n ,m;
    cin >> n >> m;
    int x = cntDi( true, n );
    int y = cntDi( false,m );
    if( x != y)
    {
            cout << "-1";
            return 0 ;
    }
    int ans = abs(a[2] - b[2]) + abs(a[3] - b[3]) + abs(a[5] - b[5]);
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