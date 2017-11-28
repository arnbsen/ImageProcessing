#include<stdio.h>
#include<math.h>
#include<stdlib.h>
//#include<conio.h>
int input[1000][1000],final[1000][1000];
float p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12;
float f1,f2,f3,f4,ff;
int dec[20],m,n,i,j;
int max=0000,min=9999;
int main()
{
//scaning the file
	FILE *ptr,*fpt,*fpt1;
	printf("enter the limits of the input array");
	scanf("%d%d",&m,&n);
    	if((ptr=fopen("/Users/arnabsen/Desktop/FileHandling/lena1.txt","r"))==NULL)
			{
			printf("\n error!!1\n");
			exit(1);
			}
    //printing the input array
		for(i=1;i<=m;i++)
			{
			for(j=1;j<=n;j++)
				{
				fscanf(ptr,"%d",&input[i][j]);
			//	printf("%d ",input[i][j]);
				}
			}
printf("enter 10 decimal values between 2 and 1024\n");
for(i=1;i<=10;i++)
{
	scanf("%d",&dec[i]);
}
//calculating the p1,p2,p3 and p4 parameters 
p1=(((1-0)*dec[1])/1023)+0;
p2=(((1-p1)*dec[2])/1023)+p1;
p3=(((1-p2)*dec[3])/1023)+p2;
p4=1-(p1+p2+p3);

//calculating p4 and p5
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
          if(input[i][j]>max)
			{
				max=input[i][j];
			}	
		}
	}	//printf("max=%d",max);
	
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
		if(input[i][j]<min)
			{
			min=input[i][j];
			}
	}	
	}//printf("min=%d",min);
	int c=max;
	max=min;
	min=c;
	p5=min;
	p6=max;
	
	//calculating p7 
	p7=(((3-1)*dec[7])/1023)+1;
	//calculating p8 to p12
p8=(((1-0)*dec[8])/1023)+0;
p9=(((1-p8)*dec[9])/1023)+p8;
p10=(((1-p9)*dec[10])/1023)+p9;
p11=(((1-p10)*dec[11])/1023)+p10;
p12=1-(p8+p9+p10+p11);
printf("the 12 parameters are\n");
printf("%f  %f  %f  %f  %f  %f  %f  %f  %f  %f  %f  %f  ",p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12);

//calculating the functions
for(i=1;i<=m;i++)
{
	for(j=1;j<=n;j++)
	{
	f1=(input[i][j]*input[i][j])/(p1+(input[i][j]*input[i][j]));
	f2=pow((1+(pow(((p6-p5)/p6),p7))),-1);
	if(input[i][j]>p5)
	{
		f3=p2*((input[i][j]-p5)*(input[i][j]-p5))+p3+p4;
		}	
		else
		{
		f3=0;
	}
	f4=(1/p6)*pow((p6-(p6*(p6/input[i][j]+p8)-1)),-p7);
	ff=p9*f1+p10*f2+p11*f3+p12*f4;
	//printf("%f %f %f %f",f1,f2,f3,f4);
	final[i][j]=p6*ff;
	printf("%d",final[i][j]);
}
}
//printing the final matrix
for(i=1;i<=m;i++)
{
	for(j=1;j<=n;j++)
	{
		printf("%d ",(int)fin [i][j]);
	}
}
//getting the image
	printf("the image is....");
	fpt=fopen("/Users/arnabsen/Desktop/output_1994.pgm","w");
	fprintf(fpt, "P2 %d %d 255",m,n);
	for(i=1;i<=m;i++)
    for(j=1;j<=n;j++)
    fprintf(fpt," %d ",(int)final[i][j]);
    fclose(fpt);
		
}
