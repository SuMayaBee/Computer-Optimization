#include<bits/stdc++.h>
using namespace std;

int numJob;

struct job{
    char jobId[20];
    int start;
    int finish;
    int compatibility;
}jobs[100];

void read_code()
{
    cin>>numJob;
    for(int i=0; i<numJob; i++)
    {
        cin>>jobs[i].jobId;
        cin>>jobs[i].start;
        cin>>jobs[i].finish;
        jobs[i].compatibility = 1;
    }
}
bool compare(struct job job1, struct job job2)
{
    return job1.finish<job2.finish;
}

void ordering()
{
    int lastTime = jobs[0].finish;
    for(int i=1; i<numJob; i++)
    {
        if(jobs[i].start<lastTime)
        {
            jobs[i].compatibility=0;
        }
        else
            lastTime= jobs[i].finish;
    }
}

void recursive(int i)
{
    int m=i+1;
    while(m<=numJob && jobs[m].start<jobs[i].finish)
    {
        jobs[m].compatibility=0;
        m++;
    }
    if(m<=numJob)
        recursive(m);
    else
        return;
}
int main()
{
    
    read_code();
    sort(jobs, jobs+numJob, compare);
    recursive(0);
    
    for(int i=0; i<numJob; i++)
    {
        if(jobs[i].compatibility)
            cout<<jobs[i].jobId<<" ";
    }
    return 0;
}