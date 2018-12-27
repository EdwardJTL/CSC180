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
