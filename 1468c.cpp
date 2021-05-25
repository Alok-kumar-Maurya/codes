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
class mycomp
{  
    public:
    bool operator()(pii a , pii b)const
    {
       if(a.first < b.first )
       return true  ;
       if(a.first == b.first) 
       return a.second > b.second ;
       return false; 
    }
};
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // cout.tie(0);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif
    int q , i = 1 ;
    priority_queue<pii , vector<pii>, mycomp> mono;
    set<pii> check ;
    queue<pii> poly;
    cin >> q ;
    while(q--)  
    {
        int a , m ;
        cin >> a ;
        if( a == 1) 
        {
              cin >> m ; 
              mono.push({ m , i}) ;
              poly.push({m , i}) ;
              i ++ ;

        }
        else if(a == 3) 
        {
               auto top = mono.top() ;
               while(check.find(top) != check.end()) 
               {
               	     
               	     mono.pop() ;
               	     top = mono.top();
               }
               mono.pop() ;
               cout << top.second <<" ";
               check.insert(top);
        }
        else 
        {      
                auto first = poly.front() ;
                while(check.find(first) != check.end()) 
                {
                   poly.pop() ;
                   first = poly.front();
                }
                poly.pop();
                check.insert(first);
                cout << first.second << " " ;
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