/* chemistry.c
 mathaine@ecf
 
 This code illustrates a few things:
 1. Another example of defining structs
 2. Recursively defined structs (inter-related)
 3. Another dynamic data structures to suit a particular problem
 (specifically, how to represent molecular structure)
 4. How to do recursion where each recursion is "aware" of
 its recursion depth
 (note how I print spaces in order to structure the output
 in a pretty manner --- the spaces are a function of recursion
 depth).
 
 Note: bondList is a linked list, however, I only added a single
 function for ll management, bondList_add, since that's all the
 application required.
 
 None of this required any special intuition. We just designed
 this "ad hoc" based on the requirements of the application, using
 the "dynamicism" we learned from our linked list lesson.
 */

#include<stdio.h>
#include<stdlib.h>

struct bondNode;
struct atom;

struct bondNode {
    int strength;
    struct atom *pAtom;
    struct bondNode *pNext;
};

struct atom {
    int atomicNumber;
    struct bondNode *bondList;
};

typedef struct bondNode bondNode;
typedef struct atom atom;

int addBond(atom *pAtom, int strength, atom *pAtom2);
atom *createAtom(int atomicNumber);
int bondList_add(bondNode **ppList, int strength, atom *pAtom);
int printAtom(atom *pAtom,int n);
int printBonds(bondNode *pList,int n);
int genFormula(atom *pAtom,int **output,int *size);

int genFormula(atom *pAtom,int **output,int *size){
    if (output==NULL) {
        return -1;
    }else if(pAtom==NULL){
        return -1;
    }else{
        int atom_number;
        int r_size;
        int *r_output=NULL;
        int d1;
        int d2;
        int d3;
        struct bondNode *nextbond=NULL;
        int *old=NULL;
        int *new=NULL;
        int new_size;
        int old_size;
        int added;
        int accum_state;
        int swapping;
        r_size=0;
        atom_number = pAtom->atomicNumber;
        old=(int *)malloc(sizeof(int)*2);
        old[0]=atom_number;
        old[1]=1;
        new_size=2;
        new = old;
        nextbond = pAtom->bondList;
        while (nextbond!=NULL) {
            added=0;
            d1 = genFormula(nextbond->pAtom,&r_output,&r_size);
            for(d1=0;d1<r_size;d1+=2){
                for(d2=0;d2<new_size;d2+=2){
                    if (r_output[d1]==new[d2]) {
                        added+=1;
                    }
                }
            }
            /*duplicate new into old*/
            old=(int *)malloc(sizeof(int)*new_size);
            old_size=new_size;
            for (d1=0; d1<new_size; d1++) {
                old[d1]=new[d1];
            }
            free(new);
            /*create new array of appropriate size*/
            new_size=new_size+r_size-added*2;
            new=(int *)malloc(sizeof(int)*new_size);
            for (d3=0; d3<new_size; d3++) {
                new[d3]=0;
            }
            for (d1=0; d1<old_size; d1+=2) {
                new[d1]=old[d1];
                new[d1+1]=old[d1+1];
            }
            /*for (d1=0; d1<old_size; d1++) {
                printf("old[%d] = %d\n", d1, old[d1]);
            }
            for (d1=0; d1<r_size; d1++) {
                printf("r_output[%d] = %d\n", d1, r_output[d1]);
            }
            for (d1=0; d1<new_size; d1++) {
                printf("new-p[%d] = %d\n", d1, new[d1]);
            }*/
            for(d1=0;d1<r_size;d1+=2){
                accum_state=0;
                for(d2=0;d2<old_size;d2+=2){
                    if (r_output[d1]==old[d2]) {
                        new[d2+1]+=r_output[d1+1];
                        accum_state+=1;
                    }
                }
                if (accum_state==0) {
                    for (d3=0; d3<new_size; d3+=2) {
                        if (new[d3]==0) {
                            new[d3]=r_output[d1];
                            new[d3+1]=r_output[d1+1];
                            d3=new_size+1;
                        }
                    }
                }
            }
            /*for (d1=0; d1<new_size; d1++) {
                printf("new[%d] = %d\n", d1, new[d1]);
            }*/
            free(r_output);
            nextbond = nextbond->pNext;
        }
        if (new_size>2) {
            swapping = 0;
            while (swapping == 0){
                int swapped;
                int i;
                swapped = 0;
                for (i=0;i<new_size-2;i+=2){
                    if (new[i]>new[i+2]) {
                        int temp;
                        int temp2;
                        temp = new[i];
                        temp2 = new[i+1];
                        new[i] = new[i+2];
                        new[i+1] = new[i+3];
                        new[i+2]=temp;
                        new[i+3]=temp2;
                        swapped = 1;
                    }
                }
                if (swapped == 0){
                    swapping = 1;
                }
            }
        }
        *output=(int *)malloc(sizeof(int)*new_size);
        for (d1=0; d1<new_size; d1++) {
            (*output)[d1]=new[d1];
        }
        *size=new_size;
        if (new_size>2) {
            free(new);
        }
        free(old);
    }
    return 1;
}


atom *createAtom(int atomicNumber) {
    atom *p=(atom *)malloc(sizeof(atom));
    p->atomicNumber = atomicNumber;
    p->bondList = NULL;
    return p;
}

int bondList_add(bondNode **ppList, int strength, atom *pAtom) {
    if (ppList == NULL) { return -1; }
    if (*ppList == NULL) {
        *ppList = (bondNode *)malloc(sizeof(bondNode));
        (*ppList)->strength=strength;
        (*ppList)->pAtom=pAtom;
        (*ppList)->pNext=NULL;
        return 0;
    } else {
        return bondList_add( &((*ppList)->pNext), strength, pAtom );
    }
}

int addBond(atom *pAtom, int strength, atom *pAtom2) {
    if (pAtom == NULL) { return -1; }
    
    return bondList_add( &(pAtom->bondList), strength, pAtom2);
}

int printAtom(atom *pAtom,int n) {
    int i;
    if (pAtom == NULL) {
        printf("black hole sun...\n");
    } else {
        for(i=0;i<n;i=i+1) {
            printf("   ");
        }
        printf("-> atomic number=%d: bonded to:\n",pAtom->atomicNumber);
        printBonds(pAtom->bondList,n);
        for(i=0;i<n;i=i+1) {
            printf("   ");
        }
        printf("<- atomic number=%d\n",pAtom->atomicNumber);
        
    }
    return 0;
}

int printBonds(bondNode *pList,int n) {
    int i;
    for(i=0;i<n;i=i+1) {
        printf("   ");
    }
    if (pList == NULL) {
        printf("no bonds\n");
    } else {
        printf("strength=%d connected to:\n",pList->strength);
        printAtom(pList->pAtom,n+1);
        printBonds(pList->pNext,n);
    }
    return 0;
}



int main(void) {
    int r=0;
    atom *S;
    atom *tmp1,*tmp2,*tmp3,*tmp4;
    int *a=NULL;
    int size;
    
    S = createAtom(16);
    
    tmp1=createAtom(8);
    r=addBond(S,2,tmp1);
    
    tmp1=createAtom(8);
    r=addBond(S,2,tmp1);
    
    tmp1=createAtom(8);
    tmp2=createAtom(1);
    r=addBond(tmp1,1,tmp2);
    r=addBond(S,1,tmp1);
    
    tmp1=createAtom(8);
    tmp2=createAtom(1);
    r=addBond(tmp1,1,tmp2);
    r=addBond(S,1,tmp1);
    
    /*S = createAtom(6);
    
    tmp2 = createAtom(6);
    tmp1 = createAtom(1);
    r = addBond(tmp2,1,tmp1);
    tmp1 = createAtom(1);
    r = addBond(tmp2,1,tmp1);
    tmp1 = createAtom(1);
    r = addBond(tmp2,1,tmp1);
    
    tmp3 = createAtom(6);
    tmp1 = createAtom(1);
    r = addBond(tmp3,1,tmp1);
    tmp1 = createAtom(1);
    r = addBond(tmp3,1,tmp1);
    r = addBond(tmp3,1,tmp2);
    
    tmp1 = createAtom(1);
    r = addBond(S,1,tmp1);
    tmp1 = createAtom(1);
    r = addBond(S,1,tmp1);
    r = addBond(S,1,tmp3);
    
    tmp4 = createAtom(7);
    tmp1 = createAtom(5);
    r = addBond(tmp4,2,tmp1);
    r = addBond(S,1,tmp4);*/
    
    
    printAtom(S,0);
    
    r= genFormula(S,&a,&size);
    for (r=0; r<size; r++) {
        printf("formula[%d] = %d\n", r, a[r]);
    }
    free(S);
    free(tmp1);
    free(tmp2);
    free(tmp3);
    free(tmp4);
    free(a);
    return 0;
}
