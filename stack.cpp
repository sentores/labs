#include <stdlib.h>
#include <conio.h>
#include <iostream>
using namespace std;


/*! @struct stacked
    @brief struct for elements of stack
    @param *mass - pointer to massive of elements
    @param tmp - variable that used to save popped elements
	@param n - number of elements of queue
*/

struct stacked
{
   int* stack;
   int tmp;
   int n;
} st;


/*! @fn void push(int var)
    @brief push element to stack
    @param var - element that will be added to queue
    @return void
*/

void push(int var)
{
	st.n++;
	st.stack = (int*)realloc(st.stack,st.n*sizeof(int));
	st.stack[st.n] = var;
}


/*! @fn int pop()
    @brief pop element from stack
    @return st.tmp
*/

int pop()
{
	if( st.n == 0 )
		st.tmp = 0;
	else
	{
		st.tmp = st.stack[st.n];
		st.n--;
	}
	return st.tmp;	
}


/*! @fn int top()
    @brief return the top of stack
    @return st.stack[st.n];
*/

int top()
{
	if( st.n == 0 )
		st.stack[st.n] = 0;
	else
		return st.stack[st.n];
}
int main()
{
	st.stack = (int*)malloc(0*sizeof(int));
	int tmp = 0;
	int var = 0;
	int ctmp = 0;
	st.n = 0;
	do                                                                  /// cycle to cteate a simple menu
	{
		cout << "\nChose the opertion:(write down the number of it) ";
		cout << "\n1. Push a number to stack ";
		cout << "\n2. Pop the element from stack";
		cout << "\n3. Show the top of stack";
		cout << "\n4. Exit programm\n";
		cin >> tmp;
		switch(tmp)
		{
		case 1 :
			cout << "\nWrite down a number: ";
			cin >> var;
			push(var);
			cout << "\nElement added to stack \n";
			getchar();
			break;
		case 2 :
			ctmp = pop();
			if (ctmp == 0)
				cout << "\nYou can't pop element from empty stack \n";
			else
				cout << "\nElement popped from stack \n";
			getchar();
			break;
		case 3 :
			ctmp = top();
			if (ctmp == 0)
				cout << "\nThe stack is empty \n";
			else
				cout << "\nThe top of stack is: " << ctmp << "\n";
			getchar();
			break;
		case 4:
			return 0;
			free(st.stack);
			break;
		default:
			cout << "\nError! You must write 1,2,3 or 4! \n";
			getchar();
			getchar();
			return 0;
		}
	}
	while(1);
}