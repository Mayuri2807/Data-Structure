#include<stdio.h>
#include<malloc.h>

struct node
{
	int iData;
	struct node *pNext;
	
};
void InsertFirst(struct node **,int);
void Display(struct node*);
void DeleteAll(struct node **);

int main(void)
{
	struct node *pFirst=NULL;

	InsertFirst(&pFirst, 40);
	InsertFirst(&pFirst, 30);
	InsertFirst(&pFirst, 20);
	InsertFirst(&pFirst, 10);


	Display(pFirst);

	  if(pFirst!=NULL)
	 {
	 
	    DeleteAll(&pFirst);
		pFirst=NULL;

	 } 
	 Display(pFirst);

	return 0;
}

void InsertFirst(struct node **ppHead,int iNo)
{
	struct node *pNewNode=NULL;

	pNewNode=(struct node *) malloc (sizeof(struct node));

	if(NULL==pNewNode)
	{
		printf("Memory Allocation Is Failed");
		return;
	}

	pNewNode->iData=iNo;

	if(NULL==*ppHead)
	{
		pNewNode->pNext=NULL;
		*ppHead=pNewNode;
		return;
    }

    pNewNode->pNext=*ppHead;
    *ppHead=pNewNode;
}
void Display(struct node *pHead)
{
	if(NULL==pHead)
	{
		printf("List is empty\n");
		return;

	}
	else
	{
		while(pHead!=NULL)
		{
			printf("|%d|->",pHead->iData);
			pHead=pHead->pNext;
		}
	}
	printf("|NULL|\n");
}
void DeleteAll(struct node **ppHead)
{
	struct node *pTemp=NULL;

	while((*ppHead)!=NULL)
	{
		pTemp=*ppHead;
		*ppHead=(*ppHead)->pNext;
		free(pTemp);
	}
}