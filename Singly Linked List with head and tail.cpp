#include<stdio.h>
#include<stdlib.h>


#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999

struct listNode
{
    int item;
    struct listNode * next;
};

struct listNode * list;
struct listNode * tail;

void initializeList()
{
    list = 0;  //initially set to NULL
	tail = 0;
}

struct listNode * searchItem(int item)
{
	struct listNode * temp ;
	temp = list ; //start at the beginning
	while (temp != 0)
	{
		if (temp->item == item) return temp ;
		temp = temp->next ; //move to next node
	}
	return 0 ; //0 means invalid pointer in C, also called NULL value in C
}

void printList()
{
    struct listNode * temp;
    temp = list;
    while(temp!=0)
    {
        printf("%d->", temp->item);
        temp = temp->next;
    }
    printf("\n");
}



//add required codes to insert item at the beginning, remember to properly set the tail pointer!
int insertItem(int item)
{
	//write your codes here
	struct listNode *newItem;
	newItem=(struct listNode*)malloc(sizeof(struct listNode));
	newItem->item=item;
	if(!list)
    {
        newItem->next=0;
        tail=newItem;
        list=newItem;
    }
    else {
        newItem->next=list;
        list=newItem;
    }
    return SUCCESS_VALUE;
}

//add required codes to delete item, remember to properly set the tail pointer!
int deleteAfter(int item)
{
    struct listNode *temp;
    struct listNode *temp2;
    temp=searchItem(item);
    if(temp)
    {
        if(temp==tail)
        {
            return NULL_VALUE;
        }
        else if(temp->next==tail)
        {
            temp2=tail;
            temp->next=0;
            tail=temp;
            free(temp2);
            return SUCCESS_VALUE;
        }
        else {
            temp2=temp->next;
            temp->next=temp2->next;
            free(temp2);
            return SUCCESS_VALUE;
        }
    }
    return NULL_VALUE;
}
/*
int deleteLast()
{
    struct listNode* temp;
    struct listNode* prev;
    struct listNode* secondprev;
    temp=list;
    if(!list)
    {
        return NULL_VALUE;
    }
    else if(!temp->next)
    {
        list=0;
        tail=0;
        free(temp);
        return SUCCESS_VALUE;
    }
    prev=temp;
    temp=temp->next;

    while(temp!=0)
    {
        secondprev=prev;
        prev=temp;
        temp=temp->next;
    }
    secondprev->next=temp;
    tail=secondprev;
    free(prev);
}
*/

int insertLast(int item)
{
    //write your codes here
    struct listNode *newItem;
    newItem=(struct listNode*)malloc(sizeof(struct listNode));
    newItem->item=item;
    newItem->next=0;
    tail->next=newItem;
    tail=newItem;
    if(!list)
    {
        list=newItem;
    }
    return SUCCESS_VALUE;
}


int main(void)
{
    initializeList();
    while(1)
    {
        printf("1. Insert new item At first. 2. Delete After. 3. Search item. \n");
        printf("4. Insert new Item At last. 5. Print. 6. exit.\n");

        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int item;
            scanf("%d", &item);
            insertItem(item);
        }
        else if(ch==2)
        {
            int item;
            scanf("%d", &item);
            deleteAfter(item);
        }
        else if(ch==3)
        {
            int item;
            scanf("%d", &item);
            struct listNode * res = searchItem(item);
            if(res!=0) printf("Found.\n");
            else printf("Not found.\n");
        }
        else if(ch==4)
        {
            int item;
            scanf("%d",&item);
            insertLast(item);
        }
        else if(ch==5)
        {
            printList();
        }
        else if(ch==6)
        {
            break;
        }
    }

}
