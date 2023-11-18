#include<bits/stdc++.h>
using namespace std;

struct item{
    int value;
    int weight;
    double val_per_weight;
};

bool compare(struct item item1, struct item item2)
{
    return item1.val_per_weight>item2.val_per_weight;
}
void benefit(vector<item>&items, int w)
{
    sort(items.begin(), items.end(), compare);

    double total=0.0;
    double curr_weight=0.0;
    double x[items.size()]={0};

    for(int i=0; i<items.size(); i++)
    {
        if(curr_weight + items[i].weight<=w)
        {
            total+=items[i].value;
            curr_weight+=items[i].weight;
            x[i]=items[i].weight;
        }
        else
        {
            double rem_weight = w-curr_weight;
            total+=rem_weight*items[i].val_per_weight;
            x[i]=rem_weight;
            break;
        }
    }
    for(int i=0; i<items.size(); i++)
    {
        if(x[i])
        cout<<x[i]<<"ml taken from "<<items[i].weight<<"ml"<<endl;
    }
    cout<<"Total Profit: "<<total<<endl;
}
int main()
{
    //freopen("test.txt", "r", stdin);
    int n, w;
    cin>>n;
    vector<item>items(n);
    for(int i=0; i<n; i++)
    {
        cin>>items[i].value>>items[i].weight;
        items[i].val_per_weight = (items[i].value/items[i].weight);
    }
    cin>>w;
    benefit(items, w);

    return 0;
}
