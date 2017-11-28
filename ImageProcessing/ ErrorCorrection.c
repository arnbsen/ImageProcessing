//
//  ErrorCorrection.c
//  ImageProcessing
//
//  Created by Arnab Sen on 15/08/16.
//  Copyright © 2016 Arnab Sen. All rights reserved.
//
#define NU -1
#include <stdio.h>
#include <stdlib.h>


int main(){
    int inp[10][10],ext[100],outr[200],out[200];
    int i,j,k,l,m,n,o,p,q;
    int con=32700;
    int temp,count,rst = 0,tempi=0,result=0;
    printf("Enter the dimension for the array\n");
    scanf("%d",&m);
    scanf("%d",&n);
    k=0;
    
    printf("Enter the array \n");
    for (i=0; i<m; i++) {
        for (j=0; j<n; j++) {
            printf("Enter inp[%d][%d]=",i,j);
            scanf("%d",&inp[i][j]);
            ext[k++]=inp[i][j];
        }
    }
    ext[k]=NU;
    l=0;
    for (i=0; i<k; i++) {
        if (ext[i]==NU) continue;
        outr[l++]=ext[i];
        temp =  ext[i];
        for (j=i+1; j<k; j++) {
            if (ext[j]<=(temp+5)&&ext[j]>=(temp-5)&&ext[j]!=NU) {
                outr[l++]=ext[j];
                ext[j]=NU;
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
    
   
    for (i=0; i<l; i++) {
        if (con==out[i]) {
            printf("\n");
            continue;
        }
        printf("%d ",out[i]);
    }
    
    
}
