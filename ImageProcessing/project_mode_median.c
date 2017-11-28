//
//  project_mode_median.c
//  ImageProcessing
//
//  Created by Arnab Sen on 04/10/16.
//  Copyright © 2016 Arnab Sen. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
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
int median(int* a, int n1){
    int i,j,m;
    for (i=1; i<n1; i++) {
        j=i;
        while (j>0) {
            if (a[j]>a[j-1]) {
                break;
            }
            m=a[j];a[j]=a[j-1];a[j-1]=m;j--;
        }
        
    }
    for (i=0; i<9; i++) {
        printf("%d ",a[i]);
    }
    printf("\n");
    return a[4];
}
int main(){
    
    FILE *inp, *out;
    int farr[1001][1001],refarr[10], outarr[1001][1001];
    int i,j,k=0,l,m,res,temp,pos=0;
    char head[10],fileout[10000],filein[10000],tempstr[1000];
    printf("Enter the input filename\n");
    scanf("%s",tempstr);
    strcpy(filein, "/Users/arnabsen/Desktop/FileHandling/");
    strcat(filein, tempstr);
    strcat(filein, ".pgm");
    inp = fopen(filein, "r");
    // out = fopen("/Users/arnabsen/Desktop/FileHandling/ABC/prj2_air_edge.pgm", "w");
    if (inp == NULL) {
        printf("File doesn't exists\n");
        exit(0);
    }
    fread(head, 1, 2, inp);
    fscanf(inp, "%d",&m);
    fread(head, 1, 8, inp);
    // printf("No of elements %d",k);
    // m = sqrt((double)k);
    // m = k;
    // printf("/n%d ",m);
    // printf("Enter the size of one side\n");
    // scanf("%d",&m);
    
    // Picking up elements
    for (i=1; i<=m; i++) {
        for (j=1; j<=m; j++) {
            fscanf(inp, "%d",&temp);
            farr[i][j] = temp;
            //  printf("%d ",temp);
            
        }
        // printf("\n");
    }
    
    // Extending the array
    for (i=0; i<=m; i++) {
        farr[0][i] = farr[1][i];
        farr[m+1][i] = farr[m][i];
        farr[i][0] = farr[i][1];
        farr[i][m+1] = farr[i][m];
        
    }
    farr[0][0] = farr[1][1];
    farr[0][m+1] = farr[1][m];
    farr[m+1][0] = farr[m][1];
    farr[m+1][m+1] = farr[m][m];
    
    printf("Enter output filename\n");
    scanf("%s",tempstr);
    strcpy(fileout, "/Users/arnabsen/Desktop/FileHandling/");
    strcat(fileout, tempstr);
    strcat(fileout, ".pgm");
    
    /* Taking the ref. mat for evaluation
    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            printf("Enter the ref[%d][%d] value\n",i,j);
            scanf("%d",&refarr[i][j]);
        }
    }
     */
    printf("Enter your choice\n1.Median 2.Mode\n");
    scanf("%d",&res);
    // Logic
    for (i=1; i<=m; i++) {
        for (j=1;j<=m; j++) {
            pos=0;
            for (k=i-1; k<=i+1; k++) {
                for (l=j-1; l<=j+1; l++) {
                   refarr[pos++]= farr[k][l];
                                    }
            }
            switch (res) {
                case 1:
                    outarr[i][j] = median(refarr, 9);
                    break;
                case 2:
                    outarr[i][j] = findmode(refarr, 9);
                    break;
                    
                default:
                    break;
            }
            
        }
    }
    out = fopen(fileout, "w");
    
    
    // Final printing to file
    fprintf(out, "P2 %d %d 255 ",m,m);
    for (i=1; i<=m; i++) {
        for (j=1; j<=m; j++) {
            fprintf(out, "%d ",outarr[i][j]);
            //   printf("%d",outarr[i][j]);
        }
    }
    
    
    
    
}
