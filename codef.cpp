#include<bits/stdc++.h>
using namespace std;
#define PI 3.1415926535897932384626 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int t,n;
    cin>>t;
    while(t--)
    {       
        cin>>n;
        vi v;
        int cnt=0;
        v.resize(n);
        for(int i=0;i<n;i++)
        cin>>v[i];
        for(int i=0;i<v.size();i++)
        {        
             
            if(v[i])
            for(int j=i+1;j<v.size();j++)
            {
                 if(v[j])
                 { 
                   cnt+=(j-i-1);
                   i=j-1;
                   break;
                 }
            }
        }  
        
          cout<<cnt<<endl;
         
    }
     return 0;
}