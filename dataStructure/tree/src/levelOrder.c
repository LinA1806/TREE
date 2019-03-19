#include <stdio.h>
#include "common.h"

#define MAXSIZE 50
/*
���Ĳ�α���
ѭ������
*/


/*
typedef struct BinTree{
    char val;
    struct BinTree *lchild;
    struct BinTree *rchild;
}BTree,TNode;
*/

void levelOrder(BTree *bt){
    if(bt !=NULL){
        int front,rear;
        TNode *que[MAXSIZE];
        front = rear = 0;
        TNode *p;//work pointer

        //�Ƚ���һ����
        rear = (rear +1) % MAXSIZE;
        que[rear] = bt;

        //ֻҪ�Ӳ���
        while(front != rear){
            //����һ��
            front = (front + 1) % MAXSIZE;
            p = que[front];
            printf("%c ",p->val);//���
            //�����Ķ�����
            if(p->lchild != NULL){
                rear = (rear + 1 ) % MAXSIZE ;
                que[rear] = p->lchild;
            }
            if(p->rchild != NULL){
                rear = (rear + 1 ) % MAXSIZE ;
                que[rear] = p->rchild;
            }
        }
    }
}
