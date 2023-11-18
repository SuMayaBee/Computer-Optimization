#include<bits/stdc++.h>
using namespace std;

struct node
{
    char c;
    int freq;
    struct node* left;
    struct node* right;
};

void printCodes(struct node* root, string& code)
{
    if (!root)
        return;
    if(root->left)
    {
        code+='0';
        printCodes(root->left,code);
        code.pop_back();
    }

    if(root->right)
    {
        code+='1';
        printCodes(root->right, code);
        code.pop_back();
    }
    if(!root->left && !root->right)
    {
        cout<<root->c<<": "<<code<<endl;
    }
}

void b_sort(struct node* arr[],int t)
{
    for(int i=0; i<t; i++)
    {
        for(int j=0; j<t; j++)
        {
            if(arr[i]->freq<arr[j]->freq)
            {
                struct node* temp = arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

struct node* build(char c, int freq)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->c = c;
    newNode->freq = freq;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main()
{
    int t,fr;
    char ch;

    cout<<"Enter numbers of symbols: ";
    cin>>t;
    struct node* arr[t];
    for(int i=0; i<t; i++)
    {
        cout<<"Enter character: ";
        cin>>ch;
        cout<<"Enter "<<ch<<"'s frequency: ";
        cin>>fr;
        arr[i]=build(ch, fr);
    }
    cout<<"Before Encoding: "<<endl;
    for(int i = 0; i < t; i++)
        cout << arr[i]->c << ": " << arr[i]->freq << endl;
    cout << endl;
    
    b_sort(arr, t);
    while(t > 1)
    {
        struct node* huff1 = arr[0];
        struct node* huff2 = arr[1];
        struct node* newHuff = build('@', huff1->freq + huff2->freq);
        newHuff->left = huff1;
        newHuff->right = huff2;

        arr[0] = newHuff;

        for (int i = 1; i < t-1; i++)
        {
            arr[i] = arr[i + 1];
        }
        t--;
        b_sort(arr,t);
    }
    cout<<"After Encoding: "<<endl;
    string code="";
    printCodes(arr[0], code);
    return 0;
}
