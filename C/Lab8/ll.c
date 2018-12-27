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

int ll_find_by_value(llnode *pList,int val) {
    if (pList==NULL){
        return -1;
    } else{
        if ((pList->val)==val) {
            return 0;
        }else{
            llnode *pnext = pList->next;
            return ll_find_by_value(pnext,val);
        }
    }
}

int ll_del_from_tail(llnode **ppList){
    if (ppList==NULL){
        return -1;
    }
    if (*ppList == NULL) {
        return -1;
    }else{
        llnode *pnext = (*ppList)->next;
        llnode *plast = (*ppList);
        llnode *plastlast = (*ppList);
        while (pnext!=NULL) {
            plastlast = plast;
            plast = pnext;
            pnext = (pnext)->next;
        }
        free(plast);
        (plastlast)->next = NULL;
        return 0;
    }
}

int ll_del_from_head(llnode **ppList){
    if (ppList==NULL){
        return -1;
    }
    if (*ppList == NULL) {
        return -1;
    }else{
        llnode *pfirst = *ppList;
        *ppList = (*ppList)->next;
        free(pfirst);
        return 0;
    }
}

int ll_del_by_value(llnode **ppList,int val){
    int deleted = -1;
    if (ppList==NULL){
        return -1;
    }
    if (*ppList == NULL) {
        return -1;
    }else{
        llnode *pcheck = *ppList;
        llnode *pold = pcheck;
        llnode *pnext = pcheck->next;
        printf("one\n");
        if ((*ppList)->val == val) {
            free(*ppList);
            *ppList = pnext;
            deleted = 0;
            printf("two\n");
        }else{
            while ((pcheck->val != val)&&(pnext!=NULL)) {
                printf("%d\n",pcheck->val);
                pold = pcheck;
                pcheck = pnext;
                pnext = pnext->next;
            }
            printf("three\n");
            pold->next = pnext;
            free(pcheck);
            deleted = 0;
        }
    }
    return deleted;
}

int ll_concat(llnode **pSrcA,llnode **pSrcB){
    if (pSrcA==NULL){
        return -1;
    }
    if (*pSrcA == NULL) {
        return -1;
    }
    if (pSrcB==NULL){
        return -1;
    }
    if (*pSrcB == NULL) {
        return -1;
    }else{
        llnode *pnext = (*pSrcA)->next;
        llnode *plast = (*pSrcA);
        llnode *plastlast = (*pSrcA);
        while (pnext!=NULL) {
            plastlast = plast;
            plast = pnext;
            pnext = (pnext)->next;
        }
        plast->next = *pSrcB;
        return 0;
    }
}

int ll_insert_in_order(llnode **ppList,int val){
    if (ppList==NULL){
        return -1;
    }
    if (*ppList == NULL) {
        return -1;
    }else{
        llnode *pcurrent;
        llnode *pnext;
        pcurrent = *ppList;
        pnext = (*ppList)->next;
        int currentval = pcurrent->val;
        int nextval = pnext->val;
        while ((currentval>val)||(nextval<val)) {
            pcurrent = pnext;
            pnext = pnext->next;
            if (pnext==NULL) {
                return -1;
            }else{
                currentval = pcurrent->val;
                nextval = pnext->val;
            }
        }
        llnode *newllnode;
        newllnode = (llnode *)malloc(sizeof(llnode));
        newllnode->val = val;
        newllnode->next = pnext;
        pcurrent->next = newllnode;
        return 0;
    }
}

int ll_sort(llnode **ppList){
    if (ppList==NULL){
        return -1;
    }
    if (*ppList == NULL) {
        return -1;
    }else{
        llnode *pcurrent;
        llnode *pnext;
        llnode *pend;
        pcurrent = *ppList;
        pnext = (*ppList)->next;
        if (pnext==NULL) {
            return 0;
        }
        pend = NULL;
        int swapping = 1;
        while (swapping==1) {
            int currentval = pcurrent->val;
            int nextval = pnext->val;
            if (currentval>nextval) {
                pcurrent->val=nextval;
                pnext->val=currentval;
            }
            pcurrent=pnext;
            pnext=pnext->next;
            int r;
            if (pnext==pend) {
                pend=pcurrent;
                if (pend==(*ppList)->next) {
                    swapping=0;
                }
                pcurrent = *ppList;
                pnext = (*ppList)->next;
            }
        }
    }
    return 0;
}
