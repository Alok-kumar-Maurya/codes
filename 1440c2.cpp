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
    int t ;
    cin >> t ;
    while ( t-- )
    {
         int n , m ; 
         cin >> n >> m ;
         
         vector<vector<int>>grid(n+1,vector<int>(m+1));
         for(int i = 1 ; i <= n ; i++ )
         {   
              string s;
              cin >> s;
             for( int j = 0 ; j < m ;j++)
             {    
                  if(s[j]=='0')
                  grid[i][j+1]=0;
                  else 
                  grid[i][j+1]=1;
             }
         }
         vector<vector<pair<int,int>>>ans(n*m,vector<pair<int,int>>(3));
         int k=0;
         for(int i = 1 ; i <= n-2; i++)
         {
             for(int j =1 ; j<= m ;j++)
             { 
                    if(grid[i][j])
                    {
                        if( j == m)
                        {
                            ans[k][0]={i,j};
                            ans[k][1]={i+1,j-1};
                            ans[k][2]={i+1,j};
                            grid[i][j]=1-grid[i][j];
                            grid[i+1][j-1]=1-grid[i+1][j-1];
                            grid[i+1][j]=1-grid[i+1][j];
                            k++;
                        }
                        else                
                        {
                            ans[k][0]={i,j};
                            ans[k][1]={i,j+1};
                            ans[k][2]={i+1,j}; 
                            grid[i][j]=1-grid[i][j];
                            grid[i][j+1]=1-grid[i][j+1];
                            grid[i+1][j]=1-grid[i+1][j];
                            k++;                      
                        }
                    }
              }
         }
         int x=n-1;
         for(int i = 1 ; i <= m-2 ; i++ )
         {
                 if(grid[x][i]) 
                 {
                       ans[k][0]={x,i};
                       ans[k][1]={x,i+1};
                       ans[k][2]={x+1,i};
                       grid[x][i]=1-grid[x][i];
                       grid[x][i+1]=1-grid[x][i+1];
                       grid[x+1][i]=1-grid[x+1][i];
                       k++;
                       
                 }
                 if(grid[x+1][i])
                 {
                       ans[k][0]={x+1,i};
                       ans[k][1]={x+1,i+1};
                       ans[k][2]={x,i+1};
                       grid[x+1][i]=1-grid[x+1][i];
                       grid[x+1][i+1]=1-grid[x+1][i+1];
                       grid[x][i+1]=1-grid[x][i+1];
                       k++;
                 }
                 
         }
         

        while(1)
		{            
			if(grid[n-1][m-1]==0 && grid[n][m-1]==0 && grid[n-1][m]==0 && grid[n][m]==0)
			{
				break;
			}
			if(grid[n-1][m-1]==1 && grid[n][m-1]==1 && grid[n-1][m]==1 && grid[n][m]==1)
			{
				grid[n-1][m-1]=0;
				grid[n-1][m]=0;
				grid[n][m-1]=0;
				ans[k][0]={n-1,m-1};
				ans[k][1]={n-1,m};
				ans[k][2]={n,m-1};
			    k++;
			}
			if(grid[n-1][m-1]==1 && grid[n][m-1]==1 && grid[n-1][m]==1 && grid[n][m]==0)
			{
				grid[n-1][m-1]=0;
				grid[n-1][m]=0;
				grid[n][m-1]=0;
				ans[k][0]={n-1,m-1};
				ans[k][1]={n-1,m};
				ans[k][2]={n,m-1};
                k++;	

			}
			if(grid[n-1][m-1]==0 && grid[n][m-1]==1 && grid[n-1][m]==1 && grid[n][m]==1)
			{
				grid[n][m]=0;
				grid[n][m-1]=0;
				grid[n-1][m]=0;
				ans[k][0]={n,m};
				ans[k][1]={n,m-1};
				ans[k][2]={n-1,m};
			    k++;
			}
			if(grid[n-1][m-1]==1 && grid[n][m-1]==0 && grid[n-1][m]==1 && grid[n][m]==1)
			{
				grid[n-1][m-1]=0;
				grid[n][m]=0;
				grid[n-1][m]=0;
				ans[k][0]={n-1,m-1};
				ans[k][1]={n,m};
				ans[k][2]={n-1,m};
                k++;
			}
			if(grid[n-1][m-1]==1 && grid[n][m-1]==1 && grid[n-1][m]==0 && grid[n][m]==1)
			{
				grid[n-1][m-1]=0;
				grid[n][m-1]=0;
				grid[n][m]=0;
				ans[k][0]={n-1,m-1};
				ans[k][1]={n,m-1};
				ans[k][2]={n,m};
                k++;
			}
			if(grid[n-1][m-1]==0 && grid[n][m-1]==0 && grid[n-1][m]==1 && grid[n][m]==1)
			{
				grid[n][m]=0;
				grid[n][m-1]=1;
				grid[n-1][m-1]=1;
                ans[k][0]={n,m};
				ans[k][1]={n,m-1};
				ans[k][2]={n-1,m-1};
			    k++;
			}
			if(grid[n-1][m-1]==1 && grid[n][m-1]==1 && grid[n-1][m]==0 && grid[n][m]==0)
			{
				grid[n-1][m-1]=0;
				grid[n-1][m]=1;
				grid[n][m]=1;
				ans[k][0]={n-1,m-1};
				ans[k][1]={n-1,m};
				ans[k][2]={n,m};
				k++;
			}
			if(grid[n-1][m-1]==1 && grid[n][m-1]==0 && grid[n-1][m]==0 && grid[n][m]==1)
			{
				grid[n-1][m-1]=0;
				grid[n-1][m]=1;
				grid[n][m-1]=1;
                ans[k][0]={n-1,m-1};
				ans[k][1]={n-1,m};
				ans[k][2]={n,m-1};
				k++;
			}
			if(grid[n-1][m-1]==0 && grid[n][m-1]==1 && grid[n-1][m]==0 && grid[n][m]==1)
			{
				grid[n-1][m-1]=1;
				grid[n-1][m]=1;
				grid[n][m]=0;
				ans[k][0]={n-1,m-1};
				ans[k][1]={n-1,m};
				ans[k][2]={n,m};
				k++;
			}
			if(grid[n-1][m-1]==1 && grid[n][m-1]==0 && grid[n-1][m]==1 && grid[n][m]==0)
			{
				grid[n-1][m-1]=0;
				grid[n][m-1]=1;
				grid[n][m]=1;
                ans[k][0]={n-1,m-1};
				ans[k][1]={n,m-1};
				ans[k][2]={n,m};
				k++;
			}
			if(grid[n-1][m-1]==0 && grid[n][m-1]==1 && grid[n-1][m]==1 && grid[n][m]==0)
			{
				grid[n-1][m-1]=1;
				grid[n-1][m]=0;
				grid[n][m]=1;
				ans[k][0]={n-1,m-1};
				ans[k][1]={n-1,m};
				ans[k][2]={n,m};
                k++;
			}
			if(grid[n-1][m-1]==0 && grid[n][m-1]==0 && grid[n-1][m]==0 && grid[n][m]==1)
			{
				grid[n-1][m-1]=1;
				grid[n-1][m]=1;
				grid[n][m]=0;
                ans[k][0]={n-1,m-1};
				ans[k][1]={n-1,m};
				ans[k][2]={n,m};
                k++;
				
			}
			if(grid[n-1][m-1]==0 && grid[n][m-1]==0 && grid[n-1][m]==1 && grid[n][m]==0)
			{
				grid[n-1][m-1]=1;
				grid[n-1][m]=0;
				grid[n][m]=1;
                ans[k][0]={n-1,m-1};
				ans[k][1]={n-1,m};
				ans[k][2]={n,m};
                k++;
				
			}
			if(grid[n-1][m-1]==0 && grid[n][m-1]==1 && grid[n-1][m]==0 && grid[n][m]==0)
			{
				grid[n-1][m-1]=1;
				grid[n][m-1]=0;
				grid[n][m]=1;
				ans[k][0]={n-1,m-1};
				ans[k][1]={n,m-1};
				ans[k][2]={n,m};
                k++;
			}
			if(grid[n-1][m-1]==1 && grid[n][m-1]==0 && grid[n-1][m]==0 && grid[n][m]==0)
			{
				grid[n-1][m-1]=0;
				grid[n][m-1]=1;
				grid[n][m]=1;
                ans[k][0]={n-1,m-1};
				ans[k][1]={n,m-1};
				ans[k][2]={n,m};
                k++;
				
			}
		}

        cout << k << endl;
         for( int i = 0 ; i < k ; i++ )
         {
                for( int j = 0 ; j < 3 ; j++ )
                cout << ans[i][j].first <<" " << ans[i][j].second<< " ";
                cout << endl; 
         }
         ans.clear();
         grid.clear();
    }
 return 0;
// THINGS TO KEEP IN MIND
//   * int overflow, time and memory limits
//   * Special case (n = 1?)
//   * Do something instead of nothing and stay organized
//   * Don't get stuck in one focus
//   * int l=s.length()-x (s.length()<x) runtime error
// TIME AND MEMORY LIMITS
//   * 1 second is approxigridely 10^8 operations (c++)
//   * 10^6 Elements of 32 Bit (4 bytes) is equal to 4 MB
//   * 62x10^6 Elements of 32 Bit (4 bytes) is equal to 250 MB
//   * 10^6 Elements of 64 Bits (8 bytes) is equal to 8 MB
//   * 31x10^6 Elements of 64 Bit (8 bytes) is equal to 250 MB
}