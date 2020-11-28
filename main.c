#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node
{
    char id[10];
    float price;
    int qty;
    struct node* next;
    struct node* prev;
}node;
struct node* head=NULL;

void insert()
{
    struct node* temp=NULL;
        temp=(node*)malloc(sizeof(struct node));
        printf("\nEnter the Item Id, Price and Quantity of the item:");
        scanf("%s%f%d",temp->id,&temp->price,&temp->qty);
        if(head==NULL)
        {
            temp->next=NULL;
            head=temp;
            temp->prev=head;
            printf("ITEM INSERTED");
        }
        else
        {
            head->prev=temp;
            temp->next=head;
            head=temp;
            printf("ITEM INSERTED");


        }
}

void print()
{
    float total=0.0;
    struct node *temp=NULL;
    if(head==NULL)
    {
        printf("Empty");
    }
    else
        {
            temp=head;
            printf("\n|\tID\t| PRICE\t\t| QUANTITY\t| TOTAL AMOUNT\t|\n");
            while(temp)
            {
                total=temp->price*temp->qty;
                printf("|\t%s\t%f\t  %d\t%f\t|\n",temp->id,temp->price,temp->qty,total);
                temp=temp->next;
            }
        }
}

void ret_item()
{
    struct node* temp=NULL;//*ptemp=NULL, *ntemp=NULL;
    char i[10];
    int flag=0;
    temp=head;
    printf("\nEnter the Item Id of the Item to be returned:");
    scanf("%s",i);
    if(head==NULL)
    {
        printf("No Item to delete");
    }
    while(temp)
    {
        if(!strcmp(temp->id,i))
        {
            flag=1;
            if((temp->next==NULL)&&(temp!=head))
            {
                temp->prev->next=temp->next;
            }
            else if(temp==head)
            {
                head->prev=temp->next;
                head=temp->next;
            }
            else
            {
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
            }
            free(temp);
            break;
        }
        temp=temp->next;
    }
    if(flag)
        printf("\n**********ITEM RETURNED**********\n ");
    print();
}

void bill()
{
    float sbill=0.0,total=0.0;
    struct node* temp=NULL;
    if(head==NULL)
    {
        printf("\nEmpty\n");
    }
    else
        {
            temp=head;
            printf("\n| ID\t| PRICE\t\t| QUANTITY | TOTAL AMOUNT |\n");
            printf("\n______________________________________________________\n");
            while(temp)
            {
                total=temp->price*temp->qty;
                sbill+=total;
                printf("| %s\t%f\t%d\t%f\n",temp->id,temp->price,temp->qty,total);
                temp=temp->next;
            }
        }
            printf("\n______________________________________________________\n");
            printf("\n\t\tTotal stock bill : %f\n",sbill);
}

void del_qty()
{
    struct node* temp=NULL;
    char i[10];
    int q;
    printf("\nEnter the Item Id and Quantity of the item to be removed from the stock:");
    scanf("%s%d",i,&q);

    if(head==NULL)
    {
        printf("\nItem Id not found to delete\n");
    }
    temp=head;
    while(temp!=NULL)
        {
            if(i==temp->id)
                break;
temp=temp->next;
            temp->qty-=q;

            break;
        }

        printf("\n%d Item(s) of ID %s deleted from stock.\n",q,i);

}

void main()
{
    int option;
     do
    {
        printf("\nENTER\n1.Add Item to the stock\n2.Display Stock\n3.Return an Item to the Seller Using item id\n4.Total Stock Bill\n5.Delete Item from the stock\nEnter Option:");
        scanf("%d",&option);
        switch(option)
        {
            case 1:insert();
                    break;
            case 2:printf("\n********************STOCK********************\n");
                    print();
                    break;
            case 3:ret_item();
                    break;
            case 4:printf("\n********************STOCK BILL********************\n");
                    bill();
                    break;
            case 5:del_qty();
                    break;
            default:exit(0);
        }
    }while(1);
}
