#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PI 3.1415926535897932384626 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
map<char,int>m1;
bool overlap(string s,string c)
{   
    int j=0,cnt=0;
   for(int i=0;i<c.length();i++)
   {
       if(c[i]==s[j]&&j<s.length())
       {
        cnt++;
        j++;
       }
    m1[c[i]]++;
   }
   return (cnt==s.length());
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int t;
    cin>>t;
    while(t--)
    {
        string s,p,t;
        map<char,int>m2;
        bool ok=false;
        cin>>s>>t>>p;
        if(overlap(s,t))
        {
             for(auto x:p)
             m2[x]++;
             for(auto x:s)
             m2[x]++;
             ok=true;
             for(auto x:m1)
             {
                 if(m2[x.first]<x.second)
                 ok=false;
                 
             }
        }
        if(ok)
        cout<<"YES"<<endl;
        else 
        cout<<"NO"<<endl;
        m1.clear();
    }
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