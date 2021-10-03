#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>



// defining a linked list to store the snake
typedef struct coords
{
    int x;
    int y;
} coords;

typedef struct particle
{
    coords co;
    struct particle *next;

} particle;

typedef struct snake
{
    particle *head;
} snake;
// end of definition , the linked list is called snake

//prototypes
void free_snake(snake *karl);
int head_in_snake(coords start,snake* karl);
//add an element to the head of the snake
void push(snake *karl, coords point)
{
    particle *new;
    new = (particle *)malloc(sizeof(particle));
    new->co = point;
    new->next = karl->head;
    karl->head = new;
}

//check if i and j exists in the snake
int exists(snake karl, int i, int j)
{
    particle *tmp = karl.head;
    while (tmp != NULL)
    {
        if (tmp->co.y == i && tmp->co.x == j)
        {
            return 1;
        }
        tmp = tmp->next;
    }
    return 0;
}
//pop from the snake
void pop(snake *karl)
{
    particle *tmp = karl->head;
    while (tmp->next->next != NULL)
    {
        tmp = tmp->next;
    }
    free(tmp->next);
    tmp->next = NULL;
}

// drawing the game window
void draw(snake karl, coords apple)
{
    for (int i = 0; i <= 30; i++)
    {
        for (int j = 0; j <= 60; j++)
        {
            if (i == 0 || i == 30 || j == 0 || j == 60)
            {
                printf("#");
            }
            else if (exists(karl, i, j))
            {
                printf("x");
            }
            else if (i == apple.y && j == apple.x)
            {
                printf("a");
            }

            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main()
{

    //creating a snake
    snake *karl;
    karl = (snake *)malloc(sizeof(snake));
    karl->head = NULL;
    //adding 3 points to the snake
    coords start = {25, 14};
    push(karl, start);
    start.x += 1;
    push(karl, start);
    start.x += 1;
    push(karl, start);
    //////////////////////////////
    //creating apple
    coords apple = {10, 20};
    //coords variables
    int x = 1;
    int y = 0;
    int eat = 0;
    char state = 'r';
    //the game loop
    while (1)
    {
        char move;
        draw(*karl, apple);
        //checking losing
        if (start.x == 60 || start.x == 0 || start.y == 0 || start.y == 30)
        {
            break;
        }
        if(head_in_snake(start,karl))
        {
            break;
        }
        //check if snake ate the apple
        if (start.x == apple.x && start.y == apple.y)
        {
            eat = 1;
            apple.x = rand() % 60;
            apple.y = rand() % 30;
        }
        else
        {
            eat = 0;
        }
        //getting input
        if(kbhit())
        {
            move = getch();
        }
        
        if (move == 'w' && state !='b')
        {
            y = -1;
            x = 0;
            state = 't';
        }
        else if (move == 's' && state !='t')
        {
            x = 0;
            y = 1;
            state='b';
        }
        else if (move == 'a' && state !='r')
        {
            x = -1;
            y = 0;
            state='l';
        }
        else if (move == 'd' && state !='l')
        {
            x = 1;
            y = 0;
            state='r';
        }
        start.x += x;
        start.y += y;
        push(karl, start);
        if (!eat)
        {
            pop(karl);
        }
        Sleep(100);
       system("cls");
    }
    free_snake(karl);
    return 0;
}


void free_snake(snake *karl)
{

    particle *tmp = karl->head;
    particle* next;
    while(tmp!=NULL)
    {
        next = tmp->next;
        free(tmp);
        tmp = next;
    }
}
int head_in_snake(coords start,snake* karl)
{
    particle* tmp = karl->head->next;
    while (tmp!=NULL)
    {
        if(tmp->co.x == start.x && tmp->co.y == start.y)
        {
            return 1;
        }
        tmp=tmp->next;
    }
    return 0;
}

