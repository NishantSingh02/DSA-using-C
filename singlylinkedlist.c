/* Singly Linked List Operations*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *root = NULL;

void display();
void append();
void insertatbegin();
void insertatend();
void insertafter();
int length();
void deletebyloc();
void deletebyvalue();

void main()
{
    int ch, len;
    while (1)
    {
        printf("1. Display\n");
        printf("2. Append\n");
        printf("3. Insert element at beginning\n");
        printf("4. Insert element at end\n");
        printf("5. Insert element after\n");
        printf("6. Length\n");
        printf("7. Delete an element by Location\n");
        printf("8. Delete an element by Value\n");
        printf("9. Exit\n");

        printf("Enter your Choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            display();
            break;
        case 2:
            append();
            break;
        case 3:
            insertatbegin();
            break;
        case 4:
            insertatend();
            break;
        case 5:
            insertafter();
            break;
        case 6:
            len = length();
            printf("Length: %d\n", len);
            break;
        case 7:
            deletebyloc();
            break;
        case 8:
            deletebyvalue();
            break;
        default:
            exit(0);
            break;
        }
    }
}

void append()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d", &temp->data);
    temp->link = NULL;

    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        struct node *p = root;
        while (p->link != NULL)
        {
            p = p->link;
        }
        p->link = temp;
    }
    display();
}

void insertatbegin()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d", &temp->data);

    if (root == NULL)
    {
        temp->link = NULL;
        root = temp;
    }
    else
    {
        temp->link = root;
        root = temp;
    }
    display();
}

void insertatend()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d", &temp->data);
    temp->link = NULL;

    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        struct node *p = root;
        while (p->link != NULL)
        {
            p = p->link;
        }
        p->link = temp;
    }
    display();
}

void insertafter()
{
    struct node *temp, *p;

    int loc, len, i = 1;
    printf("Enter the location after to add:");
    scanf("%d", &loc);
    len = length();
    if (loc > len)
    {
        printf("Invalid Location. \n");
    }
    else
    {
        temp = (struct node *)malloc(sizeof(struct node));
        printf("Enter node data:");
        scanf("%d", &temp->data);
        p = root;
        if(loc==0)
        {
        temp->link = root;
        root = temp;
        }
        else
        {
        while (i < loc)
        {
            p = p->link;
            i++;
        }
        temp->link = p->link;
        p->link = temp;
        }
    }
    display();
}

void display()
{
    struct node *temp;
    temp = root;
    if (temp == NULL)
    {
        printf("List is Empty");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d-->", temp->data);
            temp = temp->link;
        }
    }
    printf("\n\n");
}

int length()
{
    int count = 0;
    struct node *temp = root;

    while (temp != NULL)
    {
        temp = temp->link;
        count++;
    }
    return count;
}

void deletebyloc()
{
    int loc, i, len;
    len = length();
    struct node *temp = root;
    printf("Enter the location of the element");
    scanf("%d", &loc);
    if (loc > len)
        printf("location not available\n\n");

    else if (loc == 1)
    {
        root = temp->link;
        temp->link = NULL;

        free(temp);
    }

    else
    {
        struct node *temp1 = root, *temp2;
        int i = 1;
        while (i < loc - 1)
        {
            temp1 = temp1->link;
            i++;
        }
        temp2 = temp1->link;
        temp1->link = temp2->link;
        temp2->link = NULL;
        free(temp2);
    }
    display();
}

void deletebyvalue()
{
    int item;
    struct node *temp = root;
    printf("Enter the element");
    scanf("%d", &item);
    if (temp == NULL)
        printf("Linked List is Empty\n\n");

    else if (temp->data == item)
    {
        root = temp->link;
        temp->link = NULL;

        free(temp);
    }

    else
    {
        struct node *temp1 = root, *temp2 = root->link;
        while (temp2 != NULL)
        {
            if (temp2->data == item)
            {
                temp1->link = temp2->link;
                temp2->link = NULL;
                free(temp2);
            }
            temp1 = temp2;
            temp2 = temp2->link;
        }
        display();
    }
}