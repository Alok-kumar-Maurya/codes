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
    int len=s.length();
    bool ok=false;
    for(int i=0;i<=len-26;i++)
    {
       vi cnt(26,0);
       int j;
       for(j=i;j<26+i;j++)
       {
           if(cnt[s[j]-'A']==1)
           break;
           cnt[s[j]-'A']++;
       }
       if(j!=26+i)
       continue;
       ok=true;
       for(j=i;j<26+i;j++)
       {     
            if(s[j]=='?')
            for(int k=0;k<26;k++)
            {
                if(cnt[k]==0)
                {
                    cnt[k]++;
                    s[j]=char('A'+k);
                    break;
                }
            }
       }
    }
    if(!ok)
    {
        cout<<"-1";
        return 0;
    }
    for(auto x:s)
    {
        if(x=='?')
        cout<<"A";
        else 
        cout<<x;
    }
     return 0;
// THINGS TO KEEP IN MIND
//   * int overflow, time and memory limits
//   * Special case (n = 1?)
//   * Do something instead of nothing and stay organized
//   * Don't get stuck in one focus
//   * int l=s.length()-x (s.length()<x) runtime error
// TIME AND MEMORY LIMITS
//   * 1 second is approximately 10^8 operations (c++)
//   * 10^6 Elements of 32 Bit (4 bytes) is equal to 4 MB
//   * 62x10^6 Elements of 32 Bit (4 bytes) is equal to 250 MB
//   * 10^6 Elements of 64 Bits (8 bytes) is equal to 8 MB
//   * 31x10^6 Elements of 64 Bit (8 bytes) is equal to 250 MB
}