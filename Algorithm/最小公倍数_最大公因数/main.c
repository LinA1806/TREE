#include <stdio.h>
#include <stdlib.h>
#define PI 3.14


//ŷ������㷨 ����С��Լ��
int getHCF(int m,int n){
    int temp;
    while(n != 0){
        temp = n;
        n = m%n;
        m = temp;
    }
    return m;
}


int main()
{
    int m,n;
    scanf("%d %d",&m,&n);

    int HCF = getHCF(m,n);
    printf("���Լ��:%d\n",HCF);
    printf("��С������:%d",m*n/HCF);


    return 0;
}
