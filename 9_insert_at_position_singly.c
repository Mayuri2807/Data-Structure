#include<stdio.h>
#include<malloc.h>

struct node 
{
     int iData;
     struct node *pNext;

};

void InsertFirst(struct node **,int);
void Display(struct node *);
int CountNode(struct node *);
void InsertAtPostion(struct node **,int,int);
void DeleteAll(struct node **);

int main(void)
{

	struct node *pFirst=NULL;
	int iCount;

	InsertFirst(&pFirst,40);
	InsertFirst(&pFirst,30);
	InsertFirst(&pFirst,20);
	InsertFirst(&pFirst,10);

     Display(pFirst);

     iCount=CountNode(pFirst);
     printf("Total node is:%d\n",iCount);

     InsertAtPostion(&pFirst,50,2);

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
	   printf("List is empty");
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
int CountNode(struct node *pHead)
{
	 int iCount=0;

	while(pHead!=NULL)
	{
		iCount++;
		pHead=pHead->pNext;
	}
	return iCount;
}
void InsertAtPostion(struct node **ppHead,int iNo,int iPos)
{
	int iCount;
	struct node *pNewNode=NULL;
	struct node *pTemp=NULL;

	iCount=CountNode(*ppHead);

	if(iPos<=0 || iPos>iCount+1)
	{
		printf("position is invalid");
		return;
	}
	if(1==iPos)
	{
		InsertFirst(ppHead,iNo);
		return;
	}
   
    pNewNode=(struct node *)malloc(sizeof(struct node));

    if(NULL==pNewNode)
    {
    	printf("memory allocation is failed");
      return;

    }
    	
     pNewNode->iData=iNo;

      pTemp=*ppHead;
      iCount=1;

    while(iCount<iPos-1)
    {
    	iCount++;
    	pTemp=pTemp->pNext;

    }
    pNewNode->pNext=pTemp->pNext;
    pTemp->pNext=pNewNode;
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