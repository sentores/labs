#include <stdlib.h>
#include <conio.h>
#include <iostream>
using namespace std;


/*! @struct queue
    @brief struct for elements of queue
    @param start - pointer to start of queue
    @param end - pointer to end of queue
	@param *mass - pointer to massive of elements
	@param n - number of elements of queue
*/

struct queue
{
	int start;
	int end;
	int* mass;
	int n;
}q;


/*! @fn void init()
    @brief initialization of queue
    @return void
*/

void init()
{
	q.start = q.n;
	q.end = q.start;
}


/*! @fn int add(int var, int f)
    @brief add element to queue
    @param var - element that will be added to queue
    @param f - flag that will change when the queue is empty
    @return f
*/

int add(int var, int f)
{
	if (f == 1)
	{
		printf("\nError! Queue is overflowed!\n");
	}
	else
	{
		q.mass[q.end] = var;
		if(q.end == 0)
		{
			if(q.start == q.n)
				f = 1;
			else
				q.end = q.n;
		}
		else
			q.end--;
		if((q.end)-(q.start) == 1)
			f = 1;
	}
	return f;
}


/*! @fn int extract(int var)
    @brief pop element from queue
    @param var - variable that used to save popped element
    @return var
*/

int extract(int var)
{
	if(q.start == q.end)
	{
		var = 0;
	}
	else
	{
		var = q.mass[q.start];
		q.start--;
	}
	return var;
}
int main()
{
	int f = 0, tmp = 0, var = 0;
	q.n = 0;
	cout << "Enter the length of queue: ";
	cin >> q.n;
	q.n --;
	q.mass = (int*)malloc(q.n*sizeof(int));
	init();                                                 /// initializate queue
	do                                                      /// cycle to cteate a simple menu
	{
		cout << "\n Enter the number of point:\n";
		cout << "\n1. Add element to the queue";
		cout << "\n2. Pop element from the queue";
		cout << "\n3. Exit program\n";
		cin >> tmp;
		switch(tmp)
		{
		case 1:
			cout << "\n Write down the element that you want to add: ";
			cin >> var;
			f = add(var, f);
			break;
		case 2:
			var = extract(var);
			if(var == 0)
				cout << "\nError! You can't pop element from empty queue!\n";
			else
				cout << "\n You popped that element from the queue: " << var;
			_getch();
			break;
		case 3:
			return 0;
			break;
		default:
			cout << "\n Error! You must write 1,2 or 3";
			_getch();
			return 0;
			break;
		}

	}
	while (1);
}