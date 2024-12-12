#include<stdio.h>
#include<string.h>
typedef struct Book
{
    int id;
    char name[100];
    char author[100];
    int availability;    
}b;
b library[5]; 
int totalbooks=0;
void addbook()
{
    if(totalbooks>=5)
    {
        printf("The Library is full, Cannot add more books");
        return;
    }
    b n;
    n.id=totalbooks+1;
    printf("Enter book title: ");
    getchar();
    fgets(n.name,sizeof(n.name),stdin);
    n.name[strcspn(n.name, "\n")] = 0;
    printf("Enter author's name: ");
    fgets(n.author,sizeof(n.author),stdin);
    n.author[strcspn(n.author, "\n")] = 0;
    n.availability=1;
    library[totalbooks]=n;
    totalbooks++;
    printf("Book added succesfully");
}
void display()
{
    if(totalbooks==0)
    {
        printf("There are no available books in library");
        return;
    }
    printf("List of books:");
    for(int i=0;i<totalbooks;i++)
    {
        printf("\nID: %d \nTitle: %s \nAuthor: %s \nAvailability: %s\n",library[i].id,library[i].name,library[i].author,library[i].availability?"Yes":"No");
    }
}
void lend()
{
    int id;
    printf("Enter the ID of the book you want to borrow");
    scanf("%d",&id);
    if(id<1||id>totalbooks)
    {
        printf("Invalid book id");
        return;
    }
    if(library[id-1].availability)
    {
        library[id-1].availability=0;
        printf("You have successfully borrowed %s",library[id-1].name);
    }
    else
    {
        printf("The book is currently unavailable");
    }
}
void retur_n()
{
    int id;
    printf("Enter the book id: ");
    scanf("%d",&id);
    if(id<1||id>totalbooks)
    {
        printf("Please enter valid ID");
        return;
    }
    if(!library[id-1].availability)
    {
        library[id-1].availability=1;
        printf("The book %s was successfully returned",library[id-1].name);
    }
    else
    {
        printf("This book was not lent out");
    }
}
int main()
{
    int c;
    f:printf("\nWelcome to our library management system\n1: Display books\n2: Add book\n3: Borrow book\n4: Return book\n5: Exit");
    printf("\nEnter the choice you want to perform:");
    scanf("%d",&c);
    switch(c)
    {
        case 1:display();
        goto f;
        case 2:addbook();
        goto f;
        case 3:lend();
        goto f;
        case 4:retur_n();
        goto f;
        case 5:printf("Exiting the system.");
        break;
        default:printf("Please enter a valid choice");
    }
}