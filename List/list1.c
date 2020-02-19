/*
  ���Ա�˳��洢�ṹ
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXSIZE 20
typedef int ElemType;
typedef struct{
  ElemType data[MAXSIZE]; //�±�0Ҳ������
  int length; //���Ա�ǰ����
}Sqlist;

//��������
int initList(Sqlist* L){
  printf("��ʼ������\n");
  printf("����������ĳ��ȣ�С��20��\n");
  scanf("%d",&(L->length));
  if(L->length>MAXSIZE){
    printf("���볤�ȳ�����󳤶�\n");
    exit(0);
    return -1;
  }
  if(L->length==0){
    printf("����Ϊ��\n");
    return -1;
  }
  srand(time(0));
  for(int i=0;i<L->length;i++){
    L->data[i]=rand()%100+1;
  }
  printf("��ʼ���б�ɹ�");
  return 0;
}

//����Ԫ��
int listInsert(Sqlist* L,int i,ElemType e){
  if(L->length>=MAXSIZE){
    printf("�������������ܲ���Ԫ��\n");
    return -1;
  }
  if(i<0){
    printf("���ڲ���ķ�Χ\n");
    return -1;
  }
  if(i<=L->length){
    for(int k=L->length-1;k>=i;k--){
        L->data[k+1]=L->data[k];
    }
  }
  L->data[i]=e;
  L->length++;
  return 0;
}

//ɾ��Ԫ��
int listDelete(Sqlist* L,int i){
  if(L->length==0||i<0||i>L->length){
    printf("ɾ��ʧ��\n");
    return -1;
  }
  if(i<=L->length){
    for(int k=i;k<L->length;k++){
        L->data[k]=L->data[k+1];
    }
  }
  L->length--;
  printf("ɾ���ɹ�\n");
  return 0;
}

//�����Ա�L�е�i��λ��Ԫ��ֵ���ظ�e
int getElem(Sqlist L,int i,ElemType *e){
   if(L.length==0||i<0||i>L.length){
     printf("���޴�Ԫ��\n");
     return -1;
   }
   *e=L.data[i];
   return 0;
}

//��������б�
int outputList(Sqlist L){
  printf("���е�Ԫ��\n");
  for(int i=0;i<L.length;i++){
    printf("%d  ",L.data[i]);
  }
  printf("\n");
  return 0;
}

int main(){
  Sqlist list;
  ElemType result;
  initList(&list);
  outputList(list);
  listInsert(&list,0,0);
  getElem(list,0,&result);
  printf("%d\n",result);
  outputList(list);
  listDelete(&list,0);
  outputList(list);
  return 0;
}
