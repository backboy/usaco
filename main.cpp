/*
USER: jrony15@gmail.com
LANG: C++
PROG: gift1
*/
#include <stdio.h>
int N;
char name[21][15];
int init_balance[15];
int total_given[15];
int total_taken[15];
int search_name(char n[15])
{
    int i,j;
    for(i=0; i<N; i++)
    {
        for(j=0; name[i][j]&&n[j]; j++){
            if(name[i][j]!= n[j])
                break;
        }
        //printf("\n");
        if(name[i][j]||n[j]);
        else break;
    }
    return i;
}
main()
{
    FILE* fin=fopen("gift1.in","r");
    FILE* fout=fopen("gift1.out","w");
    fscanf(fin,"%d",&N);
    int i,j;
    for(i=0; i<N; i++)
    {
        fscanf (fin,"%s", name[i]);
        init_balance[i]=0;
        total_taken[i]=0;
        total_given[i]=0;
    }
    for(i=0; i<N; i++)
    {
        char donar_name[15];
        int number_0f_given=0,index=0;
        fscanf(fin,"%s",donar_name);
        index=search_name(donar_name);
        fscanf(fin,"%d %d\n",&init_balance[index],&number_0f_given);
        total_taken[index]=init_balance[index];
        int per_given=0;
        if(number_0f_given!=0)per_given= total_taken[index]/number_0f_given;
        total_taken[index]-=(per_given*number_0f_given);
        for(j=0;j<number_0f_given;j++){
            char given_name[15];
            fscanf(fin,"%s",given_name);
            total_given[search_name(given_name)]+=per_given;
        }
    }
    for(i=0;i<N;i++)fprintf(fout,"%s %d\n",name[i],(total_given[i]+total_taken[i])-init_balance[i]);
    exit(0);
}
