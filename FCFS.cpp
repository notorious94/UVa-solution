#include<bits/stdc++.h>

using namespace std;

int job[100][5];

int main()
{

    int n;
    //printf("How many jobs: ");
    scanf("%d",&n);

    printf("Enter Arrival time and Burst time:\n");

    for(int i=1;i<=n;i++)
    {
        cin>>job[i][0];
        cin>>job[i][1];
    }

    int timer = 0;
    double a_wt = 0,a_tat = 0;

    puts("Gantt Chart:\nJob  Start_Time  Finish_Time");

    for(int i=1;i<=n;i++)
    {
        timer = max(timer,job[i][0]);

        job[i][2] = timer + job[i][1];
        job[i][3] = timer - job[i][0];
        job[i][4] = job[i][2]-job[i][0];

        a_wt += timer - job[i][0];
        a_tat += job[i][2] - job[i][0];
        printf("%2d%10d%10d\n",i,timer,job[i][2]);
        timer += job[i][1]; /// Important
    }

    puts("\nCalculation Table:\nJob  Arrival_Time  Burst_Time  Finish_Time  Waiting_Time  Turn_Around_Time\n");

    for(int i=1;i<=n;i++)
    {
        printf("%2d",i);
        for(int j=0;j<5;j++)
            printf("%13d",job[i][j]);
        puts("");
    }

    a_wt /= n;
    a_tat /= n;

    printf("\nAverage Waiting Time: %0.2lf\n",a_wt);
    printf("Average Turn Around Time: %0.2lf\n",a_tat);

    return 0;
}
