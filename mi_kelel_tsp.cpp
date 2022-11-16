#include<bits/stdc++.h>
using namespace std ;
#define n 5 
#define inf INT_MAX 


struct jodi{
    int cost ;
    int mat[n][n] ;
};

jodi cal(int src, int dest, int srcmat[n][n])
{
    int rowsum = 0, colsum = 0;

    // src ki row infinity krdi 
    for( int i=0 ; i< n ; i++ )
    {
        srcmat[src][i] = inf ;
    }

    // destination ki column infinity krdi
    for (int i = 0; i < n; i++)
    {
        srcmat[i][dest] = inf;
    }

    // dest to sec path infinite krdi
    srcmat[dest][src] = inf ;

    for (int i = 0; i < n; i++)
    {
        int min = INT_MAX;
        for (int j = 0; j < n; j++)
            if (srcmat[i][j] < min)
                min = srcmat[i][j];

        if (min == inf || min == 0)
        {
            min = 0;
            continue;
        }

        if (min != INT_MAX)
        {
            for (int k = 0; k < n; k++)
            {
                if (srcmat[i][k] != inf)
                {
                    srcmat[i][k] -= min;
                }
            }

            rowsum += min;
        }
    }

    for (int i = 0; i < n; i++)
    {
        int min = INT_MAX;

        for (int j = 0; j < n; j++)
        {
            if (srcmat[j][i] < min)
                min = srcmat[j][i];
        }

        if (min == inf || min == 0)
        {
            min = 0;
            continue;
        }

        if (min != inf)
        {
            for (int k = 0; k < n; k++)
            {
                if (srcmat[k][i] != inf)
                {
                    srcmat[k][i] -= min;
                }
            }

            colsum += min;
        }
    }

    int rcap = rowsum + colsum;

    jodi temp;
    temp.cost = rcap;
    temp.mat[n][n] = srcmat[n][n] ;

    return temp;
}

jodi agla_path_nikal(int cost[n][n], bool visited[n + 1], vector<int> path ,  int src )
{

        int min = INT_MAX;
        int srcmat[n][n];
        jodi bhej ;
        int next; 
        for (int i = 1; i < n; i++)
        {
            if (visited[i] != 1)
            {
                jodi temp = cal( src , i , cost );
                if ( temp.cost < min )
                {
                    min = temp.cost;
                    srcmat[n][n] = temp.mat[n][n];
                    next=i;
                }
            }
        }   

        path.push_back( next );
        bhej.cost = min ;
        bhej.mat[n][n] = srcmat[n][n] ;

        return bhej ;
}


int soln(int cost[n][n], bool visited[n + 1], vector<int> path )
{

    int rowsum = 0, colsum = 0;

    for( int i = 0 ; i < n ; i++ )
    {
        int min = INT_MAX ;
        for( int j =0 ; j< n ; j++ )
            if (cost[i][j] < min)
                min = cost[i][j];

        if( min == inf || min==0 ){ 
            min =0 ;
            continue;
        }

        if( min != INT_MAX )
        {
            for (int k = 0; k < n; k++)
            {
                if( cost[i][k]!=inf )
                {   
                    cost[i][k] -= min;
                }
            }

            rowsum += min;
        }
        
    }

    //  printing matrix
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //        cout<<cost[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    
    for (int i = 0; i < n; i++)
    {
        int min = INT_MAX;

        for (int j = 0; j < n; j++)
        {
            if (cost[j][i] < min)
                min = cost[j][i];
        }

        if (min == inf || min==0 )
        {
            min = 0;
            continue;
        }

        if (min != inf)
        {
            for (int k = 0; k < n; k++)
            {
                if (cost[k][i] != inf)
                {
                    cost[k][i] -= min;
                }
            }

            colsum += min;
        }

    }

    int rcap = rowsum + colsum ;

    return rcap ;

}

int main( )
{

    int cost[n][n] = { {inf , 20 , 30 , 10 , 11 } ,{ 15 , inf , 16 , 4 ,2  } , { 3 , 5 ,inf , 2 ,4  } , { 19 , 6 , 18 , inf , 3  } , { 16 , 4 ,7 , 16 , inf  } } ;


    bool visited[n+1 ] ;
    visited[1] = 1;

    vector<int> path;
    path.push_back(1);

    int one_ka_cost = soln(cost, visited , path);

    int srcmat[n][n]  ;
    srcmat[n][n] = cost[n][n] ;


    for( int i =0 ; i<n-1 ; i++ )
    {
        jodi temp = agla_path_nikal( srcmat , visited , path , path[path.size()-1] ) ;
        srcmat[n][n] = temp.mat[n][n] ;
    }

    for( int i =0 ; i< path.size( ); i++ )
    {
        cout<<path[i]<<" --> ";
    }
    cout<<"1";

    return 0;


}