#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
void qSort(int*,int,int);
void PrintMass(int*,int);
void main()
{
	int n,low,high;
	int *mass;
	printf("n=");
	scanf("%d", &n);
	low = 0;
	high = n-1;
	srand(time(0));
	mass = (int*) malloc (n*sizeof(int));
	for( int i = 0; i < n; i++ )
	{
		mass[i] = -50 + rand() % 100;
		printf( "%d " , mass[i] );
	}
	qSort(mass,low,high);
	PrintMass(mass,n);
	getch();
}
void qSort(int *mass, int low, int high)
{
	int i = low;
	int j = high;
	int m;
	m = mass[(low+high)/2];
	do 
	{
		while(mass[i] < m)
			i++; 
		while(mass[j] > m)
			j--;
		if(i <= j)
		{           
			int temp = mass[i];
			mass[i] = mass[j];
			mass[j] = temp;
			i++;
			j--;
		}
	} 
	while(i < j);
	if( low < j ) 
		qSort(mass,low,j);
	if(i < high) 
		qSort(mass,i,high);
}
void PrintMass(int *mass, int n)
{
	printf("\n");
	for( int i = 0; i < n; i++ )
	{
		printf( "%d " , mass[i] );
	}
}