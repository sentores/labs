#include <iostream>
#define uint unsigned int
using namespace std;

int	f[11];	/// array of flags
uint c[11][11];
uint l[11];


/*! @fn int min(int n)
    @brief give value of the minimal of two points.
    @param n-  number of tops in graph.
    @return int
*/

int min(int n)
{
	int i, res;
	for(i=0;i<n;i++)
	{
		if(!(f[i]))
			res=i;
	}
	for(i=0;i<n;i++)
	{
		if((l[res]>l[i])&&(!f[i]))
			res=i;
	}
	return res;
}


/*! @fn uint minimal(uint x, uint y)
    @brief give value of the largest of the two.
    @param x - uint x.
    @param y - uint y.
    @return uint 
*/

uint minimal(uint x, uint y)
{
	if(x<y)
		return x;
	return y;
}

int main()
{
	int n;	                   /// number of tops
	int p;
	int xn;
	int xk;
	char s[80];	               /// buffer massive
	char path[80][11];	       /// massive for paths between points
	cout << "Enter number of tops: "; 
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			c[i][j] = 0;
	}
	for( int i = 0; i < n; i++)
	{
		for(int j = i+1; j < n; j++)
		{
			cout << "Distance from x"<< i+1 <<" to x"<<j+1<<":";
			cin >> c[i][j];
		}
	}
	cout << endl;
	for(int i = 0; i < n; i++)
	{
		cout<<"\tx"<<i+1;
	}
	cout<<endl;
	for(int i = 0; i < n; i++)
	{
		printf("x%d",i+1);
		for(int j = 0; j < n; j++)
		{
			printf("\t%d",c[i][j]);
			c[j][i] = c[i][j];
		}
		cout<<endl<<endl;
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			if(c[i][j] == 0)
				c[i][j] = 65535;
	}

	cout<<"Enter start point: x";
	cin>> xn;
	cout<<"Enter end point: x";
	cin>> xk;
	xk--;
	xn--;
	if(xn == xk)
	{
		cout<<"Error! Start and end points must be different"<<endl;
		getchar();
		getchar();
		return 0;
	}
	for(int i = 0; i < n; i++)
	{
		f[i] = 0;
		l[i] = 65535;
	}
	l[xn] = 0;
	f[xn] = 1;
	p = xn;
	_itoa_s(xn+1,s,10);
	for(int i = 1; i <= n; i++)
	{
		strcpy_s(path[i],"x");
		strcat_s(path[i],s);
	}
	do
	{
		for(int i = 0; i < n; i++)
		{
			if((c[p][i] != 65535) && (!f[i]) && (i != p))
			{
				if(l[i] > (l[p]+c[p][i]))
				{
					_itoa_s(i+1,s,10);
					strcpy_s(path[i+1],path[p+1]);
					strcat_s(path[i+1],"-x");
					strcat_s(path[i+1],s);
				}
				l[i] = minimal(l[i], l[p]+c[p][i]);
			}
		}
		p = min(n);
		f[p] = 1;
	}
	while(p != xk);
	if(l[p] != 65535)
	{
		cout<<"\npath between points: "<<path[p+1]<<endl;
		cout<<"\tpath length: "<<l[p]<<endl;
	}
	else
		cout<<"this path does not exist!"<<endl;
	getchar();
	getchar();
	return 0;
}


