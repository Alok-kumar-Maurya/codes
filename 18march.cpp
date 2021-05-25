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
    int t  ;
    cin >> t ;
    while(t -- ) 
    {
        string  s ;
        cin >> s ;
        int n = s.length() ;
        int pre = -1 ;
        bool ans = true;
        for(int i = 0 ; i < n ; i ++) 
        {
                if(s[i] == '1')
                {
                   if(pre == -1 ) 
                   pre = i ;
                   else if(pre + 1 < i)
                   pre = i ;
                   else 
                   ans = false;
                }
        }
        for(int i = 0 ; i < n ; i ++ ) 
        {
              
            bool ok = true;
            pre = -1;
            for(int j = 0 ; j < i ; j ++ ) 
            {   
                if(s[j] == '1')
                {
                   if(pre == -1 ) 
                   pre = j ;
                   else if(pre + 1 < j)
                   pre = j ;
                   else 
                   ok = false;
                }
            }
            for(int k = i ; k < n ; k ++ ) 
            {
                if(s[k] == '0')
                {
                   if(pre == -1 ) 
                   pre = k ;
                   else if(pre + 1 < k)
                   pre = k ;
                   else 
                   ok = false;
                }
            }
            if(ok) 
            ans = true;
        }
        if(ans) 
        cout <<"YES\n" ;
        else 
        cout <<"NO\n" ;
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