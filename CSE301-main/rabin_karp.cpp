#include <bits/stdc++.h>
using namespace std;
#define Q 13

int hashVal(int start, int end, string &s)
{
    int hash=0;
    for(int i=start; i<start+end; i++)
    hash = (hash*Q+s[i])%Q;

    return hash;
}

int main()
{
    string text, pattern;
    cin >> text >> pattern;

    int n = text.size(), m = pattern.size();
    int textHash=hashVal(0,n,text);
    int patternHash = hashVal(0,m,pattern);

    for(int i=0; i<=n-m; i++)
    {
        if(textHash==patternHash)
        {
            bool f = true;
            for(int j=0; j<m; j++)
            {
                if(pattern[j]!=text[i+j])
                {
                    f=false;
                    break;
                }
            }
            if(f)
            cout<<"Match at "<<i<<endl;
        }
        if(i<n-m)
        {
            textHash = (textHash-text[i] +text[i+m])%Q;
        }
    }
}
