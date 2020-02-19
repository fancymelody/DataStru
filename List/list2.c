/*
  单链表链式存储结构
  头指针与头结点的异同：
  头指针：
  1、头指针是指链表指向第一个结点的指针，若链表有头结点，则是指向头结点的指针
  2、无论链表是否为空，头指针均不为空
  3、头指针是链表的必要元素
  头结点：
  1、头结点是为了操作的统一和方便而设立的，放在第一个元素的结点之前，其数据域一般无意义（但也可以用来存放链表的长度）
  2、头结点不一定是链表的必要元素
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef int ElemType;
typedef struct Node{
  ElemType data;
  struct Node* next; //下一个结点的地址
}Node;
typedef struct Node* LinkList;

/*
 头插法建立单链表
 头插法从一个空表开始，生成新结点，读取数据存放到新结点的数据域中，然后将新结点插入到当前链表的表头上，直到结束为止
 始终让新结点插在第一的位置
*/
//L是指向LinkList(即Node*)的指针类型,*L和LinkList类型一样
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

//尾插法建立单链表
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
    printf("查无此元素\n");
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
     printf("插入失败\n");
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
    printf("删除失败\n");
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
    printf("此链表为空\n");
  }
  LinkList temp=L;
  while(temp->next!=NULL){
    temp=temp->next;
    printf("%d  ",temp->data);
  }
  printf("\n");
}

int main(){
  LinkList head=NULL; //链表的头指针
  ElemType result;
  createListHead(&head,5); //创建链表
  //createListTail(&head,5); //创建链表
  outputList(head);
  listInsert(&head,2,0);
  getElem(head,2,&result);
  printf("%d\n",result);
  outputList(head);
  listDelete(&head,2);
  outputList(head);
  clearList(&head);
  printf("清空后\n");
  outputList(head);
  return 0;
}
