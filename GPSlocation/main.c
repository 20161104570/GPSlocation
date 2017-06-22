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
    int i;
    char c[70];
    char latitude[10];//纬度
    char longitude[15];//经度
    FILE *fp;
    fp = fopen("//Users//a20161104570//Desktop//GPSlocation//GPS170510.log","r");
    if (fp == NULL)
    {
        printf("File open error !\n");
        return -1;
    }
    else
    {
        fscanf(fp,"%s",c);
        printf("%s\n",c);
        for(i=0;i<8;i++)
            latitude[i] = c[i+16];
        for(i=0;i<9;i++)
            longitude[i]=c[i+27];
        printf("%s\n %s\n",latitude,longitude);
        fclose(fp);
        fp=NULL;
    }
    
    return 0;
}
