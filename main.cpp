/*
USER: jrony15@gmail.com
LANG: C++
PROG: friday
*/
#include <stdio.h>

int days_in_months[12]= {31,28,31,30,31,30,31,31,30,31,30,31};
int count_days[7]= {0,0,0,0,0,0,0}; //0 means Saterday
int N,last_13th_was=0;
bool is_leap_year(int month)
{
    if(month%100==0)
    {
        if(month%400==0) return 1;
        else return 0;
    }
    else
    {
        if(month%4==0) return 1;
        else return 0;
    }
}
void round_days(int temp_days)
{

    if((last_13th_was+temp_days)>=7)
    {
        last_13th_was+=temp_days;
        last_13th_was-=7;
    }
    else last_13th_was+=temp_days;
}
int main()
{
    FILE* fin=fopen("friday.in","r");
    FILE* fout=fopen("friday.out","w");
    fscanf(fin,"%d",&N);
    int i=0,j=0;
    count_days[0]++;
    while(i<N)
    {
        days_in_months[1]=(is_leap_year(1900+i))?29:28;
        for(j=1; j<=12; j++)
        {
            int temp_day=days_in_months[j-1];
            temp_day%=7;
            round_days(temp_day);
            count_days[last_13th_was]++;
        }
        i++;

    }
    count_days[last_13th_was]--;
    for(i=0; i<7; i++){if(i<6)fprintf(fout,"%d ",count_days[i]);else fprintf(fout,"%d",count_days[i]);}
    fprintf(fout,"\n");
    return 0;


}
