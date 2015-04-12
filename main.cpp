/*
USER: jrony15@gmail.com
LANG: C++
PROG: beads
*/
#include <stdio.h>

int N,MAX=0;
char input_str[360];
int status[360];
FILE *fin,*fout;

int count_left_beads(int pos)
{

    int i=pos,cnt=0;
    char c=input_str[pos];
    if(c=='w')
    {   status[i]=1;
        i--;
        cnt++;

        for(;; i--,cnt++)
        {
            i=(i<0)?N-1:i;
            if(input_str[i]!='w' || cnt==N)break;
            status[i]=1;
        }
    }


    if(cnt!=N)
    {
        c=input_str[i];
        status[i]=1;
        i--;
        cnt++;
        for(;; i--,cnt++)
        {
            i=(i<0)?N-1:i;
            if((input_str[i]!=c && input_str[i]!='w')|| cnt==N)break;
            status[i]=1;

        }

    }
    return cnt;




}

int count_right_beads(int pos)
{
    int i,cnt=0;
    pos=(pos==N)?0:pos;
    i=pos;
    char c=input_str[pos];
    if(c=='w' && status[i]==0)
    {
        i++;
        cnt++;
        for(;; i++,cnt++)
        {
            i=(i==N)?0:i;
            if(input_str[i]!='w' || status[i]==1)break;
        }
    }
    if(cnt!=N&& status[i]==0)
    {
        c=input_str[i];
        i++;
        cnt++;
        for(;; i++,cnt++)
        {
            i=(i==N)?0:i;
            if((input_str[i]!=c && input_str[i]!='w')|| status[i]==1)break;
        }

    }
    return cnt;

}
int main()
{
    fin=fopen("beads.in","r");
    fout=fopen("beads.out","w");
    fscanf(fin,"%d",&N);
    fscanf(fin,"%s",input_str);
    int i,j;
    for(i=0; i<N; i++)
    {
        for(j=0;j<N;j++)status[j]=0;
        int left_cnt=0,right_cnt=0;
        left_cnt=count_left_beads(i);
        if(left_cnt<N)right_cnt=count_right_beads(i+1);
        int x=left_cnt+right_cnt;
        MAX=(MAX<x)?x:MAX;
    }
    fprintf(fout,"%d\n",MAX);
    return 0;


}
