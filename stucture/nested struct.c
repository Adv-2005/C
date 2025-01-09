#include<stdio.h>
int main(){
typedef struct{
int hours;
int minutes;
int seconds;
}Time;
typedef struct{
int days;
int months;
int years;
}Date;
typedef struct{
Time time;
Date date;
}Stamp;
typedef struct{
Stamp endtime;
Stamp starttime;
}Job;
Job job;
printf("Enter job start time\n");
printf("Enter hours \n");
scanf("%d",&job.starttime.time.hours);
printf("Enter minutes \n");
scanf("%d",&job.starttime.time.minutes);
printf("Enter seconds \n");
scanf("%d",&job.starttime.time.seconds);

printf("Start time for job is %d:%d:%d",job.starttime.time.hours,job.starttime.time.minutes,job.starttime.time.seconds);
}
