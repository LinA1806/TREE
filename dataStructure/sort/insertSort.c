#include <stdio.h>
/*
*��������
*����������������
*/


void insertSort(int *arr,int len){
    int i,j;
    int temp;
    for(i=1;i<len;i++){//�ܹ�����len-1��
        if(arr[i] < arr[i-1]){//����Ԫ�ظոպô��� ����������Ԫ�أ�������
            temp = arr[i];
            for(j=i-1;temp < arr[j] && j >=0;j--){
                arr[j+1] = arr[j];
            }
            arr[j+1] = temp;
        }
    }
}

int binSearch(int *arr,int key,int begin,int end){
    int mid;
    while(begin <= end){
        mid = (begin+end)>>1;
        if(key > arr[mid])
            begin = mid + 1;
        else
            end = mid - 1;
    }
    return begin;
}

//�۰��������
void binInsertSort(int *arr,int len){
    int i,j,insertIndex,temp;
    for(i=1;i<len;i++){//�ܹ�����len-1��
        if(arr[i] < arr[i-1]){//����Ԫ�ظոպô��� ����������Ԫ�أ�������
            temp = arr[i];
            insertIndex = binSearch(arr,temp,0,i-1);//��0~i-1���ҵ�temp�����λ��
            //�ҵ������ƶ�
            for(j=i-1;j>=insertIndex;j--){
                arr[j+1] = arr[j];
            }
            arr[j+1] = temp;
        }
    }
}
