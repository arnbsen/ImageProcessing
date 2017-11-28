//
//  kmeans1.c
//  Created by Arnab Sen on 27/09/16.
//  Copyright © 2016 Arnab Sen. All rights reserved.
//

//  ImageProcessing
//
#include <stdio.h>
#include <stdlib.h>
int check(int* m, int* n){
    int a=1,i;
    for (i=0; i<4; i++) {
        if (m[i]==n[i]) {
            a = 0;
        }
        else {a =1;}
    }
    return a;

}
int max(int* a, int n){
    int max = 0,i;
    for (i=0; i<n; i++) {
        max = max>a[i]?max:a[i];
    }
    return max;
}
int minf(int* a, int n){
    int max = 0,i;
    for (i=0; i<n; i++) {
        max = max<a[i]?max:a[i];
    }
    return max;
}
int findmode(int* a,int lt){
    int i,j,res=0,count,temp,md = 0;
    for (i=0; i<lt; i++) {
        temp = a[i]; count = 0;
        for (j=0; j<lt; j++) {
            if (temp==a[j]) {
                count++;
            }
        }
        if (count>res) {
            res = count;
            md = temp;
        }
    }
    return md;
}
int main(){

    FILE *inp,*out;
    char head[10];
    int inparr[262144];
    int mda1[262144],mda2[262144],mda3[262144],mda4[262144],mdarri[10][2];
    int md[4],md1[4],mval = 0,rd = 0,min = 0,absv = 0;
    int i,j,k,m,t;
    inp = fopen("/Users/arnabsen/Desktop/FileHandling/airplanee.pgm", "r");
    out = fopen("/Users/arnabsen/Desktop/FileHandling/ABC/prj2_air_edge.pgm", "w");
    if (inp == NULL) {
        printf("File doesn't exists\n");
        exit(0);
    }
    
    // Reading the header of image file
    fread(head, 1, 2, inp);
    fscanf(inp, "%d",&m);
    fread(head, 1, 7, inp);
    i = 0;
    // Picking up the values
    while (!feof(inp)) {
        fscanf(inp,"%d",&inparr[i++]);
    }
    //Enter the modes
    printf("Enter the four modes\n");
    for (j=0; j<4; j++) {
        printf("Enter the mode for %d",j);
        scanf("%d",&mdarri[j][0]);mdarri[i][1] = 0;md1[j] = mdarri[j][0];}
        
    while (check(md, md1)) {
        for (j=0;j<4 ; j++) {
            md[j] = md1[j];
            mdarri[j][1] = 0;
            mdarri[j][0] = md1[j];
        }
    
    for (k=0; k<i; k++) {
        rd = inparr[k];min = 0; absv = 32000;
        for (j=0; j<4; j++) {
            if (abs(rd-mdarri[j][0])<absv) {
                mval = j;
                absv = abs(rd-mdarri[j][0]);
            }
        
        }
        if (mval==0) {
            mda1[mdarri[mval][1]] = rd;
            mdarri[0][1] +=1;
        }
        if (mval==1) {
            mda2[mdarri[mval][1]] = rd;
            mdarri[1][1] +=1;
        }
        if (mval==2) {
            mda3[mdarri[mval][1]] = rd;
            mdarri[2][1] +=1;
        }
        if (mval==3) {
            mda4[mdarri[mval][1]] = rd;
            mdarri[3][1] +=1;
        }
    }
    
    md1[0] = findmode(mda1, mdarri[0][1]);
    md1[1] = findmode(mda2, mdarri[1][1]);
    md1[2] = findmode(mda3, mdarri[2][1]);
    md1[3] = findmode(mda4, mdarri[3][1]);
        for (k=0; k<4; k++) {
            printf("%d %d ",md1[k],mdarri[k][1]);
        }
        printf("\n");
 }
    fprintf(out, "P2 %d %d 255 ",m,m);
    for (k=0; k<i; k++) {
        for (t=0; t<mdarri[0][1]; t++) {
            if (mda1[t]==inparr[k]) {
                
                fprintf(out, "%d ",md1[0]);
                break;
            }
        }
        for (t=0; t<mdarri[1][1]; t++) {
            if (mda2[t]==inparr[k]) {
                
                fprintf(out, "%d ",md1[1]);
                break;
            }
        }
        for (t=0; t<mdarri[2][1]; t++) {
            if (mda3[t]==inparr[k]) {
                
                fprintf(out, "%d ",md1[2]);
                break;
            }
        }
        for (t=0; t<mdarri[3][1]; t++) {
            if (mda4[t]==inparr[k]) {
                
                fprintf(out, "%d ",md1[3]);
                break;
            }
        }
    }
   /* fprintf(out, "P2 %d %d 255 ",m,m);
    for (k=0; k<i; k++) {
        fprintf(out, "%d ",outa[k]);
    }*/
}










