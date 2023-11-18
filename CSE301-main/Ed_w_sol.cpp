#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>dp;
vector<vector<string>>path;

void print_path(string &x, string &y, int i, int j)
{
    if (!i)
    {
        cout<<"insert "<<y[j-1]<<endl;
         return;
    }
    if (!j)
    {
        cout<<"delete "<<x[i]<<endl;
         return;
    }
    if (path[i][j] == "\\")
    {
        print_path(x, y, i - 1, j - 1);
        cout << "substitute " << x[i - 1] << " with " << y[j-1] <<endl;
    }
    else if (path[i][j] == "|" && j)
    {
        print_path(x, y, i - 1, j);
        cout << "delete " << x[i - 1] << endl;
    }
    else if (path[i][j] == "-" && i)
    {
        print_path(x, y, i, j - 1);
        cout << "insert " << y[j - 1] << endl;
    }
    else if (path[i][j] == "\\\\")
    {
        print_path(x, y, i - 1, j - 1);
    }
}

void print_path_2(string &x, string &y, int i, int j)
{
    if (i>0 && j>0 && x[i-1] == y[j-1])
    {
        print_path(x, y, i-1, j-1);
    }
    else if (i>0 && (j==0 || dp[i][j] == dp[i-1][j]+1))
    {
        print_path(x, y, i-1, j);
        cout << "Delete " << x[i-1] << endl;
    }
    else if (j>0 && (i==0 || dp[i][j] == dp[i][j-1]+1))
    {
        print_path(x, y, i, j-1);
        cout << "Insert " << y[j-1] << endl;
    }
    else if (i>0 && j>0 && dp[i][j] == dp[i-1][j-1]+1)
    {
        print_path(x, y, i-1, j-1);
        cout << "Substitute " << x[i-1] << " with " << y[j-1] << endl;
    }
}


int ed(string x, string y)
{
    int m=x.size(), n=y.size();
    dp.resize(m+1, vector<int>(n+1));
    path.resize(m+1, vector<string>(n+1));

    for(int i=0; i<=m; i++)
    {
        for(int j=0; j<=n; j++)
        {
            if(!i)
            {
                dp[i][j]=j;
                path[i][j]="-";
            }

            else if(!j)
            {
                dp[i][j]=i;
                path[i][j]="|";
            }

            else if(x[i-1]==y[j-1])
            {
                dp[i][j]=dp[i-1][j-1];
                path[i][j]="\\\\";
            }
            else
            {
                if(dp[i][j-1]<dp[i-1][j] && dp[i][j-1]<dp[i-1][j-1])
                {
                    dp[i][j]= dp[i][j-1]+1;
                    path[i][j] = "-";
                }
                else if(dp[i-1][j]<dp[i][j-1] && dp[i-1][j]<dp[i-1][j-1])
                {
                    dp[i][j]=dp[i-1][j]+1;
                    path[i][j]="|";
                }
                else
                {
                    dp[i][j]= dp[i-1][j-1]+1;
                    path[i][j] = "\\";
                }
            }
        }
    }
    return dp[m][n];
}
int main()
{
    string x,y;
    cin>>x>>y;
    int res = ed(x,y);
    cout<<res<<endl;
    //print_path_loop(x,y);
    print_path(x,y,x.size(), y.size());
    return 0;
}
