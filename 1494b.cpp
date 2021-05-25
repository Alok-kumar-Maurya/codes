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
#define endl  "\n" 
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
    while( t -- ) 
    {
        int n , u , r , d , l ;
        cin >> n ;
        int a[4] ;
        for(int i = 0 ; i < 4 ; i ++ ) 
        cin >> a[i] ;
        bool final_ans = false;
        for(int i = 0 ; i < 4 ; i ++) 
        {
            int temp[4] ;
            bool ok = true ;
            for(int j = 0 ; j < 4 ; j ++) 
            temp[j] = a[j] ;
            for(int j = 0 ; j < 4 ; j ++)
            {
                if(temp[ ( i + j ) % 4] && temp[ ( i + j + 1) % 4 ]) 
                {
                    temp[( i + j) % 4] -- ;
                    temp[( i + j + 1) % 4] --;
                }
            }
            for(int j = 0 ; j < 4 ; j ++) 
            {
                if(temp[j] > n - 2) 
                ok = false ;
            }
            if(ok) 
            {
               final_ans = true ;
               break ;
            }
        }
        if( final_ans) 
        cout <<"YES\n" ;
        else 
        cout <<"NO\n" ;
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