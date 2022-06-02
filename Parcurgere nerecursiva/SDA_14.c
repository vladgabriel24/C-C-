#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

#define MAX_DIM 7		// the maximum # of elements in stack (it depends on the requirements of the problem)

typedef unsigned int UI;

typedef struct Node
{
	int data;
	struct Node *next;
} NODE, *pNODE;

typedef struct List
{
	int data;
	int repetitions;	// # of apparitions of the same node (value)
	NODE ln;	// list node
	struct List *left;
	struct List *right;
}BST, *pBST;

// functions declarations
void ins_BST(pBST*, int);
void inOrder(pBST);
void inOrder_iterative(pBST);

void stack_push(pNODE*, pNODE, int, int*);
pNODE stack_pop(pNODE*, pNODE*, int*);
bool stack_isFull(int);
//bool stack_isEmpty(pNODE);
bool stack_isEmpty(int);

int main()
{
 	int values[] = {17, 1, 34, 4, 5, 6, 7};
	UI len = sizeof(values)/sizeof(int);
	pBST root = NULL;

	for(UI i=0; i<len; i++)
		ins_BST(&root, values[i]);

	// the recursive version
	inOrder(root);
	puts("");

	// the iterative version
	inOrder_iterative(root);

 	return 0;
}

// Stack
void stack_push(pNODE *topStack, pNODE p, int val, int *pLen) 	// push
{
		pNODE q = (pNODE) malloc(sizeof(NODE));
		assert( q != NULL );
		
		q->data = val;	// information of the new node

		if( stack_isFull(*pLen) )
		{
			puts("Stiva este plina!");
			exit(EXIT_FAILURE);		// ieșire forțată din program (use error codes)
		}

		if( p == NULL )	// convenția pentru inserarea la începutul listei
		{
			q->next = *topStack;
			*topStack = q; 	// actualizarea nodului de inceput
			(*pLen)++;		// pt fiecare inserare lungimea crește (cu 1)
		} else {
			puts("Inserarea se face doar la inceput!");
			exit(EXIT_FAILURE);
		}
}

pNODE stack_pop(pNODE *topStack, pNODE *p, int *pLen)		// pop
{	
	pNODE q;
	
	//if( stack_isEmpty(*topStack) )
	if( stack_isEmpty(*pLen) )
	{
		puts("Stiva vida! Nu se poate sterge element…");
		exit(-1);	// ieșire forțată din program
	}

	if( p == NULL )		// convenția pt. ștergerea primului nod
	{
	 	q = *topStack;
		*topStack = (*topStack)->next;	// al doilea nod devine primul
		(*pLen)--;		// pt fiecare ștergere lungime scade (cu 1)
	} else {
		puts("Nu se poate sterge decat la varf!");
		exit(EXIT_FAILURE); // închei forțat programul (cod de eroare)
	}
	return q;	// save the address of the ex-first node
	free(q);
}

bool stack_isFull(int length)
{
	if( length == MAX_DIM ) return true;
	return false;
}

//bool stack_isEmpty(pNODE topStack)
bool stack_isEmpty(int length)
{
	if( length == 0 ) return true;
	return false;

#if 0
	if( topStack == NULL ) return true;
	return false;
#endif
}

// BST
void ins_BST(pBST *pRoot, int val)
{
	pBST nod1, nod2, nod3;
 
	nod1 = (pBST) malloc(sizeof(BST));
	assert(nod1 != NULL);

	nod1->ln.data = val;

	// insert the new node as leaf
	nod1->left = NULL;
	nod1->right = NULL;

	/* verificam mai intai daca exista o radacina (daca arborele a fost creat) */
	if( *pRoot == NULL )
	{
		*pRoot = nod1;
	} else { 
	  	nod2 = *pRoot;
		do {
			/* vlad: avansez la stanga (daca: val < val_nod) */
			if (val < nod2->data) {
			   nod3 = nod2; 
			   nod2 = nod2->left;
			} else {	/* se merge spre dreapta (daca: val_de_inserat > val_nod) */
				nod3 = nod2;
				nod2 = nod2->right;
			}
		} while (nod2 != NULL); 

		if (val < nod3->data)
		   	nod3->left = nod1;
		else
			nod3->right = nod1;
	}
	return;
}

void inOrder(pBST pRad)
{
	if ( pRad != NULL )
	{
	   inOrder(pRad->left);
	   fprintf(stdout, "%2d (recr) ", pRad->ln.data);
	   inOrder(pRad->right);
	}
	return;
}

void inOrder_iterative(pBST root)
{
	int length;
	pNODE topStack = NULL;
	pNODE p;	// retains the result from stack_pop
	pBST parent;

	//pBST s = (pBST)malloc(sizeof(BST));
	//assert( s != NULL );

	length = 0;
	while (true)
	{
		// Go to the left extreme insert all the elements to stack
		while( root != NULL )
		{
			stack_push(&topStack, NULL, root->ln.data, &length);
			printf("len(push stack): %u\n", length);

			parent = root;	// backup of the entry just before stepping onto a NULL link
			root = root->left;
		}

		// check if Stack is empty, if yes, exit from everywhere
		// if( stack_isEmpty(topStack) )
		if( stack_isEmpty(length) )
		{
			return;
		}

		// pop the element from the stack ...
		p = stack_pop(&topStack, NULL, &length);

		// ... print it ...
		root = parent;	// otherwise root is NULL (the while above ends w/ root as NULL)
		root->ln = *p;	// store the content of the returned node from pop() in the NODE field of the BST node (!)
		root->data = p->data;	// after stack_pop() ends, the argument p contains the ex-top node
		free(p);		// this should've appeared within stack_pop() function (!)
		printf("%2d (iter) ", root->ln.data);

		// ... and add the nodes at the right to the Stack
		root = root->right;		// follow the right subtree (and obey the same rules as above)

		printf("len(pop stack): %u\n", length);
	}
}
