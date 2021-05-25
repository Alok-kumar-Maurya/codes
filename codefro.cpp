#include<bits/stdc++.h>
using namespace std;
#define PI 3.1415926535897932384626 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
#define ll long long int 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    string s,a,c;
    set<string>se;
    cin>>s>>a>>c;
    ll cnt=0;
    for(int i=0;s[i]!='\0';i++)
    {  
           string b;
           int k=0;
        for(int j=i;s[j]!='\0';j++)
        {      
               b+=s[j];
               int d=0;
           if(b.length()<a.length()||b.length()<c.length())
           continue;

           if(b==a)
            k=1;
            
           if(k)
            {
                string m=b.substr(b.length()-c.length(),b.length()-1);
                if(m==c)
                d=1;
            }
         
             if(d==1&&k==1)
             se.insert(b);
        }
    }
    cout<<se.size();
    return 0;
}