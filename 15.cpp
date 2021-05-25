#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long int
using namespace std;
#define mod 1073741824
ll div (ll k)
{   
    int ans=1,pow;
  for(int i=2;i*i<=k;i++)
  {
      if(k%i==0) 
      {      
          pow=0;
         while(k%i==0)
         {
             k/=i;
             pow++;
         }
        ans*=(pow+1);
      } 
  }
  if(k!=1)
  ans*=2;
 
   return ans;
}
int main()
{       
    fast;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int a,b,c;
    ll ans=0;
    cin>>a>>b>>c;
    for(int i=1;i<=a;i++)
    {
        for(int j=1;j<=b;j++)
        {
            for(int k=1;k<=c;k++)
              {
                  ll l=i*j*k;
                  ans=(ans+div(l))%mod;
              }
        }
    }
    cout<<ans;
}