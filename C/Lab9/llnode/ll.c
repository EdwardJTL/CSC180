#include <stdio.h>
#include <stdlib.h>
#include "ll.h"

int ll_add_to_head( llnode **head, int val) {
    llnode *old_head;
   if (head == NULL) {
      return -1;
   }
	old_head = *head;

   *head = ( llnode *) malloc(sizeof( llnode));
   (*head) -> val = val;
	(*head) -> next = old_head;
    (*head)->prev = NULL;
    if (old_head!=NULL){
    old_head ->prev = *head;
    }
	return 0;
}

int ll_add_to_tail( llnode **head, int val) {
   if (head == NULL) {
      return -1;
   }
    if (*head == NULL) {
        (*head) = (llnode *)malloc(sizeof(llnode));
        (*head)->val=val;
        (*head)->next = NULL;
        (*head)->prev = NULL;
        return 0;
    }else if ((*head)->next == NULL) {
       llnode *newnode = NULL;
      newnode = ( llnode *) malloc(sizeof( llnode));
      newnode -> val = val;
      newnode -> next = NULL;
       newnode ->prev = *head;
       (*head) -> next=newnode;
      return 0;
   } else {
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

int ll_print_backwards(llnode *p,int state){
    if (p==NULL){
        return 0;
    }else if(state==1){
        printf("val = %d\n", p->val);
        return ll_print_backwards((p->prev),1);
    }else if(state==0){
        if (p->next == NULL) {
            return ll_print_backwards(p,1);
        }else{
            return ll_print_backwards(p->next,0);
        }
    }
    return 0;
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
        if (*ppList!=NULL) {
            (*ppList)->prev = NULL;
        }
        return 0;
    }
}

int ll_del_by_value(llnode **ppList,int val){
    if (ppList==NULL){
        return -1;
    }
    if (*ppList == NULL) {
        return -1;
    }else{
        llnode *pcheck = *ppList;
        llnode *pold = pcheck;
        llnode *pnext = pcheck->next;
        if ((*ppList)->val == val) {
            return ll_del_from_head(ppList);
        }else{
            while (pcheck!=NULL){
                int value;
                value = pcheck->val;
                if (value==val) {
                    pold->next=pnext;
                    if (pnext!=NULL) {
                        pnext->prev = pold;
                    }
                    free(pcheck);
                    return 0;
                }else if(pnext!=NULL){
                    pold=pcheck;
                    pcheck=pnext;
                    pnext=pnext->next;
                }else{
                    return -1;
                }
            }
        }
    }
    return -1;
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
        /*llnode *pnext = (*pSrcA)->next;
        llnode *plast = (*pSrcA);
        llnode *plastlast = (*pSrcA);
        while (pnext!=NULL) {
            plastlast = plast;
            plast = pnext;
            pnext = (pnext)->next;
        }*/
        /*plast->next = *pSrcB;*/
        llnode *pnextB;
        /*if (*pSrcB!=NULL) {
            (*pSrcB)->prev=plast;
        }*/
        pnextB = *pSrcB;
        while (pnextB!=NULL){
            int r;
            r = ll_add_to_tail(pSrcA,(pnextB->val));
            pnextB = pnextB->next;
        }
        return 0;
    }
}

int ll_insert_in_order(llnode **ppList,int val) {
    llnode *previous = NULL;
    llnode *curr = NULL;
    
    if (ppList == NULL) { return -1; }
    if (*ppList == NULL) {
        return ll_add_to_head(ppList,val);
    }
    if ((*ppList) -> val > val) {
        return ll_add_to_head(ppList,val);
    } else {
        previous = *ppList;
        curr = (*ppList)->next;
        while(curr != NULL) {
            if (curr->val > val) {
                break;
            } else {
                previous = curr;
                curr = previous->next;
            }
        }
        previous->next = (llnode *) malloc(sizeof(llnode));
        previous->next->val  = val;
        previous->next->next = curr;
        previous->next->prev = previous;
        if (curr!=NULL) {
            curr->prev = previous->next;
        }
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
