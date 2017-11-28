//
//  projectassign2v2.c
//  ImageProcessing
//
//  Created by Arnab Sen on 04/10/16.
//  Copyright © 2016 Arnab Sen. All rights reserved.
//

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int main(){
    
    FILE *inp, *out;
    int farr[1001][1001],refarr[5][5], outarr[1001][1001];
    int i,j,k=0,l,m,ans,res,temp;
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
    m = m + 1;
    for (i=2; i<=m; i++) {
        for (j=2; j<=m; j++) {
            fscanf(inp, "%d",&temp);
            farr[i][j] = temp;
            //  printf("%d ",temp);
            
        }
        // printf("\n");
    }
    
    // Extending the array
    for (i=0; i<=m; i++) {
        farr[1][i] = farr[2][i];
        farr[m+1][i] = farr[m][i];
        farr[i][1] = farr[i][2];
        farr[i][m+1] = farr[i][m];
        
        farr[0][i] = farr[2][i];
        farr[m+2][i] = farr[m][2];
        farr[i][0] = farr[i][2];
        farr[i][m+2] = farr[i][m];
        
    }
    farr[0][0] = farr[2][2];
    farr[0][m+2] = farr[2][m];
    farr[m+2][0] = farr[m][2];
    farr[m+2][m+2] = farr[m][m];
    
    farr[1][1] = farr[2][2];
    farr[1][m+1] = farr[2][m];
    farr[m+1][1] = farr[m][2];
    farr[m+1][m+1] = farr[m][m];

    printf("Enter output filename\n");
    scanf("%s",tempstr);
    strcpy(fileout, "/Users/arnabsen/Desktop/FileHandling/");
    strcat(fileout, tempstr);
    strcat(fileout, ".pgm");
    
    // Taking the ref. mat for evaluation
    for (i=0; i<5; i++) {
        for (j=0; j<5; j++) {
            printf("Enter the ref[%d][%d] value\n",i,j);
            scanf("%d",&refarr[i][j]);
        }
    }

    // Logic
    for (i=1; i<=m; i++) {
        for (j=0;j<=m; j++) {
            res = 0;
            for (k=0; k<5; k++) {
                for (l=0; l<5; l++) {
                    res += refarr[k][l]*farr[i-2+k][j-2+l];
                }
            }

            
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
    out = fopen(fileout, "w");
    
    
    // Final printing to file
    fprintf(out, "P2 %d %d 255 ",m,m);
    for (i=2; i<=m+1; i++) {
        for (j=2; j<=m+1; j++) {
            fprintf(out, "%d ",outarr[i][j]);
            //   printf("%d",outarr[i][j]);
        }
    }
    
    
    
    
}
