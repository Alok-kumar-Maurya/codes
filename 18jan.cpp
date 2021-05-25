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
vector<int> b ;
void sieve ()
{    
     b[0] = 0;               //  n(log(log(n)))
     b[1] = 0;

    for(int i = 2 ; i < 900000 ; i++) 
    { 
            if(b[i]) 
             {
                   for(int j = i*i ; j < 900000 ; j += i) 
                   b[j] = 0;
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
    b.resize(900000 , 1);
    sieve();
    while(t--)
    {
       int n ; 
       cin >> n ;
       int cnt = 0 ;
       vi a ;
       b[1] = 1 ;
       for(int i = 1 ; i < 900000 ; i ++)
       {
          
           if(b[i])  
           {
              cnt ++ ;
              a.push_back(i);
              i += (n -1);
           }
           if(cnt == 3) 
           break ;
       }      
       int d = a[1] * a[2] ;       
       cout << d << endl;

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