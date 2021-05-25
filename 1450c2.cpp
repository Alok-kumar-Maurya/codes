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
vector<vector<char>> tic_tak;
vector<vector<int>>grid;

void change( int cnt , int n)
{          
       for(int i = 1 ; i <= n ; i++ )
        {
            for(int j = 1 ; j <= n ; j++)
            { 
                if((tic_tak[i][j] == 'X') && (grid[i][j] == cnt) ) 
                tic_tak[i][j] = 'O' ;
            }
        }
}
void print(int n)
{
      for(int i = 1 ; i <= n ; i++ )
        {
            for(int j = 1 ; j <= n ; j++)
            { 
                cout << tic_tak[i][j] ;
            }
            cout << endl;
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

    int t ;
    cin >> t;
    while ( t--)
    {  
        int n ;
        cin >> n ;
        grid.resize(n+1 , vi(n+1)) ;
        tic_tak.resize(n+1 , vector<char>(n+1));
        for(int i = 1 ; i <= n ; i++ )
        {
            for(int j = 1 ; j <= n ; j++)
            {
                grid[i][j] = (i + j) % 3;
            }
        }
        int a[3]={0};
        for(int i = 1 ; i <= n ; i++) 
        {
           for(int j = 1 ; j <= n ; j++)
            {        
                     char c ;
                     cin >> c ;
                     tic_tak[i][j] = c ;
                     if(c == 'X') 
                     {
                         
                     }
                     else 
                     {
                          
                     }
            }
        }
        int mini = min({a[0],a[1],a[2]});
        for(int  i = 0 ; i <= 2 ; i++)
        {    
            if(mini == a[i])
            {
                change( i ,n);
                break;
            }
        }
        print(n);
        grid.clear();
        tic_tak.clear();
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