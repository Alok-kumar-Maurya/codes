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
    int t ;
    cin >> t;
    while(t--) 
    {
        int n ;
        cin >> n ;
        vi un_mar ;
        unordered_set<int>check ;
        for(int i = 1 ; i <= n ; i ++)
        check.insert(i);
        for(int i = 1 ; i <= n ; i ++)
        {
            int k ;
            cin >> k ;
            bool ok = false; 
            set<int> s;
            while( k -- ) 
            {
                int a ;
                cin >> a ;
                s.insert(a);
            } 
            while(s.size()) 
            {
                int top = *s.begin() ;
                if(check.find(top) != check.end() ) 
                {
                    check.erase(top);
                    ok = true ;
                    break ;
                }
                else 
                {
                    s.erase(s.begin()) ;
                }
            }
            if( !ok ) 
            {
                un_mar.push_back(i) ;
            }
        }
        if(un_mar.size())
        {      
            cout <<"IMPROVE\n";
            for(int i = 0 ; i < un_mar.size() ; i ++) 
            {
               cout << un_mar[i] <<" "<<*check.begin() <<endl; 
               check.erase(check.begin()) ;
            }
        }
        else 
        {
            cout <<"OPTIMAL\n";
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