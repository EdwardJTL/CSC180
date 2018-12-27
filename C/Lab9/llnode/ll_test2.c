#include <stdio.h>
#include "ll.h"

int main(void) {
   llnode *root = NULL;
   int r=0;
   int i=0;
    printf("List A\n");
    r=ll_add_to_head(&root,150);
    r=ll_add_to_head(&root,250);
    r=ll_add_to_head(&root,350);
   r=ll_add_to_tail(&root,100);
   r=ll_add_to_tail(&root,200);
   r=ll_add_to_tail(&root,300);
   /*for(i=0;i<10;i=i+1){
      r=ll_add_to_tail(&root,i*100);
   }*/
   r=ll_print(root);
    printf("here is to print A backwards\n");
    r=ll_print_backwards(root,0);
    
    r=ll_del_by_value(&root,200);
    printf("List A\n");
    r=ll_print(root);
    printf("here is to print A backwards\n");
    r=ll_print_backwards(root,0);
    

   printf("List B\n");
    llnode *Root = NULL;
	Root=NULL;
   r=ll_add_to_tail(&Root,100);
   r=ll_print(Root);
    printf("now lets add 340,21,552.\n");
    r=ll_add_to_head(&Root,340);
    r=ll_add_to_head(&Root,21);
    r=ll_add_to_head(&Root,552);
    r=ll_print(Root);
    printf("Here is the sorted list.\n");
    r=ll_sort(&Root);
    printf("Here is the sort state %d.\n",r);
    r=ll_print(Root);
    
    printf("now we concat A+B\n");
    r = ll_concat(&root,&Root);
    
    printf("List A new\n");
    r=ll_print(root);
    printf("here is to print new A backwards\n");
    r=ll_print_backwards(root,0);
    
    printf("insert in order\n");
    r=ll_insert_in_order(&root,450);
    printf("List A new\n");
    r=ll_print(root);
    printf("here is to print new A backwards\n");
    r=ll_print_backwards(root,0);
    
    printf("sort");
    r=ll_sort(&root);
    printf("List A new\n");
    r=ll_print(root);
    printf("here is to print new A backwards\n");
    r=ll_print_backwards(root,0);
    
    r=ll_free(root);
    r=ll_free(Root);
   return 0;
}
