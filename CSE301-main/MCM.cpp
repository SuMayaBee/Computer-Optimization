#include<bits/stdc++.h>
using namespace std;
#define mx 100

vector<vector<int>> m;
int s[mx][mx];

void print(int i, int j)
{
    if(i==j)
        cout<<"A"<<i<<" ";
    else
    {
        cout<<"(";
        print(i, s[i][j]);
        print(s[i][j]+1, j);
        cout<<")";
    }
}
int mcm(vector<int>& p, int i, int j) {
    if (m[i][j] != INT_MAX)
        return m[i][j];
    if (i == j)
        m[i][j] = 0;
    else {
        for (int k = i; k <= j - 1; k++) {
            int q = mcm(p, i, k) + mcm(p, k + 1, j) + p[i-1] * p[k] * p[j];
            if(m[i][j]>q)
            {
                m[i][j]=q;
                s[i][j]=k;
            }
        }
    }
    return m[i][j];
}

int main() {
    freopen("mcm.txt", "r", stdin);
    int n;
    cout << "Enter number of matrices: ";
    cin >> n;

    m.assign(n + 1, vector<int>(n + 1, INT_MAX));
    vector<int> p(n + 1);
    cout << "Enter dimensions: ";
    for (int i = 0; i <= n; i++)
        cin >> p[i];

    cout << mcm(p, 1, n)<<endl;;
    print(1, n);
    return 0;
}
