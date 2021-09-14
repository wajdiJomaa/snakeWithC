# snakeWithC
#this is a simple snake game in c language,this game will work on an ubuntu system 
it uses <ncurses.h> cz i want to read input "getch" but not wait forever for user inserting it
every loop the game wait 300 ms for input so  sometimes it didnt see what user has entered
so it's not a "perfect snake game" , just a game made for fun by a noob
the snake is implemented as a linked list with 2 functions push and pop
every time there is an if to ckeck for loose and another one to check if the snake ate the apple
apples are generated at random poisitions
the draw() function is used to draw the game with width=60 and height=30
to compile the code git clone the repository than run:
gcc -o karlTheSnake  karlTheSnake.c -lncurses
