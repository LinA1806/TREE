#include <stdio.h>

/*
�㷨:
��������
���һ����֧���
�����һ����֧��㿪ʼ������(shift����)
ÿ�ε����꣬�ѶѶ���Ԫ�ص���
*/

void shift(int *arr,int low,int high){
    //����������0��ʼ���
    int i = low;//����
    int j = 2 * i + 1;//�Һ���
    int temp = arr[i];
    while(j <= high){//�ڵ�����Χ֮�ڸ���
        if(j < high && arr[j] < arr[j+1])
            j++;//���Һ��ӽ���,׼�����Һ��ӽϴ�Ļ���ȥ
        if(temp < arr[j]){
            arr[i] = arr[j];
            i = j;
            j = 2 * i + 1;//�����µ���
        }else{
            break;
        }
    }//end while
    arr[i] = temp;
}//end

void heapSort(int *arr,int n){
    int i;
    int temp;
    for(i = n/2-1;i>0;i--){//���һ����֧���(��һ����ΪnΪ���ȣ��������0��ʼ
        shift(arr,i,n-1);//������Χ i n-1
    }//end for
    for(i=n-1;i>0;i--){
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        shift(arr,0,i-1);
    }
}
