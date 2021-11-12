/*
 It first visits the initial node and then covers all the nearest with out changind its direction
 till it reaches the 0(last bound) in that direction. on reaching the last bound one on that direction(R|L), it then goes straight to the one that
 to the lowest bound(let it be 99 in case of 100 processes i.i from 0 to 99) in another direction(L|R). and then starts scannign in reverse order
*/

#include<iostream>
using namespace std;

int nProc, proc[10],head,visited[10],previous,flagFirst=0,flagLast=0;

int findShortest( int point)
{

    int dis=999,distance,process,flag=0;
    for(int i=0;i<nProc+2;i++)
    {
        if(visited[proc[i]]==0)
        {
            distance=point-proc[i];
            if(flagFirst==1 || flagLast==1)
            {
                distance=abs(point-proc[i]);
            }
            if(distance>0)
            {

                if(distance<dis)
                {
                    dis=distance;
                    process=proc[i];
                    if(process ==0)flagFirst=1;
                    if(process==99) flagFirst=99;
                    flag=1;
                }

            }

        }

    }
    if(flag==1)
        return process;
    else return -1;
}

void input()
{
    cout<<"\n Enter head";
    cin>>head;
    cout<<"\n Enter no. of proc excluding head count";
    cin>>nProc;
    for(int i=0;i<nProc;i++)
        cin>>proc[i];
    proc[nProc]=0;
    proc[nProc+1]=99;
    for(int i=0;i<nProc;i++)
        visited[i]=0;
    previous=head;

}

void CScan()
{
    previous=head;
    int cur=proc[0];
    int totalDis=abs(head-cur);
    visited[cur]=0;

    cout<<"\n "<<previous<<" --> "<<cur;

    for(int i=1;i<nProc+2;i++)
    {
        previous=cur;
        visited[previous]=1;
        if(previous==0 && flagLast==0 || previous==proc[nProc+1] && flagFirst==0)
        {

            if(previous==0)
            {
                cur=proc[nProc+1];
                flagLast=1;
            }

            if(previous==proc[nProc+1])
            {
                cur=proc[nProc];
                flagFirst=1;
            }
        }
        else
            cur=findShortest(cur);
        cout<<" --> "<<cur;
        if(cur>=0)
        {
            totalDis+=abs(previous-head);
        }

    }
    cout<<"\n Distance : "<<totalDis;
}

int main()
{
    input();
    CScan();
}

