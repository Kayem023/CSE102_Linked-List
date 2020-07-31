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

void initializeList()
{
    list = 0;  //initially set to NULL
}

int insertItem(int item) //insert at the beginning of the linked list
{
    struct listNode * newNode ;
    newNode = (struct listNode*) malloc (sizeof(struct listNode)) ;
    newNode->item = item ;
    newNode->next = list ; //point to previous first node
    list = newNode ; //set list to point to newnode as this is now the first node
    return SUCCESS_VALUE ;
}


int deleteItem(int item)
{
    struct listNode *temp, *prev ;
    temp = list ; //start at the beginning
    while (temp != 0)
    {
        if (temp->item == item) break ;
        prev = temp;
        temp = temp->next ; //move to next node
    }
    if (temp == 0) return NULL_VALUE ; //item not found to delete
    if (temp == list) //delete the first node
    {
        list = list->next ;
        free(temp) ;
    }
    else
    {
        prev->next = temp->next ;
        free(temp);
    }
    return SUCCESS_VALUE ;
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

int insertLast(int item)
{
    if(!list)
    {
        insertItem(item);
        return SUCCESS_VALUE;
    }
    struct listNode* itemlist;
    itemlist=(struct listNode*)malloc(sizeof(struct listNode));
    itemlist->item=item;
    itemlist->next=NULL;

    struct listNode *temp, *prev ;
    temp = list ; //start at the beginning
    while (temp != 0)
    {
        prev = temp;
        temp = temp->next ; //move to next node
    }

    prev->next=itemlist;

    return SUCCESS_VALUE;

    //write your codes here
}

int insertBefore(int oldItem, int newItem)
{
    struct listNode* newNode;
    struct listNode* prev;
    struct listNode* temp;
    temp=list;
    while(temp!=0&&temp->item!=oldItem)
    {
        prev=temp;
        temp=temp->next;
    }
    if(!temp||list->item==oldItem)
    {
        insertItem(newItem);
        return SUCCESS_VALUE;
    }
    else
    {
        newNode=(struct listNode*)malloc(sizeof(struct listNode));
        newNode->item=newItem;
        newNode->next=temp;
        prev->next=newNode;
    }

    //write your codes here
}

int deleteAfter(int item)
{
    struct listNode* listitem=searchItem(item);
    if(listitem)
    {
        struct listNode* next=listitem->next;
        if(next)
        {
            struct listNode* secondnext=listitem->next->next;
            listitem->next=secondnext;
            free(next);
            return SUCCESS_VALUE;
        }
    }
    else return NULL_VALUE;
    //write your codes here
}

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
    free(prev);

    //write your codes here
}



int main(void)
{
    initializeList();
    while(1)
    {
        printf("1. Insert new item. 2. Delete item. 3. Search item. \n");
        printf("4. (Add from homework). 5. Print. 6. exit.\n");

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
            deleteItem(item);
        }
        else if(ch==3)
        {
            int item;
            scanf("%d", &item);
            struct listNode * res = searchItem(item);
            if(res!=0) printf("Found.\n");
            else printf("Not found.\n");
        }
        else if(ch==4){
            printf(" 1.InsertLast \n 2. InsertBefore \n 3. DeleteAfter \n 4. DeleteLast\n");
            int  ch2;
            scanf("%d",&ch2);
            if(ch2==1){
                int m;
                scanf("%d",&m);
                insertLast(m);
            }
            else if(ch2==2){
                    int m,n;
                    scanf("%d %d",&m,&n);
                    insertBefore(m,n);
            }
            else if(ch2==3){
                int m;
                scanf("%d",&m);
                deleteAfter(m);
            }
            else if(ch2==4){
                deleteLast();
            }
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
