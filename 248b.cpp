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
    if(n==1||n==2)
    cout<<"-1";
    else if(n==3)
    cout<<"210";
    else if(n==4)
    cout<<"1050";
    else
    {              
                int c,a=1000;
        for(int i=4;i<=n;i++)
        {
                  c=a%210;
                  a=c*10;
        }
        c=210-c;
        string s=to_string(c);
        for(int i=1;i<=(n-s.length());i++)
        {
                if(i==1)
                cout<<"1";
                else
                cout<<"0";
                
        }
        cout<<s;
    }
    
    
    
     return 0;
}