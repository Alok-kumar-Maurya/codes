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
int digit_cnt(int a) 
{
    string s = to_string(a) ;
    return s.length() ;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif 
    int t ;
    cin >> t;
    for(int j = 1 ; j <= t ; j ++ ) 
    {   
        int  n , ans = 0 ;
        cin >> n ;
        vi v(n) ;
        int cnt = 0;
        for(int i = 0 ; i < n ; i ++ ) 
        {
            cin >> v[i] ;
            cnt += digit_cnt(v[i]) ;
        }
        for(int i = 0 ; i < n - 1; i ++ ) 
        {
            if(v[i] >= v[i + 1])
            {
                  string s1 = to_string(v[i]) ;
                  string s2 = to_string(v[i + 1]) ;
                  if(s1.length() == s2.length()) 
                      v[i + 1] *= 10 ;
                  else 
                  {     
                        bool ok = true ;
                        for(int i = 0 ; i < min (s1.length() , s2.length()) ; i ++ ) 
                        {
                           if(s1[i] > s2[i])
                           ok = false;
                        }
                        if(ok)
                        {
                           string c = s2 + s1.substr(s2.length() , s1.length() - s2.length()) ; 
                           int d = stoi(c); 
                           d ++ ;
                           if( d  % 10 == 0)
                           v[i + 1] = d * 10 ;
                           else 
                           v[i + 1] = d ;
                        }
                        else 
                        v[i + 1] = v[i] * 10 ;
                  }
            }
            
        }
        for(int i = 0 ; i < n ; i ++ ) 
        {
            ans += digit_cnt(v[i]) ;
        }

        cout <<"Case #"<< j <<": " << ans - cnt << endl;
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