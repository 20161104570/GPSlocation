//
//  main.c
//  GPSlocation
//
//  Created by 20161104570 on 17/6/22.
//  Copyright © 2017年 20161104570. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,year,n,a[10],b,month,day,hour,minute,second;
    char c1[70];
    char c2[70];
    char lat[10];//纬度
    char lon[10];//经度
    char time[10];//时间
    char asl[5];//海拔
    char date[10];//从gps中提取的时间
    FILE *fp;
    FILE *fr;
    fp = fopen("//Users//a20161104570//Desktop//GPSlocation//GPS170510.log","r");
    fr = fopen("//Users//a20161104570//Desktop//GPSlocation//a.csv","w");
    if (fp == NULL)
    {
        printf("File open error !\n");
        return -1;
    }
    else
    {
        fscanf(fp,"%s %s",c1,c2);
        //经度
        for(i=0;i<9;i++)
            lon[i]=c1[i+27];
        //纬度
        for(i=0;i<8;i++)
            lat[i]=c1[i+16];
        //时间
        for(i=0;i<6;i++)
            time[i]=c1[i+7];
        n=0;
        n=atoi(time);
        for(i=0;i<6;i++)
        {
            a[i]=n%10;
            n=n/10;
        }
        hour=a[5]*10+a[4]+8;
        minute=a[3]*10+a[2];
        second=a[1]*10+a[0];
        b=0;
        if(hour>=24)
        {
            b++;
            hour=hour-24;
        }
        //海拔
        for(i=0;i<4;i++)
            asl[i]=c2[i+43];
        //日期
        for(i=0;i<6;i++)
            date[i]=c1[i+51];
        n=0;
        n=atoi(date);
        for(i=0;i<6;i++)
        {
            a[i]=n%10;
            n=n/10;
        }
        year=a[1]*10+a[0]+2000;
        month=a[3]*10+a[2];
        day=a[5]*10+a[4];
        if(b!=0)
            day=day+1;
        //*******************************
        
        printf(" 日期:%d年%d月%d日\n",year,month,day);
        printf(" 时间:%d时%d分%d秒\n",hour,minute,second);
        printf(" 经度:%s\n 纬度:%s\n 海拔:%s\n ",lon,lat,asl);
        
        fprintf(fr," 日期:%d年%d月%d日\n",year,month,day);
        fprintf(fr," 时间:%d时%d分%d秒\n",hour,minute,second);
        fprintf(fr," 经度:%s\n 纬度:%s\n 海拔:%s\n ",lon,lat,asl);
        
        fclose(fp);
        fp=NULL;
    }
    return 0;
}
