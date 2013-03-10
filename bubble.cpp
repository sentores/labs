#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
void SortMass(int*, int);
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
	SortMass(mass,n);
	PrintMass(mass,n);
	getch();
}
void SortMass(int *mass, int n)
{
	int tmp,t = 0;
	do
	{
		for( int i = n-1; i > t; i-- )
		{
			if( mass[i-1] > mass[i] )
			{
				tmp = mass[i];
				mass[i] = mass[i-1];
				mass[i-1] = tmp;
			}
		}
		t++;
	}
	while ( t < n  );
}
void PrintMass(int *mass, int n)
{
	printf("\n");
	for( int i = 0; i < n; i++ )
	{
		printf( "%d " , mass[i] );
	}
}