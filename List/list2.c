/*
  ��������ʽ�洢�ṹ
  ͷָ����ͷ������ͬ��
  ͷָ�룺
  1��ͷָ����ָ����ָ���һ������ָ�룬��������ͷ��㣬����ָ��ͷ����ָ��
  2�����������Ƿ�Ϊ�գ�ͷָ�����Ϊ��
  3��ͷָ��������ı�ҪԪ��
  ͷ��㣺
  1��ͷ�����Ϊ�˲�����ͳһ�ͷ���������ģ����ڵ�һ��Ԫ�صĽ��֮ǰ����������һ�������壨��Ҳ���������������ĳ��ȣ�
  2��ͷ��㲻һ��������ı�ҪԪ��
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef int ElemType;
typedef struct Node{
  ElemType data;
  struct Node* next; //��һ�����ĵ�ַ
}Node;
typedef struct Node* LinkList;

/*
 ͷ�巨����������
 ͷ�巨��һ���ձ�ʼ�������½�㣬��ȡ���ݴ�ŵ��½����������У�Ȼ���½����뵽��ǰ����ı�ͷ�ϣ�ֱ������Ϊֹ
 ʼ�����½����ڵ�һ��λ��
*/
//L��ָ��LinkList(��Node*)��ָ������,*L��LinkList����һ��
void createListHead(LinkList *L,int n){
  LinkList p;
  int i;
  srand(time(0));
  *L=(LinkList)malloc(sizeof(Node));
  (*L)->next=NULL;
  for(i=0;i<n;i++){
    p=(LinkList)malloc(sizeof(Node));
    p->data=rand()%100+1;
    p->next=(*L)->next;
    (*L)->next=p;
  }
}

//β�巨����������
void createListTail(LinkList *L,int n){
   LinkList p,r;
   int i;
   srand(time(0));
   *L=(LinkList)malloc(sizeof(Node));
   r=*L;
   for(i=0;i<n;i++){
     p=(LinkList)malloc(sizeof(Node));
     p->data=rand()%100+1;
     r->next=p;
     r=p;
   }
   r->next=NULL;
}

int getElem(LinkList L,int i,ElemType *e){
  int j;
  LinkList p;
  p=L->next;
  j=1;
  while(p&&j<i){
    p=p->next;
    ++j;
  }
  if(!p||j<i){
    printf("���޴�Ԫ��\n");
    return -1;
  }
  *e=p->data;
  return 0;
}

int listInsert(LinkList *L,int i,ElemType e){
   int j;
   LinkList p,s;
   p=*L;
   j=1;
   while(p&&j<i){
     p=p->next;
     j++;
   }
   if(!p){
     printf("����ʧ��\n");
     return -1;
   }
   s=(LinkList)malloc(sizeof(Node));
   s->data=e;
   s->next=p->next;
   p->next=s;
   return 0;
}

int listDelete(LinkList *L,int i){
  int j;
  LinkList p,q;
  p=*L;
  j=1;
  while(p->next&&j<i){
    p=p->next;
    j++;
  }
  if(!(p->next)){
    printf("ɾ��ʧ��\n");
    return -1;
  }
  q=p->next;
  p->next=q->next;
  free(q);
  return 0;
}

int clearList(LinkList *L){
  LinkList p,q;
  p=(*L)->next;
  while(p){
    q=p->next;
    free(p);
    p=q;
  }
  (*L)->next=NULL;
  return 0;
}

void outputList(LinkList L){
  if(L->next==NULL){
    printf("������Ϊ��\n");
  }
  LinkList temp=L;
  while(temp->next!=NULL){
    temp=temp->next;
    printf("%d  ",temp->data);
  }
  printf("\n");
}

int main(){
  LinkList head=NULL; //�����ͷָ��
  ElemType result;
  createListHead(&head,5); //��������
  //createListTail(&head,5); //��������
  outputList(head);
  listInsert(&head,2,0);
  getElem(head,2,&result);
  printf("%d\n",result);
  outputList(head);
  listDelete(&head,2);
  outputList(head);
  clearList(&head);
  printf("��պ�\n");
  outputList(head);
  return 0;
}
