#include<bits/stdc++.h>
using namespace std;

vector<int>pie;

void prefix(string pattern)
{
    int m = pattern.size();
    pie.resize(m,0);

    int k=0;

    for(int q=1; q<m; q++)
    {
        while(k>0 && pattern[k]!=pattern[q])
            k=pie[k];
        if(pattern[k]==pattern[q])
            k++;
        pie[q]=k;
    }
}

void kmp(string& text, string& pattern) {
    int n = text.size();
    int m = pattern.size();
    prefix(pattern);

    int q = 0;
    for (int i = 0; i<n; i++) {
        while (q>0 && pattern[q] != text[i])
            q = pie[q-1];

        if (pattern[q] == text[i])
            q++;

        if (q == m) {
            cout<<"Pattern occurs with shift "<<i-m+1<<endl;
            q = pie[q-1];
        }
    }
}

int main()
{
    string text, pattern;
    cin>>text>>pattern;
    
    kmp(text, pattern);
    cout<<endl;
    return 0;
}
