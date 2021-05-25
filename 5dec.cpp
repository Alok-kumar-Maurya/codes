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
class my
{
      public : 
      bool operator() (string a ,string b)
      {
            if(a.length() > b.length()) 
            return true ;
            if(a.length() == b .length()) 
            return a < b ;
            return false ;
      }
};
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int t ;
    cin >> t;
    while (t--)
    {
    
          string s ; 
          cin >> s ;
          set < string > all ;
          for(int i = 0 ; i< s.length() ; i++)
          {
                string c  ="",d ;
                int l = 0;
                for(int j = i; j < s.length() ; j++ )
                {
                     c += s[j] ;
                     if(s[j] == '1') 
                     l++ ;
                     if ( l%2 == 0 ) 
                     {   
                        d = c;
                        reverse(d.begin() , d.end());
                        if((all.find(d) == all.end()) && (all.find(c) == all.end() ) )
                        {
                            all.insert(c);
                        }
                     }
                     else     
                        all.insert(c);
                     
                }
          }           
          
          cout << all.size() << endl;
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