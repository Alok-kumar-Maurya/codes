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
struct seg 
{
    map<int ,int> fre[200001];

    void store_count(int a , int index) 
    {
        for(int i = 2 ; i * i <= a ; i ++)
        {
            if(a % i == 0 ) 
            {    
                int cnt = 0;
                while(a %i == 0) 
                {
                    cnt ++ ;
                    a /= i ;
                }
                fre[index][i] += cnt ;
            }
        }
        if(a != 1) 
        fre[index][a] += 1 ;
    }
};
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n , q;
    cin >> n >> q ;
    seg all[7];
    for(int i = 0 ; i < n ; i ++ )
    {    
         int a ;
         cin >> a;
         for(int j = 0 ; j < 7 ; j ++ ) 
         {
              
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