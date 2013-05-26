#include<iostream>
using namespace std;
#define TRUE 1
#define FALSE 0


/*! @struct	node
	@brief struct for elements of tree.
    @param count - value of leaf.
	@param key - key&
	@param *left - pointer to left child.
	@param *right - pointer to right child.
*/

struct  Node
{
  int key;
  int count;
  Node *left;
  Node *right;
};


class Tree
{
  private:
    Node *tree;							/// root of tree
    Node *res;							/// pointer to the found vertex
    int B;								/// sign of finding the top of the tree

	
/*! @fn		void search (int x,Node **p)
    @brief	search link x in a binary tree with priority			
	@param	node **p - pointer to the root
	@param	int x
*/
	void search (int x,Node **p)
	{
		if  (*p==NULL)						/// The top of the tree there, turn it on
		{
			*p = new(Node);
			(**p).key = x;  
			(**p).count = 1;
			(**p).left = (**p).right = NULL;
		}
		else
			if  (x<(**p).key) 
				search (x,&((**p).left));
			else
				if  (x>(**p).key)
					search (x,&((**p).right));
				else  (**p).count += 1;
	}


/*! @fn     void delete_1 (Node **r,Node **q)
    @brief	delete leaf	
	@param	node **r - pointer
	@param	node **q - pointer
*/

	void delete_1 (Node **r,Node **q)
	{
		Node *s;
		if  ((**r).right==NULL)
		{
			(**q).key = (**r).key; 
			(**q).count = (**r).count;
			*q = *r;
			s = *r;
			*r = (**r).left;
			delete s;
		}
		else 
			delete_1 (&((**r).right), q);
	}
  public:
    Tree() 
	{ tree = NULL;}
    Node** GetTree() 
	{return &tree;}
	void buildTree ()
	{
		int el;
		cout<<"Enter the key nodes of the tree:\n";
		cin>>el;
		while  (el!=0)
		{
			search (el,&tree);
			cin>>el;
		}
	}


/*! @fn void output (Node **x,int l)
    @brief	printing tree	
	@param	node **x - pointer to the root
	@param	int l
*/

	void output (Node **x,int l)
	{
		int i;
		if  (*x!=NULL)
		{
			output (&((**x).right),l+1);
			for  (i=1; i<=l; i++) 
				cout<<"   ";
			cout<<(**x).key<<endl;
			output (&((**x).left),l+1);
		}
	}


/*! @fn			int iSearch (int k)
    @brief	search virtex with link k
	@param	int k		
	@return	int B
*/

	int iSearch (int k)
	{
		Node *p;
		Node *q;
		B = FALSE; 
		p = tree;								/// pointer to tree
		if  (tree!=NULL)
			do
			{
				q = p;
				if  ((*p).key==k) 
					B = TRUE;
				else
				{
					q = p;
					if  (k<(*p).key)
						p = (*p).left;
					else  
						p = (*p).right;
				}
			} while  (!B && p!=NULL);
			res = q;							/// virtex
			return B;
	}


/*! @fn		Node* s_1 (int k,Node **p)
    @brief	search virtex with link k			
	@param	node **p - pointer to root
	@param	int k
*/
	Node* s_1 (int k,Node **p)
	{
		if  (*p==NULL) 
			return (NULL);
		else
			if  ((**p).key==k) 
				return (*p);
			else
				if  (k<(**p).key)
					return s_1 (k,&((**p).left));
				else 
					return s_1 (k,&((**p).right));
	}


/*! @fn		void addition (int k)
    @brief	search link k in a binary tree with priority			
	@param	int k
*/

	void addition (int k)
	{
		Node *s;
		iSearch (k);
		if  (!B)
		{
			s = new(Node);
			(*s).key  = k;  
			(*s).count = 1;
			(*s).left = (*s).right = NULL;
			if  (tree==NULL) 
				tree = s;
			else
				if  (k<(*res).key) 
					(*res).left = s;
				else  (*res).right = s;
		}
		else  (*res).count += 1;
	}


/*! @fn		void Delete (Node **p,int k)
    @brief	delete tree		
	@param	node **p - pointer to root
	@param	int k
*/
	void Delete (Node **p,int k)
	{
		Node *q;
		  if  (*p==NULL) 
			  cout<<"top with the specified key is not found\n";
		  else
			  if  (k<(**p).key)
				  Delete (&((**p).left),k);
			  else
				  if  (k>(**p).key)
					  Delete (&((**p).right),k);
				  else
				  {
					  q = *p;
					  if  ((*q).right==NULL) 
					  {
						  *p = (*q).left;
						  delete q;
					  }
					  else
						  if  ((*q).left==NULL)
						  { 
							  *p = (*q).right; 
							  delete q; 
						  }
						  else  
							  delete_1 (&((*q).left),&q);
				  }
	}
};
void main ()
{
  Tree a;
  int el;
  a.buildTree ();  
  a.output (a.GetTree(),0);
  cout<<"Enter the key top, you want to find in the tree:";	
  cin>>el;
  if  (a.iSearch (el)) 
	  cout<<"vertex exists\n";
  else
	  cout<<"vertex non-exists\n";
  cout<<"Enter the key top, you want to find in the tree:";  
  cin>>el;
  if  (a.s_1 (el,a.GetTree())!=NULL) 
	  cout<<"vertex exists\n";
  else
	  cout<<"vertex non-exists\n";
  cout<<"Enter the key tops added:";	
  cin>>el;
	  a.addition (el);  
	  a.output (a.GetTree(),0);
 cout<<"Enter the key removed the top:";	
 cin>>el;
 a.Delete (a.GetTree(),el);  
 a.output (a.GetTree(),0);
}