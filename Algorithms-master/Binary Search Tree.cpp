#include<iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

void insertt(struct node **temp,int data)
{
    if(*temp==NULL)
    {
        *temp=new node;
        (*temp)->data=data;
        (*temp)->left=NULL;
        (*temp)->right=NULL;
    }
    else if(data<=((*temp)->data))
        insertt(&((*temp)->left),data);
    else if(data>((*temp)->data))
        insertt(&((*temp)->right),data);
}

void InOrder(struct node **temp)
{
    if((*temp)!=NULL)
    {
        InOrder(&((*temp)->left));
        cout<<(*temp)->data<<", ";
        InOrder(&((*temp)->right));
    }
}

void PreOrder(struct node **temp)
{
    if((*temp)!=NULL)
    {
        cout<<(*temp)->data<<", ";
        PreOrder(&((*temp)->left));
        PreOrder(&((*temp)->right));
    }
}

void PostOrder(struct node **temp)
{
    if((*temp)!=NULL)
    {
        PostOrder(&((*temp)->left));
        PostOrder(&((*temp)->right));
        cout<<(*temp)->data<<", ";
    }
}

int main()
{
    int a;
    struct node *root=NULL;
    do{
        cout<<"\nEnter your choice:\n 1. Create tree \n 2. Traverse \n 3. Delete tree \n 4. Exit \n : ";
        cin>>a;
        if(a==1)
        {
            if(root==NULL)
                {
                    int c=0;
                    do{
                        int d;
                        cout<<"\nEnter data : ";
                        cin>>d;
                        insertt(&root,d);
                        cout<<"\n Want to insert more ?(0 to end)";
                        cin>>c;
                    }while(c);
                }
            else
            {
                cout<<"\n Deleting previous tree.\n";
                root=NULL;
                int c=0;
                    do{
                        int d;
                        cout<<"\nEnter data : ";
                        cin>>d;
                        insertt(&root,d);
                        cin.ignore();
                        cout<<"\n Want to insert more ?(1/0)";
                        cin>>c;
                    }while(c);
            }
            }
            else if(a==2)
            {
                cout<<"\nInOrder\n";
                InOrder(&root);
                cout<<"\nPreOrder\n";
                PreOrder(&root);
                cout<<"\nPostOrder\n";
                PostOrder(&root);
                cout<<"\n";
            }
            else if(a==3)
            {
                root=NULL;
            }
    }while(a==1 || a==2 || a==3);
    cout<<"\nThank you\n";
    return 0;
}
