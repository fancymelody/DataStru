/*
  线性表顺序存储结构
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXSIZE 20
typedef int ElemType;
typedef struct{
  ElemType data[MAXSIZE]; //下标0也存数据
  int length; //线性表当前长度
}Sqlist;

//创建链表
int initList(Sqlist* L){
  printf("初始化链表\n");
  printf("请输入链表的长度（小于20）\n");
  scanf("%d",&(L->length));
  if(L->length>MAXSIZE){
    printf("输入长度超过最大长度\n");
    exit(0);
    return -1;
  }
  if(L->length==0){
    printf("链表为空\n");
    return -1;
  }
  srand(time(0));
  for(int i=0;i<L->length;i++){
    L->data[i]=rand()%100+1;
  }
  printf("初始化列表成功");
  return 0;
}

//插入元素
int listInsert(Sqlist* L,int i,ElemType e){
  if(L->length>=MAXSIZE){
    printf("链表已满，不能插入元素\n");
    return -1;
  }
  if(i<0){
    printf("不在插入的范围\n");
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

//删除元素
int listDelete(Sqlist* L,int i){
  if(L->length==0||i<0||i>L->length){
    printf("删除失败\n");
    return -1;
  }
  if(i<=L->length){
    for(int k=i;k<L->length;k++){
        L->data[k]=L->data[k+1];
    }
  }
  L->length--;
  printf("删除成功\n");
  return 0;
}

//将线性表L中第i个位置元素值返回给e
int getElem(Sqlist L,int i,ElemType *e){
   if(L.length==0||i<0||i>L.length){
     printf("查无此元素\n");
     return -1;
   }
   *e=L.data[i];
   return 0;
}

//输出整个列表
int outputList(Sqlist L){
  printf("所有的元素\n");
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
