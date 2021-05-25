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
    freopen("output1.txt","w",stdout);
    #endif
    int q ;
    cin >> q ;
    for(int t = 1 ; t <= q ; t ++ ) 
    {
        int n , c ;
        cin >> n >> c ;
        int l = ( n * ( n + 1) ) / 2 - 1;
        vi v(n);
        if(c > l || c < n - 1) 
        {
            cout <<  "Case #"  << t << ": IMPOSSIBLE" << endl;
            continue ;
        }
        for(int i = 0 ; i < n ; i ++ ) 
        v[i] = i + 1 ;

        if( c != n - 1) 
        {   
            swap(v[0] , v[1]) ;
            do
            {    
               int x = 0 ; 
               vi temp = v ;
               for(int i = 0 ; i < n - 1 ; i ++ ) 
               {   
                   int mn = INT32_MAX , idx = -1 ;
                   for(int j = i ; j < n ; j ++ ) 
                   {
                        if( mn > temp[j]) 
                        {
                           idx = j ;
                           mn = temp[j];
                        }
                    }
                    x += idx - i + 1 ;
                   
                    reverse(temp.begin() + i , temp.begin() + idx + 1 ); 
                }
                if(x == c) 
                break ;
            } while(next_permutation( v.begin() , v.end() ));
        }
        cout <<  "Case #"  << t << ": "; 
        for(auto x  : v ) 
        cout << x <<" ";
        cout << endl;
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