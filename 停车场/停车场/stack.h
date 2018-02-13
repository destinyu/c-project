#pragma once
typedef int Status;
typedef int SElemType;
#define MAXSIZE 2
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#include <malloc.h>
typedef struct {
	SElemType data[MAXSIZE];
	SElemType time[MAXSIZE];
	int top=-1;
}SqStack;


Status InitStack(SqStack *S)
{
	/* S.data=(SElemType *)malloc(MAXSIZE*sizeof(SElemType)); */
	S->top = -1;
	return OK;
}

/* 把S置为空栈 */
Status ClearStack(SqStack *S)
{
	S->top = -1;
	return OK;
}

/* 若栈S为空栈，则返回TRUE，否则返回FALSE */
Status StackEmpty(SqStack S)
{
	if (S.top == -1)
		return TRUE;
	else
		return FALSE;
}

/* 返回S的元素个数，即栈的长度 */
int StackLength(SqStack S)
{
	return S.top + 1;
}

/* 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR */
Status GetTopdata(SqStack S, SElemType *e)
{
	if (S.top == -1)
		return ERROR;
	else
		*e = S.data[S.top];

	return OK;
}
Status GetToptime(SqStack S, SElemType *e)
{
	if (S.top == -1)
		return ERROR;
	else
		*e = S.time[S.top];

	return OK;
}


/* 插入元素e为新的栈顶元素 */
Status Push(SqStack *S, SElemType e,SElemType k)
{
	if (S->top == MAXSIZE - 1) /* 栈满 */
	{
		return ERROR;
	}
	S->top++;				/* 栈顶指针增加一 */
	S->data[S->top] = e;/* 将新插入元素赋值给栈顶空间 */
	S->time[S->top] = k;
	return OK;
}

/* 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR */
Status Pop(SqStack *S, SElemType *e,SElemType *k)
{
	if (S->top == -1)
		return ERROR;
	*e = S->data[S->top];	/* 将要删除的栈顶元素赋值给e */
	*k = S->time[S->top];
	S->top--;				/* 栈顶指针减一 */
	return OK;
}

/* 从栈底到栈顶依次对栈中每个元素显示 */
/*Status StackTraverse(SqStack S)
{
	int i;
	i = 0;
	while (i <= S.top)
	{
		visit(S.data[i++]);
	}
	printf("\n");
	return OK;
}*/
