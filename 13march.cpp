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
   
        int n ;
        cin >> n ;
        vpii v(n) ;
        for(int i = 0 ; i < n ; i ++ ) 
        {
            int a ;
            cin >> a ;
            v[i] = {a , i + 1};
        }
        sort(v.begin() , v.end()) ; 
        map<int , vpii> m ;
        for(int i = 0 ;i < n - 1 ; i ++ ) 
        {    
             int c = v[i+1].first - v[i].first ;
             if( i + 2 < n && ( c !=  v[i + 2].first - v[i + 1].first))
             m[ (v[i+ 1].first - v[i].first) ].push_back({v[i].second, v[i + 1].second});  
             else if(i == n - 2) 
             m[ (v[i+ 1].first - v[i].first) ].push_back({v[i].second, v[i + 1].second});  

        }

        bool ok = false ;
        for(auto x : m )
        {
            if(x.second.size() >= 2) 
            {   
                cout <<"YES\n";
                cout << x.second[0].first <<" "<<x.second[1].second <<" "; ;;;;
                cout << x.second[0].second <<" "<<x.second[1].first << endl;
                ok = true ;
                break;
            }
        }
        if(!ok) 
        cout << "NO\n"; 

    
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