#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
void MergeMass (int*,int,int,int);
void MergeSort(int*,int,int);
void PrintMass(int*, int);
void main()
{
	int n;
	int *mass;
	printf("n=");
	scanf("%d", &n);
	srand(time(0));
	mass = (int*) malloc (n*sizeof(int));
	for( int i = 0; i < n; i++ )
	{
		mass[i] = -50 + rand() % 100;
		printf( "%d " , mass[i] );
	}
	MergeSort(mass,0,n-1);
	PrintMass(mass,n);
	getch();
}
void MergeMass (int* SourceMass,int left,int middle,int right)
{
	int* masstM = new int[right-left];
	int i = left;
	int j = middle+1;
	int ni = 0;
	for (int z = left; z <= right; z++)
	{
		if(i > middle)
		{
			masstM[ni] = SourceMass[j];
			j++;
		}
		else 
			if(j > right)
			{
				masstM[ni] = SourceMass[i];
				i++;
			}
			else
				if(SourceMass[i] < SourceMass[j])
				{
					masstM[ni] = SourceMass[i];
					i++;
				}
				else
				{
					masstM[ni] = SourceMass[j];
					j++;
				}
				ni++;
	}
	for(int c = 0; c <= right-left; c++)
		SourceMass[c+left] = masstM[c];
}
void MergeSort(int* SourceMass,int left,int right)
{
	if(left >= right)
		return;
	int mid = (right+left)/2;
	MergeSort(SourceMass,left,mid);
	MergeSort(SourceMass,mid+1,right);
	MergeMass(SourceMass,left,mid,right);
}
void PrintMass(int *mass, int n)
{
	printf("\n");
	for( int i = 0; i < n; i++ )
	{
		printf( "%d " , mass[i] );
	}
}