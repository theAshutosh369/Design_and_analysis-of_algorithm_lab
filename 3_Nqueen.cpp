
#include<bits/stdc++.h>
using namespace std;
#define n 4

void print( int board[n][n] )
{
    for( int i = 0 ; i<n  ; i++ )
    {
        for( int j =0 ; j<n ; j++ )
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;
    cout<<endl;
}


bool issafe( int board[n][n] ,int  row ,int  col )
{

    int i , j ;
    for( i = 0 ; i< col ; i++)
    {
        if( board[row][i] )
        {
            return false ;
        }
    }

    for( i = row , j = col  ; i>=0 && j>=0  ; i-- , j-- )
    {
        if( board[i][j] )
        {
            return false ;
        }
    }

    for( i = row , j = col  ; i<n && j>=0  ; i++ , j-- )
    {
        if( board[i][j] )
        {
            return false ;
        }
    }

    return true;
}


bool solve( int board[n][n] , int col )
{

    if( col>= n )
    {
        print( board );
        cout<<endl;
        cout<<endl;
        cout<<endl;
    }

    for( int i =0 ; i<n ; i++ )
    {
        if(  issafe( board , i , col ) )
        {
            board[i][col] = 1 ;

            if( solve( board , col+1) ){
                return true;
            }
            board[i][col] = 0 ;

        }
    }

    return false;
}

int main()
{
    int board[n][n] = { };

    bool ans = solve( board , 0 );

    if( !ans )
    {
        cout<<"SOLUTION doesnt exist ! ";
        return false ;
    }

    print( board  );
    return 0 ;
}