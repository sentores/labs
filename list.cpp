#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


/*! @struct book
    @brief struct for book description
    @param *surname - pointer to surname of author
    @param *midname - pointer to midname of author
	@param *name - pointer to name of author
	@param *title - pointer to title of book
	@param *pub - pointer to publisher
    @param *year - pointer to year of publishing
	@param *number - pointer to number of pages
*/

struct book
{
	char* surname;
	char* midname;
	char* name;
	char* title;
	char* pub;
	char* year;
	char* number;
};


/*! @struct list
    @brief struct for elements of list
    @param dat - variable that contains information about book
    @param *head - pointer to head of list
	@param *tail - pointer to tail of list
	@param *next - pointer to next element of list
*/

struct list
{
	book dat;
	list* head;
	list* tail;
	list* next;
}l;


/*! void construct(list &l)
    @brief initialization of list
	@param l - pointer to list
    @return void
*/

void construct(list &l)
{
	l.head = NULL;
}


/*! bool check_empty(list l)
    @brief checking the list(empty or filled)
	@param l - pointer to list
    @return bool
*/

bool check_empty(list l)
{
	return (l.head==NULL);
}
void add(list &l);
void view(list l);
void write(list &l);
void main()
{
	char x;
	list data;
	construct(data);
	printf("Add new book? (y/n)");
	x=getchar();
	while ( x != 'n')                                          ///cycle to add the books into list
	{
		if ( x == 'y')
		{
				add(l);
				printf("Add new book? (y/n)");
		}
		x = getchar();
	}
	write(l);
	printf(" List saved ");
	getch();
}


/*! void add(list &l)
    @brief add the book to list
	@param l - pointer to list
    @return void
*/

void add(list &l)
{
	book nov;
	list* c;
	c =(list*)malloc(sizeof(list));
	printf("      New book:");
	printf("\nAuthor's surname:");
	scanf("%s", nov.surname);
	printf("Author's name:");
	scanf("%s", nov.name);
	printf("Author's midname:");
	scanf("%s", nov.midname);
	printf("\tTitle:");
	scanf("%s", nov.title);
	printf("Publisher:");
	scanf("%s", nov.pub);
	printf("Year of publish:");
	scanf("%s", nov.year);
	printf("Number of pages:");
	scanf("%s", nov.number);
	c->dat = nov;
	c->next = NULL;
	if (check_empty(l))
		l.head = c;
	else
		l.tail->next = c;
	l.tail = c;
}


/*! void write(list &l)
    @brief write the list to the file
	@param l - pointer to list
    @return void
*/

void write(list &l)
{
	list *p;
	p = l.head;
	FILE *mein;
	mein=fopen("books.txt", "wb");
	while ( p != NULL )
	{
		fwrite(&(p->dat.surname),sizeof(book),1,mein);
		fwrite(&(p->dat.midname),sizeof(book),1,mein);
		fwrite(&(p->dat.name),sizeof(book),1,mein);
		fwrite(&(p->dat.title),sizeof(book),1,mein);
		fwrite(&(p->dat.pub),sizeof(book),1,mein);
		fwrite(&(p->dat.year),sizeof(book),1,mein);
		fwrite(&(p->dat.number),sizeof(book),1,mein);
		p = p->next;
	}
	fclose(mein);
}