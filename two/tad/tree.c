//Lucas Trindade Oliveira e Jose Valter Silva Carneiro
#include "tree.h"

static bool
cmp_cpf(const char first_cpf[], const char second_cpf[])
{
	/*
	 * It returns <code>true</code> if the first cpf
	 * is less than the second cpf; otherwise
	 * returns <code>false</code>.
	 *
	 * @param first_cpf	string
	 * @param second_cpf	string
	 *
	 * @return		bool
	 * @see			https://cplusplus.com/reference/cstring/strcmp/
	 */

	return strcmp(first_cpf, second_cpf) < 0;
}

static bool
are_cpf_equal(const char first_cpf[], const char second_cpf[])
{
	/*
	 * It returns <code>true</code> if the first cpf
	 * and the second cpf are equal; otherwise
	 * returns <code>false</code>.
	 *
	 * @param first_cpf	string
	 * @param second_cpf	string
	 *
	 * @return		bool
	 * @see			https://cplusplus.com/reference/cstring/strcmp/
	 */

	return strcmp(first_cpf, second_cpf) == 0;
}

static int
levels(struct tree *root)
{
	/*
	 * It returns the level of any root.
	 *
	 * @return	int
	 */

	if (root == NULL)
		return 0;

	return 1 + (
		levels(root->left) > levels(root->right) ?
		levels(root->left) : levels(root->right)
	);
}

static int
balance_factor(struct tree *root)
{
	/*
	 * It returns the balance factor of any root.
	 *
	 * @return	int
	 */

	if (root == NULL)
		return 0;			/* empty */

	return levels(root->left) - levels(root->right);
}

static void
rotate_right(struct tree **root)
{
	/*
	 * This procedure rotates to the right.
	 *
	 * @see		https://www.geeksforgeeks.org/introduction-to-avl-tree/
	 */

	struct tree *new_root = (*root)->left;

	(*root)->left 	= new_root->right;
	new_root->right = *root;
	*root 		= new_root;
}

static void
rotate_left(struct tree **root)
{
	/*
	 * This procedure rotates to the left.
	 *
	 * @see		https://www.geeksforgeeks.org/introduction-to-avl-tree/
	 */

	struct tree *new_root = (*root)->right;

	(*root)->right 	= new_root->left;
	new_root->left 	= *root;
	*root 		= new_root;
}

void
balance(struct tree **root)
{
	/*
	 * It balances any tree.
	 *
	 * @return noreturn
	 */

	int level;

	if (*root == NULL)		/* isn't balanced			*/
		return ;

	level = balance_factor(*root);	/* how many more levels the left has	*/

	if (level < -1) {		/* the left has less levels 		*/

		if (balance_factor((*root)->right) > 0)
			rotate_right(&(**root).right);
		
		rotate_left(root);
		balance(root);		/* try to balance it again		*/
	} else if (level < 2) { 	/* balanced tree			*/
		balance(&(**root).right);
		balance(&(**root).left);
	} else {			/* the right has less levels 		*/

		if (balance_factor((*root)->left) < 0)
			rotate_left(&(**root).left);
		
		rotate_left(root);
		balance(root);		/* try to balance it again 		*/
	}
}

static void
real_itree(struct tree **root, char cpf[], char name[], char birth[])
{
	/*
	 * It creates and stores a new register.
	 *
	 * @param cpf	string
	 * @param name	string
	 * @param birth	string
	 *
	 * @return	noreturn
	 * @see		https://cplusplus.com/reference/cstring/memcpy/
	 */

	struct tree *new = malloc(sizeof(struct tree));

	if (new == NULL)				/* there's not enough memory */
		exit(1);

	memcpy(new->cpf, cpf, 	12);
	memcpy(new->name, name, 15);
	memcpy(new->birth, birth, 9);

	new->left 	= NULL;
	new->right 	= NULL;

	*root = new;					/* now the empty node gets a new node	*/
}

void
itree(struct tree **root, char cpf[], char name[], char birth[])
{
	/*
	 * It's a public procedure to store
	 * a new register of type tree.
	 *
	 * @param cpf	string
	 * @param name	string
	 * @param birth	string
	 *
	 * @return	noreturn
	 */

	if (*root == NULL) {				/* base case 		*/
		real_itree(root, cpf, name, birth);
		return ;
	}

	cmp_cpf(cpf, (*root)->cpf) ?			/* cpf < (*root)->cpf		*/
		itree(&(**root).left,  cpf, name, birth) :	
		itree(&(**root).right, cpf, name, birth) ;
}

struct tree
*dtree(struct tree *root, const char cpf[])
{
	/*
	 * This function deletes a register according
	 * to the specified cpf and returns the tree
	 * root.
	 *
	 * @param cpf	string
	 *
	 * @return	struct tree *
	 */

	struct tree *p1, *p2;

	if (root == NULL)
		return root;				/* empty 			*/

	if (strcmp(cpf, root->cpf) == 0) {		/* equals @see #cmp_cpf 	*/
		
		if (root->left == root->right) {	/* null or empty 		*/
			/* the tree is emptied				*/
			free(root);
			return NULL;
		} else if (root->left == NULL) {	/* right isn't null 		*/
			/* right node becomes root			*/
			p1 = root->right;

			free(root);
			return p1;
		} else if (root->right == NULL) {	/* left isn't null		*/
			/* left node becomes root 			*/
			p2 = root->left;

			free(root);
			return p2;
		} else {				/* two sub-trees are present	*/
			/* the last left node on the right becomes root */
			p1 = root->right;

			for (; p1->left != NULL; p2 = p1, p1 = p1->left) ;

			p1->left	= root->left;
			p2->left	= p1->right;
			p1->right	= root->right;

			free(root);
			return p1;
		}
	}

	if (cmp_cpf(cpf, root->cpf)) 		/* cpf < root->cpf */
		root->left 	= dtree(root->left, cpf);
	else
		root->right	= dtree(root->right, cpf);

	return root;
}

struct tree
*search_tree(struct tree *root, const char cpf[])
{
	/*
	 * It's function searches for a register
	 * with the key `cpf` and returns a
	 * pointer to this key if it's found;
	 * otherwise returns NULL.
	 *
	 * @param cpf	string
	 *
	 * @return	struct tree *
	 */

	if (root == NULL)
		return root;			/* empty */

	while (root != NULL && !are_cpf_equal(cpf, root->cpf))
                root = cmp_cpf(cpf, root->cpf) ? root->left : root->right;

	return root;
}

void
print_inorder(struct tree *root)
{
	if (root == NULL)
		return ;			/* empty */

	print_inorder(root->left);

	printf("%s:\n", root->cpf);
	printf("\t%s\n", root->name);
	printf("\t%s\n", root->birth);
	
	print_inorder(root->right);
}

void
destroy_tree(struct tree *root)
{
	/*
	 * This procedure frees the memory
	 * allocated for storing the registers.
	 *
	 * @return	noreturn
	 */
	
	/* code */
}
