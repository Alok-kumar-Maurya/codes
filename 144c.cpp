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
    string s,p;
    cin>>s>>p;
    vi mp(26);
    vector<vector<int>> sp(s.length(),vector<int>(27,0));
    for(auto x:p)
    mp[x-'a']++;
    if(s[0]=='?')
    sp[0][26]++;
    else
    sp[0][s[0]-'a']++;
    for(int i=1;i<s.length();i++)
    {
          sp[i]=sp[i-1];
          if(s[i]=='?')
          sp[i][26]++;
          else
          sp[i][s[i]-'a']++;
    }
    int l1=s.length(),l2=p.length(),cnt=0;
    for(int i=0;i<=l1-l2;i++)
    {        
              int k=1,char_,ok=1;
             for(int j=0;j<=25;j++)
             {
                    
                    if(i==0)
                    {      
                        if(k)
                        char_=sp[l2-1][26];
                        if(mp[j]<sp[l2-1][j])
                        ok=0;
                        else if(mp[j]>sp[l2-1][j])
                        {
                            int diff=mp[j]-sp[l2-1][j];
                            if(diff>char_)
                            ok=0;
                            else
                            char_-=diff;
                        }

                    }
                    else 
                    {            
                              if(k)
                              char_=sp[i+l2-1][26]-sp[i-1][26];
                              if(mp[j]<sp[i+l2-1][j]-sp[i-1][j])
                              ok=0;
                              else if(mp[j]>sp[i+l2-1][j]-sp[i-1][j])
                              {
                                   int diff=mp[j]-(sp[i+l2-1][j]-sp[i-1][j]);
                                   if(diff>char_)
                                   ok=0;
                                   else
                                   char_-=diff;
                              }
                    }
                 k=0;

              }
              if(ok)
              cnt++;
    }
    cout<<cnt;
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