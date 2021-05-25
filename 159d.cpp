#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PI 3.1415926535897932384626 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    string s;
    cin>>s;
    map<string,int>m;
    for(int i=0;i<s.length();i++)
    {
         string b;
         for(int j=i;j<s.length();j++)
         {
             b+=s[j];
             m[b]++;
         }
    }
    // for(auto x:m)
    // cout<<x.first<<" "<<x.second<<endl;
    int ans=0;
    for(auto x:m)
    {        
          string b=x.first;
          bool ok=true;
          for(int i=0;i<b.length()/2;i++) 
          {
              if(b[i]!=b[b.length()-i-1])
              ok=false;

          }
          if(ok)
          {
          cout<<x.first<<endl;
          ans+=x.second;
          }
          
          
    }
    cout<<ans;
     return 0;
// THINGS TO KEEP IN MIND
//   * int overflow, time and memory limits
//   * Special case (n = 1?)
//   * Do something instead of nothing and stay organized
//   * Don't get stuck in one focus
// TIME AND MEMORY LIMITS
//   * 1 second is approximately 10^8 operations (c++)
//   * 10^6 Elements of 32 Bit (4 bytes) is equal to 4 MB
//   * 62x10^6 Elements of 32 Bit (4 bytes) is equal to 250 MB
//   * 10^6 Elements of 64 Bits (8 bytes) is equal to 8 MB
//   * 31x10^6 Elements of 64 Bit (8 bytes) is equal to 250 MB
}