#include<bits/stdc++.h>
using namespace std;
#define PI 3.1415926535897932384626 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
#define int long long
void ansPrint(int n)
{
      for(int i=1;i<=n;i+=3)
        {
             if(i==1)
             cout<<i<<" ";
             else
             {
              cout<<i<<" ";
              if(i+1<=n)
              cout<<++i<<" ";
             }
              
        }
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
    int n;
    cin>>n;
    
    if(n%2==0)
    {
         if((n/2)%2==0)
         cout<<"0"<<endl<<n/2<<" ";
         else
         cout<<"1"<<endl<<n/2<<" ";
         ansPrint(n);
       
     }
     else
     {     
          int a=n-1;
          if((a/2)%2==0)
          cout<<"1"<<endl<<n/2<<" ";
          else
          cout<<"2"<<endl<<n/2<<" ";
          ansPrint(n);
          
     }
    return 0;
}