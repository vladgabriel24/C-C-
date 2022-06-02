#include <stdio.h>
#include <stdlib.h>

struct tree{

    int x;
    struct tree *left;
    struct tree *right;
};

typedef struct tree BST;

BST *create_node(int x){

    BST *new_node=malloc(sizeof(BST));

    new_node->x=x;

    new_node->left=NULL;
    new_node->right=NULL;

    return new_node;
}

BST *insert_node(BST *tree , int x){

    if(tree==NULL)
    return create_node(x);

    if( x < tree->x )
    tree->left=insert_node(tree->left , x);
    else
    tree->right=insert_node(tree->right , x);

    return tree;
}

void inorder(BST *tree){

    if(tree==NULL)
    return;

    inorder(tree->left);
    printf("%d " , tree->x);
    inorder(tree->right);
}

int main(){

    BST *tree=NULL;

    int n;
    scanf("%d" , &n);

    int x;
    for(int i=0 ; i<n ; i++){

        scanf("%d" , &x);
        tree=insert_node(tree , x);
    }

    inorder(tree);

    // Complexitate : O(height tree)




    return 0;
}