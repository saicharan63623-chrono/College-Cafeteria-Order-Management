
#include <stdio.h>
#include <string.h>

#define SIZE 5

struct Order
{
    int orderNo;
    char studentName[30];
    char foodItem[30];
};

struct Order queue[SIZE];

int front = -1;
int rear = -1;

// Function to place a new order
void enqueue()
{
    if ((rear + 1) % SIZE == front)
    {
        printf("\nQueue is Full!\n");
        return;
    }

    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = (rear + 1) % SIZE;
    }

    printf("Enter Order Number: ");
    scanf("%d", &queue[rear].orderNo);
    getchar();

    printf("Enter Student Name: ");
    fgets(queue[rear].studentName, 30, stdin);
    queue[rear].studentName[strcspn(queue[rear].studentName, "\n")] = '\0';

    printf("Enter Food Item: ");
    fgets(queue[rear].foodItem, 30, stdin);
    queue[rear].foodItem[strcspn(queue[rear].foodItem, "\n")] = '\0';

    printf("\nOrder placed successfully!\n");
}

// Function to serve an order
void dequeue()
{
    if (front == -1)
    {
        printf("\nNo pending orders!\n");
        return;
    }

    printf("\nOrder Served!\n");
    printf("Order Number: %d\n", queue[front].orderNo);
    printf("Student Name: %s\n", queue[front].studentName);
    printf("Food Item: %s\n", queue[front].foodItem);

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % SIZE;
    }
}

// Function to display pending orders
void display()
{
    int i;

    if (front == -1)
    {
        printf("\nNo pending orders!\n");
        return;
    }

    printf("\n--- Pending Orders ---\n");

    i = front;

    while (1)
    {
        printf("\nOrder Number: %d\n", queue[i].orderNo);
        printf("Student Name: %s\n", queue[i].studentName);
        printf("Food Item: %s\n", queue[i].foodItem);

        if (i == rear)
            break;

        i = (i + 1) % SIZE;
    }
}

// Function to view the next order
void peek()
{
    if (front == -1)
    {
        printf("\nNo pending orders!\n");
        return;
    }

    printf("\n--- Next Order ---\n");
    printf("Order Number: %d\n", queue[front].orderNo);
    printf("Student Name: %s\n", queue[front].studentName);
    printf("Food Item: %s\n", queue[front].foodItem);
}

// Main function
int main()
{
    int choice;

    while (1)
    {
        printf("\n===== COLLEGE CAFETERIA =====\n");
        printf("1. Place Order\n");
        printf("2. Serve Order\n");
        printf("3. Display Pending Orders\n");
        printf("4. View Next Order\n");
        printf("5. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                peek();
                break;

            case 5:
                printf("\nThank you for using the Cafeteria System!\n");
                return 0;

            default:
                printf("\nInvalid choice!\n");
        }
    }

    return 0;
}
