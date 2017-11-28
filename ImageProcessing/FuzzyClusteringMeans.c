//
//  FuzzyClusteringMeans.c
//  ImageProcessing
//
//  Created by Arnab Sen on 02/02/17.
//  Copyright © 2017 Arnab Sen. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float cen[4], memmato[4][539220];
float memmatn[4][539220];
float mem_val(int a, float cen[], int j){
    float d=0.0000,m;
    
    for (int k=0; k<4; k++) {
         m = (fabs((float)a-cen[j]))/(fabs((float)a-cen[k]));
	d = d + m*m;
    }
    
    return (1/d);
}
float centroid(int a[], int i, int no){
    float n=0.00000,d = 0.00000;
    for (int j =0; j<no; j++) {
        n += memmatn[i][j]*memmatn[i][j]*a[j];
        d += memmatn[i][j]*memmatn[i][j];
    }
    return n/d;
}
int check(int row, int col){
    int flag=1;
    for (int i =0; i<row; i++) {
        for (int j=0; j<col; j++) {
            if (fabs(memmato[i][j]-memmatn[i][j]) < 0.01) {
                flag = 0;
            }
            else{
                
               return 1;
                
            }
        }
    }
    return flag;
}
void copy(int row, int col){
    for (int i =0; i<row; i++) {
        for (int j=0; j<col; j++) {
            memmato[i][j] = memmatn[i][j];
        }
    }
}
int inparr[539220],in;

int main(){
    FILE *inp,*out;
    char head[10];
        float maxn;
    
    int i,j,m;
    inp = fopen("/Users/arnabsen/Desktop/FileHandling/sardinia_DI.pgm", "r");
    out = fopen("/Users/arnabsen/Desktop/FileHandling/sardinia_DI_fcm.pgm", "w");
    if (inp == NULL) {
        printf("File doesn't exist\n");
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
    // Logic.
    for (i=0; i<4; i++) {
        for (j=0; j<539220; j++) {
            memmatn[i][j] = (float)rand()/(float)((unsigned)RAND_MAX+1);
        }
    }
    
    do{
        copy(4, 539220);
        for (j = 0; j<4; j++) {
            cen[j] = centroid(inparr, j, 539220);
        }
        
        for (i = 0; i<4; i++) {
            for (j=0; j<539220; j++) {
                memmatn[i][j] = mem_val(inparr[j], cen, i);
            }
        }
        for (int k=0; k<4; k++) {
            printf("%f ",cen[k]);
        }
        printf("\n");
        
    }while (check(4, 539220));
    printf("Writing File. Please Wait\n");
    fprintf(out, "P2 860 627 255 ");
    for (i=0; i<539220; i++) {
        maxn = -9999;
        in = 0;
        for (j=0; j<4; j++) {
                if (memmatn[j][i]>maxn) {
                maxn = memmatn[j][i];
                in = j;
            }
        }
        fprintf(out, "%d ",(int)cen[in]);
        
    }
    
}
