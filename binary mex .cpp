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
    int t ;
    cin >> t ;
    while(t -- ) 
    {   
        string s ;
        cin >> s ; 
        int n = s.length() ;
        vector<pair<char,int>> v;
        for(int i = 0 ; i < n ; i ++ ) 
        {    
            int cnt = 0 ;
            while(i + 1 < n && s[i] == s[i + 1]) 
            {
                i ++ ;
                cnt ++ ;
            }
            v.push_back({s[i] , cnt + 1});
        }
        if(v.size() == 1)
        {  

            cout << ( v[0].first == '1' ? '0' : '1' ) << endl;
        }
        else
        {   
            string ans ;
            int l = v.size() ;
            for(int i = 0 ; i < l ; i ++ ) 
            {   
                if(i == l - 1) 
                {
                    if(v[i - 1].second == 1) 
                    {
                      ans += v[i - 1].first ;
                      ans += v[i - 1].first ;
                    }
                    else if(v[i].second == 1)
                    {
                        ans += v[i].first ;
                        ans += '0' ;
                    }
                    else 
                    {
                        ans += v[i].first ;
                        ans += ( v[i].first == '1' ? '0' : '1') ;
                    }

                }
                else if(i != 0  && v[i - 1].second == 1 && v[i - 1].first == '0')
                {
                    ans += '0' ;
                    i ++ ;
                }
                else if(v[i].second == 1) 
                {
                   ans += v[i].first ;
                   if(i + 2 == l ) 
                   ans += v[i].first ;
                   i ++ ;
                }
                else 
                {
                   ans += v[i].first ;
                }
            }
            cout << ans << endl;
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