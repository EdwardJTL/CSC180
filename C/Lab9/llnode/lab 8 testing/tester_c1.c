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

int tester_offset(llnode *root, int *expect, int n, int offset) {
	llnode *p=root;
	int x = 0;
	if (root==NULL) { if (n==0) return 0; else return -1; }
	if (n==0) { if (root==NULL) return 0; else return -1; }
	while(p!=NULL) {
		/*printf("%d %d\n",p->val,expect[x]);*/
		if (p->val != expect[offset+x]) { return -1; }
		x=x+1;
		p = p->next;
	}
	return 0;
}
		
		

int main(int argc,char *argv[]){
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
   printf("INFO (free marks): %d/%d\n",tot-err,tot);

   for(i=0;i<13;i=i+1) {
      if (ll_find_by_value(root,refA[i]) != 0) { err += 2; printf("couldn't find %d\n",refA[i]); }
      if (ll_find_by_value(root,-refA[i]-1) != -1) { err += 2; printf("found wrong val %d\n",-refA[i]); }
      tot += 2;
      tot += 2;
   }
   printf("INFO (find by value): %d/%d\n",tot-err,tot);

   for(i=1;i<13;i=i+1) {
      r=ll_del_from_tail(&root);
      r=tester(root,refA,13-i);
      if (r!=0) { err += 5; } tot += 5;
   }
   printf("INFO (del from tail): %d/%d\n",tot-err,tot);
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
   printf("INFO (free marks): %d/%d\n",tot-err,tot);

   for(i=1;i<13;i=i+1) {
      r=ll_del_from_head(&root);
      r=tester_offset(root,refA,13-i,i);
      if (r!=0) { err += 5; } tot += 5;
   }
   printf("INFO (del from head): %d/%d\n",tot-err,tot);

   r=ll_free(root);

   printf("Testing ll_insert_in_order\n");
   root=NULL;
   r=ll_add_to_tail(&root,100);
   r=ll_add_to_tail(&root,200);
   r=ll_add_to_tail(&root,300);
   printf("before\n");
   r=ll_print(root);
   r=ll_insert_in_order(&root,99);
   printf("after-a\n");
   r=ll_print(root);
   refA[0]=99; refA[1]=100; refA[2]=200; refA[3]=300;
   r=tester(root,refA,4);
   if (r!=0) { err += 2; } tot += 2;
   printf("INFO: %d/%d\n",tot-err,tot);

   r=ll_insert_in_order(&root,101);
   printf("after-b\n");
   /*r=ll_print(root);*/
   refA[0]=99; refA[1]=100; refA[2]=101; refA[3]=200; refA[4]=300;
   r=tester(root,refA,5);
   if (r!=0) { err += 2; } tot += 2;
   printf("INFO: %d/%d\n",tot-err,tot);

   r=ll_insert_in_order(&root,201);
   printf("after-c\n");
   /*r=ll_print(root);*/
   refA[0]=99; refA[1]=100; refA[2]=101; refA[3]=200; refA[4]=201; refA[5]=300;
   r=tester(root,refA,6);
   if (r!=0) { err += 2; } tot += 2;
   printf("INFO: %d/%d\n",tot-err,tot);

   r=ll_insert_in_order(&root,301);
   printf("after-d\n");
   /*r=ll_print(root);*/
   refA[0]=99; refA[1]=100; refA[2]=101; refA[3]=200; refA[4]=201; refA[5]=300; refA[6]=301;
   r=tester(root,refA,7);
   if (r!=0) { err += 2; } tot += 2;
   printf("INFO: %d/%d\n",tot-err,tot);

   r=ll_del_by_value(&root,99);
   refA[0]=100; refA[1]=101; refA[2]=200; refA[3]=201; refA[4]=300; refA[5]=301;
   r=tester(root,refA,6);
   if (r!=0) { err += 10; } tot += 10;
   printf("INFO (del by value): %d/%d\n",tot-err,tot);

   r=ll_del_by_value(&root,301);
   refA[0]=100; refA[1]=101; refA[2]=200; refA[3]=201; refA[4]=300;
   r=tester(root,refA,5);
   if (r!=0) { err += 10; } tot += 10;
   printf("INFO (del by value): %d/%d\n",tot-err,tot);

   r=ll_del_by_value(&root,200);
   refA[0]=100; refA[1]=101; refA[2]=201; refA[3]=300;
   r=tester(root,refA,4);
   if (r!=0) { err += 10; } tot += 10;
   printf("INFO (del by value): %d/%d\n",tot-err,tot);

   r=ll_del_by_value(&root,101);
   refA[0]=100; refA[1]=201; refA[2]=300;
   r=tester(root,refA,3);
   if (r!=0) { err += 10; } tot += 10;
   printf("INFO (del by value): %d/%d\n",tot-err,tot);

   r=ll_del_by_value(&root,201);
   refA[0]=100; refA[1]=300;
   r=tester(root,refA,2);
   if (r!=0) { err += 10; } tot += 10;
   printf("INFO (del by value): %d/%d\n",tot-err,tot);

   printf("SCORE:%s,%d\n",argv[1],(int)((float)(tot-err)*100.0/(float)tot));

   r=ll_free(root);
   return 0;
}
