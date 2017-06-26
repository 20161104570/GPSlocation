//
//  main.c
//  GPSlocation
//
//  Created by 20161104570 on 17/6/22.
//  Copyright © 2017年 20161104570. All rights reserved.
//

#include <stdio.h>

int main()
{
    int i,n[10],y,r,d;
    char c1[70];
    char c2[70];
    char lat[10];//纬度
    char lon[10];//经度
    char time[10];//时间
    char asl[5];//海拔
    FILE *fp;
    fp = fopen("//Users//a20161104570//Desktop//GPSlocation//GPS170510.log","r");
    if (fp == NULL)
    {
        printf("File open error !\n");
        return -1;
    }
    else
    {
        fscanf(fp,"%s %s",c1,c2);
        for(i=0;i<9;i++)
            lon[i]=c1[i+27];
        for(i=0;i<8;i++)
            lat[i]=c1[i+16];
        for(i=0;i<6;i++)
            time[i]=c1[i+7];
        for(i=0;i<4;i++)
            asl[i]=c2[i+43];
        n[i]=c1[i+51]-48;
        d=n[0]*10+n[1];
        y=n[2]*10+n[3];
        r=n[4]*10+n[5];
            printf("%d",n);
        printf("\n 经度:%s\n 纬度:%s\n 时间:%s\n 海拔:%s\n ",lon,lat,time,asl);
        
        fclose(fp);
        fp=NULL;
    }
    
    return 0;
}
