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
    int k ;
    string s ;
    cin >> k >> s ;
    int n = s.length() ;
    vector<pair<int,int>> v( n ,{-1, 0}) ;
    queue<int> ones ;
    int cnt = 0 , cnt2 = 0 ;
    for(int i = n - 1 ; i >= 0 ; i --) 
    {
        if(s[i] == '1') 
        {
            v[i].second = cnt ;
            cnt2 +=  (cnt * (cnt + 1) / 2 ) ;
            cnt = 0 ;
            ones.push(i) ;
        }
        else 
        {  
            cnt ++ ;
        }    
        if(s[i] =='1' && ones.size() == k)
        {
            v[i].first = ones.front();
            ones.pop() ;
        } 
        else 
        { 
            if(i+1 < n)
            v[i].first = v[i+1].first ;
        }

           
    }
    int ans  = 0 ;
    cnt2 += cnt * ( cnt + 1) /2 ;
    if(k == 0) 
    ans = cnt2 ;
    else
    for(auto x : v) 
    {   
        if(x.first == -1) 
        continue ;
        ans += v[x.first].second + 1 ;
    }
    cout << ans << endl;
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