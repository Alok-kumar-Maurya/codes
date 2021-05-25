

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
    freopen("output2.txt","w",stdout);
    #endif
    int t ;
    cin >> t ;
    
    while(t -- ) 
    {
        int n , x ;
        cin >> n >> x;
        vi v(30 , 0 ) ;
        for(int i = 0 ; i < n ; i ++ ) 
        { 
            int a;
            cin >> a ;
            int mask = 0 ;
            while(a) 
            {
               if(a & 1) 
               v[mask] ++ ;
               a >>= 1 ;
               mask ++ ;
            }    
        }
        int c = x , hieght = 0;
        int bit[30] = { };
        int mask = 0 ;
        while(c) 
        {
            if(c & 1) 
            bit[mask] ++ ;
            c >>= 1 ;
            mask ++ ;
        }
        while(n)
        {
            for(int i = 29 ; i >= 0  ; i -- ) 
            {  
                if(bit[i]) 
                {
                    if(v[i])
                    {
                       v[i] -- ;
                       n -- ;
                    }
                    else 
                    {    
                        int target = 1 << i ;
                        for(int j = i - 1 ; j >= 0 ; j -- )
                        {   
                            int need = target / ( 1 << j ) ;
                            if(v[j] == 0) 
                            continue;
                            if( v[j] >= need )
                            {
                               v[j] -= need;
                               n -= need ;
                               break ;
                            }
                            else
                            {
                               target -= ( v[j]) * ( 1 << j) ;
                               n -= v[j];
                               v[j] = 0;
                            }
                    
                        }
                     }
                }
            }
          //  debugx(n);
            hieght ++ ;
        }
        
        cout << hieght << endl;
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