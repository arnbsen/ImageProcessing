//
//  clusterfilerep.c
//  ImageProcessing
//
//  Created by Arnab Sen on 24/08/16.
//  Copyright © 2016 Arnab Sen. All rights reserved.
//
#define NU -1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    
    FILE *fp1,*prs,*outf;
    int *arr, outr[100000],out[100000];
    int i = 0,j=0,k=0,l,p;
    int store;
    int con=32700;
    int temp,count =0,rst = 0,result=0;
    char swr[100];
    
    
    fp1=fopen("/Users/arnabsen/Desktop/FileHandling/abc.txt", "r+");
    prs=fopen("/Users/arnabsen/Desktop/FileHandling/prs.txt", "w+");
    outf=fopen("/Users/arnabsen/Desktop/FileHandling/outfile.txt", "w+");
    
    
    while (fscanf(fp1, "%d",&store)&&!feof(fp1)) {
        i++;
    }
    arr = (int*)malloc(i*sizeof(int));
    if (arr==NULL) {
        printf("Storage allocation failed\n");
    }
    fseek(fp1, 0, SEEK_SET);
    i=0;
    while (fscanf(fp1, "%d",&store)&&!feof(fp1)) {
        arr[k++]=store;}
    
    arr[k]=NU;
    l=0;
    for (i=0; i<k; i++) {
        if (arr[i]==NU) continue;
        outr[l++]=arr[i];
        temp =  arr[i];
        for (j=i+1; j<k; j++) {
            if (arr[j]<=(temp+5)&&arr[j]>=(temp-5)&&arr[j]!=NU) {
                outr[l++]=arr[j];
                arr[j]=NU;
            }
        }
        outr[l++]=con;
    }
    
    for (i=0; i<l; i++) {
        if (outr[i]==con) {
            continue;
        }
        result =0;
        for (j=i; outr[j]!=con; j++) {
            temp=outr[i];count=0;
            for (k=j; out[k]!=con; k++) {
                if (temp==outr[j]) {
                    count++;
                }
            }
            if (count>result) {
                result=count;
                rst=outr[i];
            }
        }
        
        
        for (p=i; outr[p]!=con; p++) {
            out[p]=rst;
        }
        out[p]=con;
        i=j-1;
    }
    fseek(fp1, 0, SEEK_SET);
    while (fgets(swr, 100, fp1)&&!feof(fp1)) {
        fputs(swr, prs);
        fseek(prs, -1, SEEK_CUR);
        fprintf(prs, "-1\n");
    }
    fputs(swr, prs);
    fprintf(prs, "-1");
    fseek(prs, 0, SEEK_SET);
    while (fscanf(prs, "%d",&temp)&&!feof(prs)) {
        if (temp==-1) {
            fprintf(outf, "\n");
            
            // printf("\n");
        }
        else{
            for (k=0; k<=i; k++) {
                if (temp==outr[k]) {
                    fprintf(outf, "%d ",out[k]);
                   // printf("%d ",out[k]);
                    break;
                }
            }
        }
            
    }
    
   remove("/Users/arnabsen/Desktop/FileHandling/prs.txt");
   
    
}
    
    
