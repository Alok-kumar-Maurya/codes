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
    int k;
    string s,s2;
    cin>>k>>s;
    for(int j=1;j<=k;j++)
    {   
        for(auto x:s)
        s2.push_back(x);
    } 
    map<char,vector<int>>m;
    for(int i=0;i<s2.length();i++)
    m[s2[i]].push_back(i);

    int q;
    cin>>q;
    while(q--)
    {
         int b;
         char c;
         cin>>b>>c;
         if(m[c].size()>=b)
         {  
             s2[m[c][b-1]]='A';
             m[c].erase(m[c].begin()+b-1);
         }
    }
    for(int i=0;i<s2.length();i++)
    {
        if(s2[i]=='A')
        continue;
        cout<<s2[i];
    }
    
     return 0;
}