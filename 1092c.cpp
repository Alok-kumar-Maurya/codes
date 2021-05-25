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
    int  n ;
    cin >> n ;
    vector< string > v(2* n - 2 ) ,check ;
    vector<char> ans(2 * n - 2 , 'S') ;
    unordered_set< string > s ;
    for(int i = 0 ; i < 2 * n - 2 ; i ++ ) 
    {
       cin >> v[i];
       s.insert( v[i] ) ;
       if(v[i].length() == n - 1 ) 
       check.push_back( v[i] );
    }
    for(int i = 0 ; i < 2 ; i ++ ) 
    {  
        bool ok = true ;
        unordered_set<string> all ;
        string c ;
        for(int j = 0 ; j < check[i].length() ; j ++ )
        {   
    
                c += check[i][j] ;
                all.insert(c);
                if(s.find(c) == s.end()) 
                ok = false;
        
        }
        if(ok) 
        {a
            for(int j = 0 ; j < 2 * n - 2; j ++ ) 
            {
                if(all.find(v[j]) != all.end()) 
                {
                    ans[j] = 'P' ;
                    all.erase(v[j]);
                } 
                else 
                ans[j] = 'S' ;
            }
            
        }
     
    }
    for(auto x : ans) 
    cout <<x ;
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