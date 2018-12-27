#include <stdio.h>
#include "ll.h"

int main(void) {
   llnode *root = NULL;
   int r=0;
   int i=0;

   printf("List A\n");
   r=ll_add_to_tail(&root,100);
   r=ll_add_to_tail(&root,200);
   r=ll_add_to_tail(&root,300);
   for(i=0;i<10;i=i+1){
      r=ll_add_to_tail(&root,i*100);
   }
   r=ll_print(root);
   r=ll_free(root);

   printf("List B\n");
	root=NULL;
   r=ll_add_to_tail(&root,100);
   r=ll_print(root);
    printf("now lets add 340,21,552.\n");
    r=ll_add_to_head(&root,340);
    r=ll_add_to_head(&root,21);
    r=ll_add_to_head(&root,552);
    r=ll_print(root);
    printf("Here is the sorted list.\n");
    r=ll_sort(&root);
    printf("Here is the sort state %d.\n",r);
    r=ll_print(root);
    printf("now lets inset 99.\n");
    
    r=ll_insert_in_order(&root,20);
    r=ll_print(root);
   r=ll_free(root);
   return 0;
}
