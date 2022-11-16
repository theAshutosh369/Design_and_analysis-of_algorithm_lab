#include<bits/stdc++.h>
using namespace std;

struct item
{

    int p , w ;
    item(){
        this->p = 0;
        this->w = 0;
    }
    item( int p , int w )
    {
        this->p = p ;
        this->w = w ;
    }

};

bool comp( struct item a , struct item b )
{
    double r1 = (double)a.p / (double)a.w;
    double r2 = (double)b.p / (double)b.w;

    return r1>r2;
}

int fk( struct item arr[] , int W , int n  )
{
    sort( arr , arr+n , comp );

    double ans = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].w <= W)
        {
            W = W - arr[i].w;
            ans = ans + arr[i].p;
        }
        else
        {
            ans = ans + arr[i].p * ((double)W / (double)arr[i].w);
            break;
        }
    }

    return ans;
}

float fractinalUtil()
{
    cout<<"++++++++++++++ FRACTIONAL KNAPSACK +++++++++++++++++++++"<<endl;
    int W;
    int n ,i ;
    cout<<"Enter number of items : ";
    cin >> n;

    cout<<"Enter knapsack size : ";
    cin >> W;

    item arr[n];

    cout<<"enter profit and weight line by line "<<endl;
    for( i = 0; i < n; i++)
    {
        cout<<"profit weight pair no. "<<i+1<<endl;
        cin >> arr[i].p >> arr[i].w;
    }

    cout<<"The maximum profit by fractional knapsack is : ";
    cout << fk(arr, W, n)<<endl;
    return fk(arr, W, n);
}

float zero_one()
{
    
    cout << "++++++++++++++ ZERO ONE KNAPSACK +++++++++++++++++++++" << endl;
    int n, k ,i, j;

    cout << "Enter number of items : ";
    cin >> n;

    cout << "Enter knapsack size : ";
    cin >> k;

    int pr[n], wt[n];

    cout << "enter profit and weight line by line "<<endl ;
    for (i = 0; i < n; i++)
    {
        cout << "profit weight pair no. " << i+1 << endl;
        cin >> pr[i] >> wt[i];
    }

    int dp[n + 1][k + 1];
    for (i = 0; i < n + 1; i++)
    {
        for (j = 0; j < k + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (j < wt[i - 1])
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = max(   dp[i-1][j]   ,  dp[i-1][j-wt[i-1]] + pr[i-1]    );
            }
        }
    }

    for (i = 0; i < n + 1; i++)
    {
        for (j = 0; j < k + 1; j++)
        {
            cout << dp[i][j];
        }
        cout << endl;
    }

    vector<int> v;
    j = k;

    for (int i = n; i > 0; i--)
    {
        if (dp[i][j] == dp[i-1][j])
        {
            j = j - 1;
        }
        else
        {

            j = j - wt[i - 1];
            v.push_back(i);
        }
    }

    cout << "items selected are : ";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    cout << "ANSWER for o/1 knapsack is : " << dp[n][k]<<endl;
    cout<<endl;

    return dp[n][k];
}

int main( )
{

    fractinalUtil();
    cout<<"/////////////////////////////////////////////////"<<endl;
    zero_one();


    return 0;

}











