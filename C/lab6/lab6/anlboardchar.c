int anlboard(char *T, int sizeT){
    if (sizeT != 9){
        return -1;
    }
    int i;
    for (i=0;i<9;i++){
        if ((T[i]!='X') && (T[i]!='O') && (T[i]!='-')){
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
        if (T[combos[i][0]]==T[combos[i][1]]&&T[combos[i][1]]==T[combos[i][2]]){
            if (T[combos[i][0]]=='X') {
                return 1;
            }
            if (T[combos[i][0]]=='O') {
                return 2;
            }
        }
    }
    for (i=0;i<8;i++){
        if (T[i]=='-'){
            return 0;
        }
    }
    return 3;
}
