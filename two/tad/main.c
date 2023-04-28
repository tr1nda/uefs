//Lucas Trindade Oliveira e Jose Valter Silva Carneiro
#include "tree.h"

void
print(const char cpf[], int l)
{
        for (register int i = 0; i < l; i++)
                printf("\t\t");
        puts(cpf);
}

void
print_tree(struct tree *root, int l)
{
        if (root == NULL) {
                print("00000000000", l);
                return ;
        }
        
        print_tree(root->right, l+1);
        
        print(root->cpf, l);
        
        print_tree(root->left, l+1);
}

int
main(int argc, char argv[])
{
        struct tree *root = NULL;
	struct tree *jose = NULL;	/* search */

        itree(&root, "05014668460\0", "Jose\0", "15031998\0");
        itree(&root, "14658945632\0", "Joao\0", "25031995\0");
        itree(&root, "14658445132\0", "Pedro\0", "45631999\0");

        puts("------------------");
        print_tree(root, 0);

        balance(&root);

        itree(&root, "14658945930\0", "Carlos\0", "15031999\0");
        itree(&root, "14658445130\0", "Mateus\0", "11631999\0");

        puts("------------------");
        print_tree(root, 0);

        balance(&root);

	print_inorder(root);

        puts("------------------");
        print_tree(root, 0);

	root = dtree(root, "05014668460");

        balance(&root);

        puts("------------------");
	jose = search_tree(root, "14658945930");
	printf("The name of the searched user: %s\n", jose->name);

        puts("------------------");
        print_tree(root, 0);

	destroy_tree(root);	/* it frees memory */

        return 0;
}
