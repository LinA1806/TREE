#include <stdio.h>
#include <stdlib.h>
#include "common.h"

/*typedef struct BinTree{
    char val;
    struct BinTree *lchild;
    struct BinTree *rchild;
}BTree,TNode;*/

//��ǰ�������������У�ȷ��һ����
TNode *createBT(char *pre,char *in,int L1,int R1,int L2,int R2){
    if(L1 > R1)
        return NULL;
    TNode *result = (TNode*)malloc(sizeof(TNode));
    result -> lchild = NULL;
    result -> rchild = NULL;
    result -> val = pre[L1];
    //Ѱ�Ҹ�
    int i;
    for(i=L2;i<R2;i++)
        if(in[i] == pre[L1])
            break;

    result -> lchild = createBT(pre,in,L1+1,L1+i-L2,L2,i-1);
    result -> rchild = createBT(pre,in,L1+i-L2+1,R1,i+1,R2);

    return result;
}
