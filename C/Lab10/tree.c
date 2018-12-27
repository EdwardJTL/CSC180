#include <stdlib.h>
#include <stdio.h>

struct TreeNode;

struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
typedef struct TreeNode TreeNode;

int add(TreeNode **root,int val);
int print(TreeNode *root);

int add(TreeNode **root,int val){
    int r;
    if (root==NULL) {
        return -1;
    }else if(*root==NULL){
        (*root)=(TreeNode *)malloc(sizeof(TreeNode));
        (*root)->val = val;
        (*root)->left = NULL;
        (*root)->right = NULL;
        return 0;
    }else{
        if ((*root)->val==val) {
            return 0;
        }else if((*root)->val>val){
            r = add(&((*root)->left),val);
        }else if((*root)->val<val){
            r = add(&((*root)->right),val);
        }
    }
    return 0;
}

int print(TreeNode *root){
    if (root==NULL) {
        return 0;
    }else{
        int r;
        r = print(root->left);
        printf("%d\n",root->val);
        r = print(root->right);
        return 0;
    }
}

int main(void){
    TreeNode *t=NULL;
    int r;
    r=add(&t,5);
    r=add(&t,15);
    r=add(&t,1);
    r=add(&t,3);
    r=add(&t,10);
    r=print(t);
    free(t);
    return 0;
}
