#include<bits/stdc++.h>
using namespace std;

void print_sol(vector<int>&prev, vector<int>&a, int i)
{
    if(i==-1)
    return;
        print_sol(prev, a,prev[i]);
        cout<<a[i]<<" ";
}

void lis(vector<int>&a, int n)
{
    vector<int> L, Lc(n + 1), prev(n + 1);
    L.push_back(INT_MIN);
    Lc[0] = -1;
    prev[0] = -1;

    for(int i = 1; i <= n; i++)
    {
        if(L[L.size()-1] < a[i])
        {
            L.push_back(a[i]);
            Lc[L.size()-1] = i;
            prev[i] = Lc[L.size()-2];
        }
        else
        {
            int s = 0, h = L.size()-1;
            while(s < h)
            {
                int m = (s + h) / 2;
                if(L[m] < a[i])
                    s = m + 1;
                else
                    h = m;
            }
            L[s] = a[i];
            Lc[s] = i;
            prev[i] = Lc[s - 1];
        }
    }
    /*for(int i=0; i<=n; i++)
    cout<<a[i]<<" "<<L[i]<<" "<<Lc[i]<<" "<<prev[i]<<endl;*/
    cout << L.size()-1<<endl;
    print_sol(prev,a, n);
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);

    for(int i = 1; i <= n; i++)
        cin >> a[i];
    lis(a, n);
    return 0;
}
