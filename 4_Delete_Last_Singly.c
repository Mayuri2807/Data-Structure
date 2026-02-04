#include<stdio.h>
#include<malloc.h>

struct node
{
	int iData;
	struct node *pNext;
};

void InsertFirst(struct node **,int);
void Display(struct node *);
int DeleteLast(struct node **);
void DeleteAll(struct node **);

int main(void)
{
	int iDelData=0;
	struct node *pFirst=NULL;

	InsertFirst(&pFirst,10);
	InsertFirst(&pFirst,20);
	InsertFirst(&pFirst,30);
	InsertFirst(&pFirst,40);

	Display(pFirst);

	iDelData=DeleteLast(&pFirst);
	if(iDelData!=-1)
       printf("Deleted node is:|%d|\n",iDelData);
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

	pNewNode=(struct node *)malloc(sizeof(struct node));

	if(NULL==pNewNode)
	{
		printf("Mmeory allocation is failed");
		return;
	}

	pNewNode->iData=iNo;

	if(NULL==*ppHead)
	{
		pNewNode->pNext=NULL;

	}
	pNewNode->pNext=*ppHead;
	*ppHead=pNewNode;
}
void Display(struct node *pHead)
{
	if(NULL==pHead)
	{
		printf("List is empty");
		return ;
	}
	else
	{
		while(NULL!=pHead)
		{
			printf("|%d|->",pHead->iData);
			pHead=pHead->pNext;
		}
	}
	printf("|NULL|\n");
}

int DeleteLast(struct node **ppHead)
{
	int iDelData;
	struct node *pTemp=NULL;

	if(NULL==*ppHead)
	{
		return -1;
	}

	pTemp=*ppHead;

	if(NULL==pTemp->pNext)
	{
		iDelData=pTemp->iData;
		free(pTemp);
		*ppHead=NULL;
	}
	else
	{
		while(pTemp->pNext->pNext!=NULL)
			pTemp=pTemp->pNext;

		iDelData=pTemp->pNext->iData;
		free(pTemp->pNext);
		pTemp->pNext=NULL;
		
	}
	return iDelData;

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