#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PI 3.1415926535897932384626 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;

bool my(pair<int,string>a,pair<int,string>b)
{                     
             if(a.first>b.first)
             return true;
             if(a.first==b.first)
              {
                   if(a.second<=b.second)
                   return true;
              }
              return false;
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
    string s;
    int n;
    map<string,int>m;
    cin>>s>>n;
    while(n--)
    {     
        
         string b,s1,s2,s3;
        for(int i=0;i<5;i++)
        {
            cin>>b;
            if(i==0)
            s1=b;
            if(i==1)
            s3=b;
            if(s3=="likes")
            {
                cin>>s2>>b;
                break;
            }
            if(i==3)
            s2=b;
            
        }
        s2.erase(--s2.end());
        s2.erase(--s2.end());
       /// cout<<s2<<" ";
        if(s3=="likes")
        {
                  if(s1==s||s2==s)
                  {
                      m[s1]+=5;
                      m[s2]+=5;
                  }
        }
        else if(s3=="posted")
         {
                  if(s1==s||s2==s)
                  {
                      m[s1]+=15;
                      m[s2]+=15;
                  }
         }
        else
          {
                  if(s1==s||s2==s)
                  {
                      m[s1]+=10;
                      m[s2]+=10;
                  }
           }
           if(m.find(s1)==m.end())
           m[s1]=0;
           if(m.find(s2)==m.end())
           m[s2]=0;
    }
    m.erase(s);
    vector<pair<int,string>>v;
    for(auto x:m)
    v.push_back({x.second,x.first});

    sort(v.begin(),v.end(),my);  
    for(auto x:v)
    cout<<x.second<<endl;
    
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