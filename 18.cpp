#include<bits/stdc++.h>
using namespace std;
int32_t main()
{       
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c=0,l,m,bitmask=0;
        cin>>a>>b;
        l=a;m=b;
        while(a!=0&&b!=0)
        {
                if((a&1)&&(b&1))
                c=c+(1<<bitmask);
                a=a>>1;
                b=b>>1;
                bitmask++;
        }
          cout<<(l^c)+(m^c)<<endl;
    }
}