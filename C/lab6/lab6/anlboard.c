int anlboard(int *T, int sizeT){
    if (sizeT != 9){
        return -1;
    }
    int i;
    for (i=0;i<9;i++){
        if (T[i]!=0&&T[i]!=1&&T[i]!=2){
            return -1;
        }
    }
    int combos[8][3];
    for (i=0;i<3;i++){
        combos[0][i]=i;
    }
    for (i=0;i<3;i++){
        combos[1][i]=i+3;
    }
    for (i=0;i<3;i++){
        combos[2][i]=i+6;
    }
    for (i=0;i<3;i++){
        combos[3][i]=i*3;
    }
    for (i=0;i<3;i++){
        combos[4][i]=i*3+1;
    }
    for (i=0;i<3;i++){
        combos[5][i]=i*3+2;
    }
    for (i=0;i<3;i++){
        combos[6][i]=i*4;
    }
    for (i=0;i<3;i++){
        combos[7][i]=i*2+2;
    }
    for (i=0;i<8;i++){
        if (T[combos[i][0]]==T[combos[i][1]]&&T[combos[i][1]]==T[combos[i][2]]&&T[combos[i][1]]!=0){
            return T[combos[i][0]];
        }
    }
    for (i=0;i<8;i++){
        if (T[i]==0){
            return 0;
        }
    }
    return 3;
}
