/*
USER: jrony15@gmail.com
LANG: C++
PROG: ride
*/
#include <stdio.h>
main()
{
    FILE* fin=fopen("ride.in","r");
    FILE* fout=fopen("ride.out","w");
    char comet[7],group[7];
    fscanf(fin,"%s",comet);
    fscanf(fin,"%s",group);
    int i,comet_len=0,comet_sum=1,group_len=0,group_sum=1;
    for(comet_len=0;comet[comet_len];comet_len++);
    for(group_len=0;group[group_len];group_len++);
    for(i=0;i<comet_len;i++)comet_sum*=(comet[i]-65+1);
    for(i=0;i<group_len;i++)group_sum*=(group[i]-65+1);
    if((comet_sum%47)==(group_sum%47))fprintf(fout,"GO\n");
    else fprintf(fout,"STAY\n");
    exit(0);
}
