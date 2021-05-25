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
    int n;
    cin>>n;
    set<string>all_sub;
    while(n--)
    {
        string s;
        cin>>s;
        for(int i=0;i<s.length();i++)
        {
            string b;
            for(int j=i;j<s.length();j++)
            {
                b+=s[j];
                all_sub.insert(b);
            }
        }

    }
    string ans,b;
    for(int i=0;i<26;i++)
    {
        for(int j=0;j<26;j++)
          {  
                   string c=b; 
                    c=(97+j);
                    if(all_sub.find(c)==all_sub.end())
                    {
                        ans=c;
                        break;
                    }

          }

          b=char(97+i);
          if(ans.length())
          break;
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