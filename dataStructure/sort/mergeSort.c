#include <stdio.h>

//��һ����������������������У��鲢���и���������
void merge(int *arr,int low,int mid,int high){
    int i,j,k;
    int n1 = mid - low + 1;//�ֳ���������ĳ���
    int n2 = high - mid;
    int L[n1],R[n2];
    for(i=0;i<n1;i++){
        L[i] = arr[low+i];
    }
    for(j=0;j<n2;j++){
        R[j] = arr[mid+1+j];
    }
    i = 0;
    j = 0;
    k = low;
    while(i<n1 && j<n2){
        if(L[i] <= R[j])
            arr[k] = L[i++];
        else
            arr[k] = R[j++];
        k++;
    }//end while
    while(i<n1) arr[k++] = L[i++];
    while(j<n2) arr[k++] = R[j++];
}//end fun

//�鲢����������
void mergeSort(int arr[],int low,int high){
    if(low < high){//�鲢����
        int mid = (low+high)>>1;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}
