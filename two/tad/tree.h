#include <stdio.h>
#include <stdlib.h>

#include <stdbool.h>
#include <string.h>
 
struct tree {       
        char cpf[12];           /* 00000000000\0        */
        char name[15];
        char birth[9];          /* 00000000\0           */
                                                                                  
        struct tree *left;           
        struct tree *right;
};

void 	destroy_tree(struct tree *root);

void	itree(struct tree **root, char cpf[], char name[], char birth[]);
struct	tree *dtree(struct tree *root, const char cpf[]);
struct	tree *search_tree(struct tree *root, const char cpf[]);

void 	balance(struct tree **root);
void 	print_inorder(struct tree *root);
