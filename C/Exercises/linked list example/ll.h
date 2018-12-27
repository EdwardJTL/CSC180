struct llnode {            /* since the llnode is a self-referential structure */
   int val;                /* we can not compile the struct and typedef decl into one */
   struct llnode *next;
};
typedef struct llnode llnode;

int ll_add_to_head( llnode **head, int val);
int ll_add_to_tail( llnode **head, int val);
int ll_print( llnode *p);
int ll_free( llnode *p);
