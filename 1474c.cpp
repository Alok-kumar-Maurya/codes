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
    cin >> t ;
    while(t--)
    {
        int n ; 
        cin >> n ;
        vi v(2*n) ;
        multiset<int>all ;
        for(auto &x :v)
        {
           cin >> x ;
           all.insert(x);
        }
        sort(v.begin() , v.end()) ;
        vector<pii> ans ;
        bool check = false;
        for(int i = 0 ; i < 2 * n -1 ; i ++)
        { 
            int y = v[i];
            int l = v[2*n -1];
            bool ok = true ;
            int num = l;
            ans.clear();
            multiset<int , greater<int> > s;
            ans.push_back({l , y}) ;
            for(auto z : all) 
            {
                if(l == z) 
                l = -1 ;
                else if(y == z) 
                y = -1 ;
                else 
                s.insert(z);

            }

            while(s.size())
            {    
                int top = *s.begin();
                s.erase(s.begin()) ;
                if(s.find(num - top ) != s.end() ) 
                {  
                    ans.push_back({top , num - top}) ;
                    s.erase(s.find(num - top)) ;
                    num = top ;
                }
                else 
                {
                    ok = false ;
                    break;
                }
            }
            if(ok) 
            {  
               check = true ;
               break ;
            }

        }
        if(check)
        {
            cout <<"YES\n" << ans[0].first + ans[0].second << endl;
            for(auto x : ans) 
            cout << x.first <<" " << x.second << endl;
        }
        else 
        cout <<"NO\n";
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