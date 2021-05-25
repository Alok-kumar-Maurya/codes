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
    string s;
    cin>>n>>s;
    int cnt1=0,cnt2=0,cnt0=0;
    for(auto x:s)
    {
        if(x=='0')
        cnt0++;
        else if(x=='1')
        cnt1++;
        else 
        cnt2++;
    }
    int k=0,l=0;
    for(int i=0;i<s.length();i++)
    {
            if(cnt0>n/3&&s[i]=='0')
              {
                 if(cnt1<n/3&&k>=n/3)
                 {
                     s[i]='1';
                     cnt1++;
                     cnt0--;
                 }
                 else if(cnt2<n/3&&k>=n/3)
                 {
                     s[i]='2';
                     cnt2++;
                     cnt0--;
                 }
                 k++;
              }

            else if(s[i]=='1'&&cnt1>n/3)
              {
                       if(cnt0<n/3)
                       {
                        s[i]='0';
                        cnt0++;
                        cnt1--;
                       }
                       else if(l<n/3)
                       l++;
                       else if(cnt2<n/3)
                       {
                           cnt2++;
                           cnt1--;
                           s[i]='2';
                       }
                
              }
             else if(cnt2>n/3&&s[i]=='2')
              {
                   if(cnt0<n/3)
                       {
                        s[i]='0';
                        cnt2--;
                        cnt0++;
                       }
                       else if(cnt1<n/3)
                      {
                        s[i]='1';
                        cnt2--;
                        cnt1++;
                       }
                    
              }
    }
    cout<<s;
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