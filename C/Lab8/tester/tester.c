#include <stdio.h>
#include "ll.h"

int tester(llnode *root, int *expect, int n);

int tester(llnode *root, int *expect, int n) {
	llnode *p=root;
	int x = 0;
	if (root==NULL) { if (n==0) return 0; else return -1; }
	if (n==0) { if (root==NULL) return 0; else return -1; }
	while(p!=NULL) {
		/*printf("%d %d\n",p->val,expect[x]);*/
		if (p->val != expect[x]) { return -1; }
		x=x+1;
		p = p->next;
	}
	return 0;
}
		

int main(void) {
   llnode *root = NULL;
   int r=0;
   int i=0;
   int refA[13];
   int tot=0;
   int err=0;

   printf("List A\n");
   r=ll_add_to_tail(&root,100); refA[0] = 100;
   r=ll_add_to_tail(&root,200); refA[1] = 200;
   r=ll_add_to_tail(&root,300); refA[2] = 300;
   for(i=0;i<10;i=i+1){
      r=ll_add_to_tail(&root,i*100); refA[3+i]=i*100;
   }
   /*r=ll_print(root);*/
   r=tester(root,refA,13);
   if (r!=0) { err += 10; } tot += 10;
   printf("INFO: %d/%d\n",tot-err,tot);
   r=ll_free(root);

   printf("List B\n");
   root=NULL;
   r=ll_add_to_head(&root,100); refA[12] = 100;
   r=ll_add_to_head(&root,200); refA[11] = 200;
   r=ll_add_to_head(&root,300); refA[10] = 300;
   for(i=0;i<10;i=i+1){
      r=ll_add_to_head(&root,i*100); refA[9-i]=i*100;
   }
   /*r=ll_print(root);*/
   r=tester(root,refA,13);
   if (r!=0) { err += 10; } tot += 10;
   printf("INFO: %d/%d\n",tot-err,tot);
   r=ll_free(root);

#if 0
   printf("Testing ll_insert_in_order\n");
   root=NULL;
   r=ll_add_to_tail(&root,100);
   r=ll_add_to_tail(&root,200);
   r=ll_add_to_tail(&root,300);
   printf("before\n");
   /*r=ll_print(root);*/
   r=ll_insert_in_order(&root,99);
   printf("after-a\n");
   /*r=ll_print(root);*/
   refA[0]=99; refA[1]=100; refA[2]=200; refA[3]=300;
   r=tester(root,refA,4);
   if (r!=0) { err += 10; } tot += 10;
   printf("INFO: %d/%d\n",tot-err,tot);

   r=ll_insert_in_order(&root,101);
   printf("after-b\n");
   /*r=ll_print(root);*/
   refA[0]=99; refA[1]=100; refA[2]=101; refA[3]=200; refA[4]=300;
   r=tester(root,refA,5);
   if (r!=0) { err += 10; } tot += 10;
   printf("INFO: %d/%d\n",tot-err,tot);

   r=ll_insert_in_order(&root,201);
   printf("after-c\n");
   /*r=ll_print(root);*/
   refA[0]=99; refA[1]=100; refA[2]=101; refA[3]=200; refA[4]=201; refA[5]=300;
   r=tester(root,refA,6);
   if (r!=0) { err += 10; } tot += 10;
   printf("INFO: %d/%d\n",tot-err,tot);

   r=ll_insert_in_order(&root,301);
   printf("after-d\n");
   /*r=ll_print(root);*/
   refA[0]=99; refA[1]=100; refA[2]=101; refA[3]=200; refA[4]=201; refA[5]=300; refA[6]=301;
   r=tester(root,refA,7);
   if (r!=0) { err += 10; } tot += 10;
   printf("INFO: %d/%d\n",tot-err,tot);
   r=ll_free(root);
#endif


   return 0;
}
