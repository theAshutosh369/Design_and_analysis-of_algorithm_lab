#include <bits/stdc++.h>
using namespace std;

#define n 8



////////////////  BELLMAN FORD ALGORITHM /////////////////////////





// struct edge{
//     int src , dest , weight;
// };

// struct graph{
//     int V, E ;
//     struct edge* e;
// };

// void bellman( struct graph* g , int src )
// {
//     int V = g->V;
//     int E = g->E;

//     int dist[V];

//     for( int i =0 ; i<V  ; i++ )
//     {
//         dist[i] = INT_MAX;
//     }
//     dist[src] = 0;

//     for( int i = 1 ; i<= V-1 ; i++ )
//     {
//         for( int j = 0 ; j<E ; j++ )
//         {
//             int u , v , w ;
//             u = g->e[j].src;
//             v = g->e[j].dest;
//             w = g->e[j].weight;

//             if( dist[u]!=INT_MAX &&  dist[u]+w<dist[v])
//             {
//                 dist[v] = dist[u] + w ;
//             }

//         }
//     }

//     for (int j = 0; j < E; j++)
//     {
//         int u, v, w;
//         u = g->e[j].src;
//         v = g->e[j].dest;
//         w = g->e[j].weight;

//         if (dist[u] != INT_MAX && dist[u] + w < dist[v])
//         {
//             cout<<"neg cycle !! ";
//             return;
//         }
//     }

//     cout<<"distance of vertexes from source : "<<endl;

//     for( int i = 0 ; i< V ; i++ )
//     {
//         cout<<i<<"  "<<dist[i]<<endl;
//     }



// }
// int main()
// {
//     struct graph* g ;

//     int V, E;
//     cout<<"no. of vertices : ";
//     cin>> V;
//     cout<<"no. of edges : ";
//     cin>> E;

//     g->V=V;
//     g->E=E;
//     g->e = new edge[E];

//     cout<<"enter source , destination and weight : "<<endl;

//     for( int i =0 ; i<E ; i++ )
//     {
//         int u , v , w ;
//         cin>> u >> v >> w ;
//         g->e[i].src = u;
//         g->e[i].dest = v;
//         g->e[i].weight = w;

//     }

//     bellman( g , 0 );
//     return 0;




// }










//////////////////  N QUEENS ////////////////////////////////


// void print( int board[n][n] )
// {
//     for( int i =0 ; i< n ; i++ )
//     {
//          for( int j = 0 ; j<n ;j++ )
//          {
//             cout<<board[i][j] <<" ";
//          }
//          cout<<endl;
//     }
// }
// bool issafe( int board[n][n] , int row , int col )
// {

//     for( int i =0 ; i< col ; i++ )
//     { 
//         if( board[row][i] ) return false ;
//     }

//     for( int i =row , j = col  ; i>=0 && j>=0  ; i-- , j--  )
//     { 
//         if( board[i][j] ) return false ;
//     }

//     for (int i = row , j= col ; i<n && j>=0 ; i++ , j-- )
//     {
//         if (board[i][j])
//             return false;
//     }

//     return true;
// }

// bool solve ( int board[n][n] , int col )
// {

//     if( col >= n  ) return true ;

//     for( int i =0 ; i < n ; i++ )
//     {
//         if( issafe( board , i , col ))
//         {
//             board[i][col] = 1;
//             if( solve( board , col+1 )) return true;
//             board[i][col] = 0;

//         }
//     }

//     return false;
// }
// int main( )
// {
//     int board[n][n] = { };

//     bool ans = solve( board , 0 );

//     if( !ans )
//     {
//         cout<<"solution doesnt exist ! "<<endl;
//         return false ;
//     }

//     print( board);

//     return 0;



// }



//////////////////// fractional knapsack problem //////////////////////


// struct item{
//     int p , w;
//     item( )
//     {
//         this->p = 0;
//         this->w = 0;
//     }
//     item( int p , int w )
//     {
//         this->p = p ;
//         this->w = w ;
//     }
// };

// bool comp( struct item a , struct item b )
// {
//     double r1 = ( double)a.p / ( double)a.w ;
//     double r2 = (double)b.p / (double)b.w;

//     return r1>r2 ;
// }

// int main( )
// {
//     int W , num  ;
//     cout<<"enter the no. of items : ";
//     cin>> num;

//     cout << "Knapsack size : ";
//     cin >> W;
//     item arr[num ];

//     cout<<"ENter the profit and weights "<<endl;

//     for( int i =0 ; i< num ; i++ )
//     {
//         int pro , wei ;
//         cin>> pro >> wei ;

//         arr[i].p = pro ;
//         arr[i].w = wei ; 
//     }

//     sort( arr , arr+num , comp );
//     double ans = 0;
//     for( int i =0 ; i<num ; i++ )
//     {
//         if( arr[i].w <= W ){
//             W = W - arr[i].w;
//             ans = ans + arr[i].p ;
//         }
//         else{
//             ans = ans + arr[i].p * ( (double) W / (double)arr[i].w);
//             break;
//         }
//     }

//     cout<<"The profit : "<<ans;
//     return 0;


// }



/////////////////////  0 / 1 knapsack problem  ////////////////////


int main()
{
    int k, nn;
    cout << "enter the no. of items : ";
    cin >> nn;

    cout << "Knapsack size : ";
    cin >> k;
    int dp[nn + 1][k + 1];
    int p[nn], w[nn];

    cout << "ENter the profit and weights " << endl;
    for (int i = 0; i < nn; i++)
    {
        cin >> p[i] >> w[i];
    }

    for (int i = 0; i < nn + 1; i++)
    {
        for (int j = 0; j < k + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (j < w[i - 1])
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i - 1]] + p[i - 1]);
            }
        }
    }

    vector<int> v;
    int j = k;

    for (int i = nn; i > 0; i--)
    {
        if (dp[i][j] == dp[i - 1][j])
        {
            j = j - 1;
        }
        else
        {
            j = j - w[i - 1];
            v.push_back(i);
        }
    }

    cout << "items selected are : ";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    cout<<endl;
    cout << "MAX profit by 0 1 knapsack : " << dp[nn][k];
    return 0;
}
