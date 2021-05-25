#include<bits/stdc++.h>
using namespace std;
#define PI 3.1415926535897932384626 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
vector<string> ans;
void y1y2equl(int &x1,int &x2)
{
          if(x1<x2)
          {
                 while(x1!=x2)
                 {
                   ans.push_back("D");
                   x1++;
                 }
          }
          else
          {     
                   while(x1!=x2)
                    {
                       ans.push_back("U");
                       x2++;
                    }
          }
 
}
void x1x2equal(int &y1,int &y2)
{
           if(y1<y2)
          {
                 while(y1!=y2)
                 {
                   ans.push_back("R");
                   y1++;
                 }
          }
          else
          {     
                       while(y1!=y2)
                       {
                         cout<<'L'<<endl;
                         y2++;
                       }
          }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int x1,x2,y1,y2;
    
           string c,s;
           cin>>c>>s;
           x1=c[0]-'a'+1;
           y1=c[1]-'0';
           x2=s[0]-'a'+1;
           y2=s[1]-'0';
        
    if(x1==x2)
    {
            x1x2equal(y1,y2);
    }
    else if (y1=y2)
    {
           y1y2equl(x1,x2);   
    }
    else
    {
               if(x2>x1)
               {
                   if(y2>y1)
                   { 
                       while(x1!=x2&&y2!=y1)
                       {
                             ans.push_back("RD");
                             y1++;
                             x1++;
                             if(x2==x1)
                             x1x2equal(y1,y2);
                             if(y2==y1)
                             y1y2equl(x1,x2);
                       }

                   }
                  else
                   {
                         while(x1!=x2&&y2!=y1)
                       {
                             ans.push_back("LD");
                             y1--;
                             x1++;
                             if(x2==x1)
                             x1x2equal(y1,y2);
                             if(y2==y1)
                             y1y2equl(x1,x2);
                       } 
                   }
               }
               else
               { 
                    if(y2>y1)
                              while(x1!=x2&&y2!=y1)
                              {
                             ans.push_back("RU");
                             y1++;
                             x1--;
                             if(x2==x1)
                             x1x2equal(y1,y2);
                             if(y2==y1)
                             y1y2equl(x1,x2);
                              }
                  
                    else 
                            while(x1!=x2&&y2!=y1)
                             {
                             ans.push_back("RU");
                             y1--;
                             x1--;
                             if(x2==x1)
                             x1x2equal(y1,y2);
                             if(y2==y1)
                             y1y2equl(x1,x2);
                       }

               }

               
    }         
    cout<<ans.size()<<endl;
    for(auto x:ans)
    cout<<x<<endl;
    
       
    return 0;
}