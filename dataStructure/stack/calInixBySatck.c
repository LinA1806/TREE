#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#define MIN 1E-7
#define MAXSIZE 100

//��ջʵ������׺���ʽ��ֵ

//�ж�����������ȼ�
int getPriority(char op){
    if(op == '+' || op == '-')
        return 0;
    else
        return 1;
}

int calSub(float opand1,char op,float opand2,float *result){
    if(op == '+') {
        *result = opand1 + opand2;
    }else if(op == '-'){
        *result = opand1 - opand2;
    }else if(op == '*'){
        *result = opand1 * opand2;
    }else if(op == '/'){
        if(fabs(opand2) <  MIN){
            return 0;
        }else{
            *result =  opand1 /opand2;
        }
    }
    //�ɹ�
    return 1;

}
//s1��ջ���������� ���㲢�Ż�s1�ĺ���
int calStackTopTwo(int *top1,float *s1,int *top2,float *s2){
        int flag;

        float opand1 = s1[*top1];
        (*top1)--;
        float opand2 = s1[*top1];
        (*top1)--;
        float temp ;
        char opt = s2[*top2];//s2��ջ�����
        (*top2)--;
        flag = calSub(opand2,opt,opand1,&temp);
        //��ջ
        (*top1)++;
        s1[*top1] = temp;

        return flag ? 1 : 0;
}

float calInfix(char *exp){
    float s1[MAXSIZE]; int top1 = -1;//��������ջ
    float s2[MAXSIZE]; int top2 = -1;
    int i = 0;//����ָ��
    while(exp[i] != '\0'){
        if('0' <= exp[i] && exp[i] <= '9'){//Ϊ������
            s1[++top1] = exp[i] - '0';
            ++i;
        }else if(exp[i] == '('){//Ϊ������
                 s2[++top2] = '(';
                 ++i;
        }else if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/'){
            //��ǰɨ��Ϊ�����
            if(top2 == -1 || s2[top2] == '(' || getPriority(exp[i]) > getPriority(s2[top2])){
                //��ǰɨ�����������ȼ�����s2ջ��,s2ջΪ��,s2ջ��Ϊ�����ţ�����ջ
                    s2[++top2] = exp[i];
                    ++i;
            }else{//����
                int flag = calStackTopTwo(&top1,s1,&top2,s2);
                if(!flag){
                    printf("�����������");
                    return -1e-5;
                }
            }
        }else if(exp[i] == ')'){//��ǰɨ��Ϊ�����ţ���s2һֱ��ջ֪��������
            while(s2[top2] != '('){
                int flag = calStackTopTwo(&top1,s1,&top2,s2);
                if(!flag){
                    printf("�����������");
                    return -1e-5;
                }
            }
            ++i;
            --top2;//��s2��������Ҳ��ջ
        }
    }//end while

    //ջ2���� ��������
    while(top2 != -1){
        int flag = calStackTopTwo(&top1,s1,&top2,s2);
        if(!flag){
            printf("�����������");
            return -1e-5;
        }


    }
    return s1[top1];
}



//��������
int main()
{
    char test[] = {"101*(12+7*5)+6/7+4"};
    float result = calInfix(test);
    printf("%.2f",result);
    return 0;
}
