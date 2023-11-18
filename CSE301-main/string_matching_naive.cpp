#include<iostream>
using namespace std;

int main()
{
    string s,t;
    cin>>s>>t;
    bool match=true;
    for(int i=0; i<=s.size()-t.size(); i++)
    {
        for(int j=0; j<t.size(); j++)
        {
            if(t[j]!=s[i+j])
            {
                match=false;
                break;
            }
        }
        if(match)
        cout<<"matched at: "<<i<<endl;
        match=true;
    }
    return 0;
}
