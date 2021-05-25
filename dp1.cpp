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
vi memotable ,coin ;
int dp(int sum ) 
{       
   
    if(memotable[sum] != -1 )
       return memotable[sum];

    if( sum == 0 ) 
    {        
       memotable[0] = 0;                   // top down
       return 0 ;
    }
    int minval = INT64_MAX;
    for( int i = 0 ; i < coin.size() ; i++)
    {      
           if(sum - coin[i] >= 0) 
           minval = min ( minval , dp ( sum - coin[i]));   

    }
    memotable[sum] = minval + 1;
    return minval + 1 ;
}
int dp2(int sum)
{
    vi table(sum +1 , 0) ;
    vi parent(sum+1 , -1) ;
    for(int i = 1 ; i <= sum ; i ++)
    {          
            table[i] = INT64_MAX ;
        for(int j = 0 ; j < coin.size() ; j++)
        {    
            if(  i - coin[j] >=0 )
            {         
                  if(table[i - coin[j]] + 1 < table[i])    // bottom top
                  { 
                      table[i] = table[i- coin[j]] + 1;          
                      parent[i] = i - coin[j];
                  }
            }
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
    int sum , num ;
    cin >> sum >> num;
    for(int i = 0 ; i < num ; i ++)
    {     
        int a ;
        cin >> a ;
        coin.push_back(a);
    }
    memotable.resize(sum+1, -1) ;
    cout << dp( sum ) ;
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