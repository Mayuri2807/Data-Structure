#include<stdio.h>
#include<malloc.h>

struct node
{
	int iData;
	struct node *pNext;
};

void InsertFirst(struct node **,int);
void Display(struct node *);
int DeleteFirst(struct node **);
void DeleteAll(struct node **);

int main(void)
{
	struct node *pFirst=NULL;
	int iDelData=0;

	InsertFirst(&pFirst,10);
	InsertFirst(&pFirst,20);
	InsertFirst(&pFirst,30);
	InsertFirst(&pFirst,40);

	Display(pFirst);

	iDelData=DeleteFirst(&pFirst);
	if(iDelData!=-1)
      printf("Deleted node:|%d|\n",iDelData);

	Display(pFirst);

	 if(NULL!=pFirst)
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

	pNewNode=(struct node *)malloc (sizeof(struct node));

	if(NULL==pNewNode)
	{
		printf("Memory allocation is failed:");
		return ;

	}

	pNewNode->iData=iNo;

	if(NULL==*ppHead)
	{
		pNewNode->pNext=NULL;
		
	}
	else
	{
		pNewNode->pNext=*ppHead;
	}
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
     	while(pHead!=NULL)
     	{
     		printf("|%d|->",pHead->iData);

		    pHead=pHead->pNext;

     	}
		
	}
	printf("|NULL|\n");
}


int DeleteFirst(struct node **ppHead)
{
	int iDelData;
	struct node *pTemp=NULL;

	if(NULL==*ppHead)
	{
		return -1;
	}
	else
	{
		pTemp=*ppHead;
		*ppHead=pTemp->pNext;
		iDelData=pTemp->iData;
		free(pTemp);
		return iDelData;
	}

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