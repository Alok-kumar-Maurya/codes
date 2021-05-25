#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PI 3.1415926535897932384626 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
#define debugxy(x,y) cout<<"[ "<<x<<"  "<<y<<" ]"<< endl
#define debugx(x) cout <<"[ "<< x <<" ]"<<endl
#define endl  "\n" 
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int q ;
    cin >> q ;
    for(int t = 1 ; t <= q ; t ++) 
    {
        int x , y ;
        cin >> x >> y ;
        string s ;
        cin >> s ;
        int n = s.length() ;
        int ans = INT32_MIN;
        if(n == 1) 
        {
            cout <<  "Case #" << t << ": " <<"0" << endl; 
            continue;
        }
        if( x && y  )
        {      
               string temp ;
               for(int i = 0 ; i < n ; i ++ )
               {
                    if(s[i] == '?') 
                    {   
                        if(temp.size())
                        temp += s[i] ;
                        while(i < n && s[i] == '?')
                        i ++ ;
                    }
                    if(i < n)
                    temp += s[i];
               }
               for(int i = 1 ; i < (int)temp.size() - 1 ; i ++ ) 
               {
                   if(temp[i] == '?') 
                   {
                        if(temp[i - 1] == temp[i + 1]) 
                        temp[i] = temp[i + 1];
                        else 
                        temp[i] = temp[i - 1] ;
                   }
               }
               for(int i = 0 ; i < (int)temp.size() - 1; i ++ ) 
               {
                   if(temp.substr(i , 2) == "CJ") 
                   ans += x ;
                   else if(temp.substr(i , 2) == "JC") 
                   ans += y ;
               }

        }
    
        cout <<  "Case #" << t << ": " <<ans << endl; 
     }
 return 0;
// THINGS TO KEEP IN MIND
//   * int overflow, time and memory limits
//   * Special case (n = 1?)
//   * Do something instead of nothing and stay organized
//   * Don't get stuck in one focus
//   * int l=s.length()-x (s.length()<x) garbage value
// TIME AND MEMORY LIMITS
//   * 1 second is approximately 10^8 operations (c++)
//   * 10^6 Elements of 32 Bit (4 bytes) is equal to 4 MB
//   * 62x10^6 Elements of 32 Bit (4 bytes) is equal to 250 MB
//   * 10^6 Elements of 64 Bits (8 bytes) is equal to 8 MB
//   * 31x10^6 Elements of 64 Bit (8 bytes) is equal to 250 MB
}