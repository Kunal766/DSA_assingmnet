#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int row;
    int col;
    int data;
    struct Node *next;
};

void push(struct Node **head, int data, int col, int row)
{
    struct Node *temp, *r;
    temp = *head;
    if (temp == NULL)
    {

        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = data;
        temp->row = row;
        temp->col = col;
        temp->next = NULL;
        *head = temp;
    }
    else
    {
        while (temp->next != NULL)
            temp = temp->next;

        r = (struct Node *)malloc(sizeof(struct Node));
        r->data = data;
        r->row = row;
        r->col = col;
        r->next = NULL;
        temp->next = r;
    }
}

void PrintNode(struct Node *head)
{

    struct Node *temp;
    temp = head;

    while (temp != NULL)
    {

        printf("%d ", temp->row);
        printf("%d ", temp->col);
        printf("%d ", temp->data);
        printf("\n");
        temp = temp->next;
    }
}

struct Node *MultiplyMatrix(struct Node *head1, struct Node *head2, int n)
{

    struct Node *R = NULL, *temp1, *temp2;
    temp1 = head1;
    temp2 = head2;
    int data = 0;
    for (int row = 1; row <= n; row++)
    {
        for (int col = 1; col <= n; col++)
        {
            temp1 = head1;
            temp2 = head2;
            data = 0;

            while (temp1 != NULL)
            {
                if (temp1->row == row)
                    while (temp2 != NULL)
                    {
                        if (temp2->col == col && temp2->row == temp1->col)
                        {
                            data += (temp1->data) * (temp2->data);
                        }
                        temp2 = temp2->next;
                    }
                temp1 = temp1->next;
            }

            if (data != 0)
            {

                push(&R, data, col, row);
            }
        }
    }

    return R;
}

int main()
{

    int n, M, col, row, data;
    struct Node *head1 = NULL, *head2 = NULL, *tail1, *tail2;

    scanf("%d", &n);
    while (1)
    {
        scanf("%d", &M);
        if (M == 0)
            break;
        scanf("%d", &row);
        scanf("%d", &col);
        scanf("%d", &data);
        if (M == 1)
        {
            push(&head1, data, col, row);
        }
        if (M == 2)
        {
            push(&head2, data, col, row);
        }
    }
    // PrintNode(head1);
    PrintNode(MultiplyMatrix(head1, head2, n));

    return 0;
}
