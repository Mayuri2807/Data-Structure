	#include<stdio.h>
#include<malloc.h>

struct node
{
	int iData;
	struct node *pNext;
};

void InsertLast(struct node **,int);
void Display(struct node *);
int SearchAllOccurences(struct node *,int);
void DeleteAll(struct node **);

int main(void)
{
	struct node *pFirst=NULL;
	int iLastPos;
	int iKey;

	InsertLast(&pFirst,10);
	InsertLast(&pFirst,20);
	InsertLast(&pFirst,30);
	InsertLast(&pFirst,40);
	InsertLast(&pFirst,40);
	InsertLast(&pFirst,20);

	Display(pFirst);

	printf("Enter a Key you Want to Search:\n");
	scanf("%d",&iKey);

	iLastPos=SearchAllOccurences(pFirst,iKey);

    printf("All  Occurance are:%d\n",iLastPos);

	if(pFirst!=NULL)
	{
	   DeleteAll(&pFirst);
	   pFirst=NULL;
	}
	Display(pFirst);
	return 0;

}

void InsertLast(struct node **ppHead,int iNo)
{
	struct node *pNewNode=NULL;
	struct node *pTemp=NULL;


	pNewNode=(struct node *)malloc(sizeof(struct node));

	if(NULL==pNewNode)
	{
		printf("Memory allocation is failed");
		return ;
	}

	pNewNode->iData=iNo;
	pNewNode->pNext=NULL;

	if(NULL==*ppHead)
	{
		*ppHead=pNewNode;
		return;
	}

	pTemp=*ppHead ;
     
     while(pTemp->pNext!=NULL)
	{
		pTemp=pTemp->pNext;
		
	}
	pTemp->pNext=pNewNode;
}
void Display(struct node *pHead)
{
	if(NULL==pHead)
	{
		printf("List is Empty");
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

int SearchAllOccurences(struct node *pHead,int iKey)
{
	int iCount=0;

	while(pHead!=NULL)
	{
		if(pHead->iData==iKey)
		iCount++;
	pHead=pHead->pNext;


	}
	return iCount;
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