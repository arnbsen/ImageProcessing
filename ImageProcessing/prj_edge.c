//
//  projectass2.c
//  ImageProcessing
//
//  Created by Arnab Sen on 22/09/16.
//  Copyright © 2016 Arnab Sen. All rights reserved.
//  Works for fixed dimensions only.

#include <stdio.h>
#include <stdlib.h>
int main(){
    
    FILE *inp, *out;
    int farr[1001][1001],refarr[3][3], outarr[1001][1001];
    int i,j,k,l,m,ans,res,temp;
    
    inp = fopen("/Users/arnabsen/Desktop/FileHandling/airplanee.txt", "r");
    out = fopen("/Users/arnabsen/Desktop/FileHandling/ABC/prj2_air_edge.pgm", "w");
    if (inp == NULL) {
        printf("File doesn't exists\n");
        exit(0);
    }
    printf("Enter the size of one side\n");
    scanf("%d",&m);
    
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
    
    
    // Taking the ref. mat for evaluation
    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            printf("Enter the ref[%d][%d] value\n",i,j);
            scanf("%d",&refarr[i][j]);
        }
    }
    // Logic
    for (i=1; i<=m; i++) {
        for (j=0;j<=m; j++) {
            res = 0;
            res = refarr[0][0]*farr[i-1][j-1] + refarr[0][1]*farr[i-1][j] + refarr[0][2]*farr[i-1][j+1] + refarr[1][0]*farr[i][j-1]+ refarr[1][1]*farr[i][j] + refarr[1][2]*farr[i][j+1] + refarr[2][0]*farr[i+1][j-1] + refarr[2][1]*farr[i+1][j] + refarr[2][2]*farr[i+1][j+1];

            if (res>=255) {
                outarr[i][j] = 255;
            }
            else if (res<=0){
                outarr[i][j] = 0;
            }
            else{
                outarr[i][j] = res;
            }
        }
    }


    // Final printing to file
    fprintf(out, "P2 %d %d 255 ",m,m);
    for (i=1; i<=m; i++) {
        for (j=1; j<=m; j++) {
            fprintf(out, "%d ",outarr[i][j]);
         //   printf("%d",outarr[i][j]);
        }
    }




}