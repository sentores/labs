#include <iostream>
#define EXIT_WHILE 7                                /// const for break infinite loop


/*! @struct leaf
    @brief struct for elements of tree
    @param val - value of leaf
    @param *parent - pointer to parent
    @param *lchild - pointer to left child
    @param *rchild - pointer to right child
*/

struct leaf
{
	int val;
	leaf *parent;
	leaf *lchild;
	leaf *rchild;
};


/*! @fn void createTree(leaf *root)
    @brief this function creating tree
    @param *root - pointer to root of tree
    @return void
*/

void createTree(leaf *root)
{
	short f = NULL;
	printf ("\nLet\'s create binar tree.");
	printf ("\n....Input value of root: ");
	scanf ("%d", &(root->val));
	while (1)
	{
		switch (give_cF(root))	                    /// give flag
		{
		case 1:
			root = crt_lchild(root);	            /// create left child
			break;
		case 2:
			root = crt_rchild(root);	            /// create right child
			break;
		case 3:
			root = up_root(root);	                /// go up to parent
			break;
		case 0:
			f = EXIT_WHILE;	                        /// stop creating
			break;
		default:
			break;
		}
		if (f == EXIT_WHILE) 
			break;
	}
}


/*! @fn void delTree(leaf *root)
    @brief delete tree
	@param *root - pointer to root of tree
	@return void
*/

void delTree(leaf *root)
{
	if(!root)
		return;
	delTree(root->lchild);
	delTree(root->rchild);
	if(root->val)
	{
		printf("\n....deleting (%d)", root->val);
		delete root;
	}
}


/*! @fn int giveVal()
    @brief give value of leaf
    @return int 
*/

int giveVal()
{
	int val;
	printf ("....value of leaf: ");
	scanf("%d", &val);
	return val;
}


/*! @fn int giveMF()
    @brief give value of command for main menu
    @return int 
*/

int giveMF()
{
	int f = 11;
	while (f != 2 && f != 1 && f != 0)
	{
		printf ("\n# Create tree\t\t[input: 1]");
		printf ("\n# Print tree\t\t[input: 2]");
		printf ("\n# Destroy and exit\t[input: 0]");
		printf ("\n#\tCommand: "); scanf("%d", &f);
		printf(" ");
	}
	return f;
}


/*! @fn int giveCF(leaf *nowRoot)
    @brief give value of command for menu of creating tree
    @param *curRoot - pointer to the leaf of the tree with which  program works
    @return int
*/

int giveCF(leaf *curRoot)
{
	int f = 11;
	while (f != 3 && f !=2 && f != 1 && f != 0)
	{
		printf ("\n# Add left leaf for\t(%d)\t[input: 1]",curRoot->val);
		printf ("\n# Add right leaf for\t(%d)\t[input: 2]",curRoot->val);
		if(curRoot->parent == NULL)
			printf ("\n# Up to root\t\t(--)\t[No parent]");
		else
			printf ("\n# Up to root\t\t(%d)\t[input: 3]",curRoot->parent->val);
		printf ("\n# Exit to main menu\t\t[input: 0]");
		printf ("\n#\tCommand: ");
		scanf("%d", &f);
	}
	return f;
}
/*! @fn leaf* upRoot(leaf *root)
    @brief Moves the user to a higher level
	@param *root - pointer to the leaf of the tree whith which the program works
	@return leaf root - adrees of this leaf in memory.
*/
leaf* upRoot(leaf *root)
{
	if (root->parent)
	{
		printf("....now you at leaf \t(%d)\n", root->parent->val);
		return root->parent;
	}
	else
	{
		printf("....now you at leaf (%d), (%d) - ROOT of all tree!\n", root->val, root->val);
		return root;
	}
}
/*! @fn leaf* crt_lchild(leaf *parent)
    @brief create left child for current leaf
	@param *parent - pointer to the leaf of the tree with which the program works
	@return tmpchild - adress of child in memory
*/
leaf* crt_lchild(leaf *parent)
{
	leaf *tmpchild;
	tmpchild = new leaf;
	if (parent->lchild)	                          /// if we already have child
	{
		delete tmpchild;
		printf ("....parent (%d) has left child (%d)", parent->val, parent->lchild->val);
		printf ("\n....return pointer to left child (%d)\n", parent->lchild->val);
		return parent->lchild;
	}
	parent->lchild = tmpchild;
	tmpchild->parent = parent;
	tmpchild->val = giveVal();
	tmpchild->lchild = NULL;
	tmpchild->rchild = NULL;
	return tmpchild;
}


/*! @fn leaf* crt_rchild(leaf *parent)
    @brief create right child for current leaf
	@param *parent - pointer to the leaf of the tree with which the program works
	@return tmpchild - adress of child in memory
*/

leaf* crt_rchild(leaf *parent)
{
	leaf *tmpchild;
	tmpchild = new leaf;
	if (parent->rchild)	                          /// if we already has son
	{
		delete tmpchild;
		printf ("....parent (%d) has right son (%d)", parent->val, parent->rchild->val);
		printf ("\n....return pointer to right son (%d)\n", parent->rchild->val);
		return parent->rchild;
	}
	tmpchild->val = giveVal();
	tmpchild->parent = parent;
	tmpchild->lchild = NULL;
	tmpchild->rchild = NULL;
	parent->rchild = tmpchild;
	return tmpchild;
}


/*! @fn void simOrder(leaf *root)
    @brief print tree in simmetric order.
	@param *root - pointer to root of tree.
	@return void
*/

void simOrder(leaf *root)
{
	if(!root) 
		return;
	simOrder(root->lchild);
	if(root->val) printf("%d ", root->val);
	simOrder(root->rchild);
}


/*! @fn void dOrder(leaf *root)
    @brief print tree in direct order.
	@param *root - pointer to root of tree.
	@return void
*/

void dOrder(leaf *root)
{
	if(!root) 
		return;
	if(root->val) printf("%d ", root->val);
	dOrder(root->lchild);
	dOrder(root->rchild);
}


/*! @fn void revOrder(leaf *root)
    @brief print tree in reverse order.
	@param *root - pointer to root of tree.
	@return void
*/

void revOrder(leaf *root)
{
	if(!root) 
		return;
	revOrder(root->lchild);
	revOrder(root->rchild);
	if(root->val) printf("%d ", root->val);
}


/*! @fn void print_tree(leaf* root)
    @brief print tree in different orders
	@param *root - pointer to root of tree
	@return void
*/

void printTree(leaf* root)
{
	printf("\nPrinted tree:");
	printf("\nSimmetric order:\t");
	simOrder(root);
	printf("\nDirect order:\t\t");
	dOrder(root);
	printf("\nBack order:\t\t");
	revOrder(root);
	printf("\n");
}
int main ()
{
	short f = 11;	                              /// flag for menu
	leaf *root;	                                  /// root of tree
	root = new leaf;
	root->parent = NULL;	                      /// totaly null root of tree
	root->lchild = NULL;	                      
	root->rchild = NULL;	                      
	root->val = NULL;	                          
	while(1)
	{
		switch (giveMF())	                      /// give flag
		{
		case 1:
			createTree(root);	                  /// calling creating function
			printf("\n....tree was created");
			break;
		case 2:
			printTree(root);	                  /// calling printing functiom
			break;
		case 0:
			delTree(root);	                      /// calling deleting function
			printf("\n....tree was deleted");
			f = EXIT_WHILE;	                      /// exit
			break;
		}
		if (f == EXIT_WHILE)
			break;
	}
	getchar();
	getchar();
}