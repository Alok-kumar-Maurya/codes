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
string a , b ;
int l1 , l2 ;

int memotable[100][100] = {0};
int lcs ( int i , int  j )
{     
     ///debugxy(i, j);
     if(memotable[i][j] != 0) 
     return memotable[i][j] ;
     if(i == l1 || j == l2 )
     {  
       return 0 ;
     }
     if( a[i] == b[j]) 
     {    
         memotable[i][j] = 1 + lcs(i+1 , j+1);
         return  memotable[i][j];
     }
     else 
     {  
         memotable[i][j] = max( lcs(i , j+1) , lcs( i+1 , j)) ;
         return  memotable[i][j] ;
     }
}
int memo[100][100][20] ;                 ///// k = 20 is 
int K_order_lcs ( int i , int  j ,int k)
{     
     if(memo[i][j][k] != 0) 
     return memo[i][j][k] ;
     if(i == l1 || j == l2 ) 
     return 0 ;
     if( a[i] == b[j]) 
     {    
         memo[i][j][k] = 1 + K_order_lcs(i+1 , j+1 , k);
         return  memo[i][j][k];
     }
     else 
     {    
         int fi = 0, se = 0;
         if(k > 0) 
         fi = 1 + K_order_lcs(i+1 ,j+1 , k-1) ;
         se = max( K_order_lcs(i+1 , j ,k) , K_order_lcs( i , j+1,k)) ;
         memo[i][j][k] = max(fi ,se) ;
         return  memo[i][j][k] ;
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
    int k ;
    cin >> a >> b ;
    l1 = a.length() ;
    l2 = b.length() ;

    int cas_e  ;
    cin >> cas_e ;
    int ans = 0; 

    switch (cas_e)
    {
    case 1:
            lcs(0 , 0 );
            for(int i = 0 ; i < 100 ; i++)  
            {   
              for(int j = 0 ; j < 100 ;j ++) 
                   ans = max (ans , memotable[i][j]);
            }
            cout << ans << endl;
            break;
    case 2:
          cin >> k ;
          K_order_lcs(0 , 0 , k);
         for(int i = 0 ; i < 100 ; i++)  
         {   
            for(int j = 0 ; j < 100 ;j ++) 
            {
              for(int l =0 ; l <= k ; l++)
              {
                ans = max (ans , memo[i][j][l]);
              }

            }
         }
           cout << ans << endl;
           break;
    default:
        cout <<"INCORRECT CHOICE\n";
        break;
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