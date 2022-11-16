#include<stdio.h>
#include<stdlib.h>
int main()
{
	int ******p=NULL;
	int a1, a2, a3, a4, a5, a6;  // array dimention
	int i, j, k, l, m, n;

	printf("\nEnter the 6D-Array Size=");
	scanf("%d",&a6);

	printf("\nEnter the 5D-Array Size=");
	scanf("%d",&a5);

	printf("\nEnter the 4D-Array Size=");
	scanf("%d",&a4);

	printf("\nEnter the 3D-Array Size=");
	scanf("%d",&a3);

	printf("\nEnter the 2D-Array Size=");
	scanf("%d",&a2);

	printf("\nEnter the 1D-Array Size=");
	scanf("%d",&a1);

//step1:allocate the memory dynamically

	//allocate the memory for 6D Array
	p=(int******)malloc(a6*sizeof(int*****));

	if (p == NULL)
	{
		printf("\nNo more space available to allocate, Hence exiting...");
		exit(1);
	}

	//allocate the memory for 5D Array
	for(i=0;i<a6;i++)
		p[i]=(int*****)malloc(a5*sizeof(int****));

		//allocate the memory for 4D Array
	for(i=0;i<a6;i++)
		for(j=0;j<a5;j++)
			p[i][j]=(int****)malloc(a4*sizeof(int***));

		//allocate the memory for 3D Array
	for(i=0;i<a6;i++)
		for(j=0;j<a5;j++)
			for(k=0;k<a4;k++)
				p[i][j][k]=(int***)malloc(a3*sizeof(int**));

		//allocate the memory for 2D Array
	for(i=0;i<a6;i++)
		for(j=0;j<a5;j++)
			for(k=0;k<a4;k++)
				for(l=0;l<a3;l++)
					p[i][j][k][l]=(int**)malloc(a2*sizeof(int*));


	//allocate the memory for 1D Array
	for(i=0;i<a6;i++)
		for(j=0;j<a5;j++)
			for(k=0;k<a4;k++)
				for(l=0;l<a3;l++)
					for(m=0;m<a2;m++)
						p[i][j][k][l][m]=(int*)malloc(a1*sizeof(int));

	//step2: assigning the values to the Array
	for(i=0;i<a6;i++)
		for(j=0;j<a5;j++)
			for(k=0;k<a4;k++)
				for(l=0;l<a3;l++)
					for(m=0;m<a2;m++)
						for(n=0;n<a1;n++)
					p[i][j][k][l][m][n]=(i+j+k+l+m+n);

	//printing the values of an array
	printf("\nvalues of an Array");
	for(i=0;i<a6;i++)
	{
		for(j=0;j<a5;j++)
		{
			for(k=0;k<a4;k++)
			{
				for(l=0;l<a3;l++)
				{
					for(m=0;m<a2;m++)
				  {
					  printf("\n\n************ %d %d %d %d %d **************\n\n",i,j,k,l,m);
					for(n=0;n<a1;n++)
					  {
		printf("%3d\t",p[i][j][k][l][m][n]);
				      }
					printf("\n");
				   }
					printf("\n");
				}
				printf("\n");
			}
			printf("\n");
		}
		printf("\n");
	}

	//step3: Deallocate the Memory for 1D array
	for(i=0;i<a6;i++)
		for(j=0;j<a5;j++)
			for(k=0;k<a4;k++)
				for(l=0;l<a3;l++)
					for(m=0;m<a2;m++)
						free(p[i][j][k][l][m]);

	//Deallocate the memory for 2D array
	for(i=0;i<a6;i++)
		for(j=0;j<a5;j++)
			for(k=0;k<a4;k++)
				for(l=0;l<a3;l++)
		free(p[i][j][k][l]);

	//Deallocate the memory for 3D Array

	for(i=0;i<a6;i++)
		for(j=0;j<a5;j++)
			for(k=0;k<a4;k++)
				free(p[i][j][k]);

	//Deallocate the Memory for 4D Array
	for(i=0;i<a6;i++)
		for(j=0;j<a5;j++)
			free(p[i][j]);

	//Deallocate the memory for 5D Array
		for(i=0;i<a6;i++)
			free(p[i]);

		//Deallocate the memory for 6D Array
		free(p);
		p = NULL;

		return(0);
}