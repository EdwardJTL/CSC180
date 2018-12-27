#include <stdio.h>
#include <stdlib.h>
#include "ll.h"

/* One of the lessons here is to see that if we want to use a function to malloc something that
 * is a POINTER in the CALLER of the function, then we must send in the ADDRESS of the POINTER
 * to that function.
 * 
 * Recap: if we want to use a function to modify a VARIABLE in the caller
 *        then the CALLER needs to send in the ADDRESS of the VARIABLE
 *
 * Similarly: if we want to use a function to modify a POINTER in the caller
 *            then the CALLER needs to send in the ADDRESS of the POINTER
 *
 * In the code below, ll_add_to_head and ll_add_to_tail are dynamically creating new
 * nodes to be added to the linked list. Any dynamic creation of a node must be via
 * malloc.
 */

int ll_add_to_head( llnode **head, int val) {
    llnode *old_head;
   if (head == NULL) {
      return -1;
   }
	old_head = *head;

   *head = ( llnode *) malloc(sizeof( llnode));
   (*head) -> val = val;
	(*head) -> next = old_head;
	return 0;
}

int ll_add_to_tail( llnode **head, int val) {
   if (head == NULL) {
      return -1;
   }
   if (*head == NULL) {
      *head = ( llnode *) malloc(sizeof( llnode));
      (*head) -> val = val;
      (*head) -> next = NULL;
      return 0;
   } else { /* recursively call ll_add_to_tail until we get to the tail
					which is the point where the pointer is NULL */
      return ll_add_to_tail(&((*head)->next), val);
   }
}

int ll_print( llnode *p) {
   if (p==NULL) {
      return 0;
   } else {
      printf("val = %d\n",p->val);
      return ll_print(p->next);
   }
}

int ll_free( llnode *p) {
   if (p==NULL) {
      return -1;
   } else {
       llnode *f=p->next;
      free(p);
      return ll_free(f);
   }
}
