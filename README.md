# ASCII-Roguelike-RPG-game
An ASCII Roguelike RPG game using random ASCII characrters ,graphics and some other  functions of the C language.
1.PROBLEM DESCRIPTION:
Making an ASCII Roguelike RPG game using random ASCII characrters ,graphics and some other  functions of the C language.The game starts with the 1st level having monsters  “Z” while the player have to collect gold coins an amount of gold coins “S” set for each level while having only a limited lives set for each level which can reduce after the player comes in contact with the monster.
2.FEATURES OF THE PROGRAM:
The distuinguishing features of the code are mentioned below:
•	The game consists of three levels having different boundary design of walls .
•	A number of programming functionalities are used in the making of a code to make the player and other characters of the game stays between the boundaries.
Our project is totally based on the fundamentals/logics of the programming considering the aim of our course. It can also tell the main programming constructs used in the programs.

3.THE CHALLENGES  And THE STEPS  OF THE PROGRAM:
The most challenging part was the approach to the whole concept of our game as this idea of this game was completely though from scratch by us and we have to make a boundary for the player and the other characters to move so we have used multiples approaches to make the code nderstandable for everyone and to implement our idea.The first step was defining some constant values needed for the program then we made a structure for thecoordinates, player, ghosts.Then we setup gloabal variables of type struct.After that we setup how our program will take the input and move using arrow keys.For this -_khbit function was used. The _kbhit function checks the console for a recent keystroke.  The program then call _getch to get the keystroke. Then we set the cursor positions by using function  as at the backend an infinite loop is running so the position must have to be set again and again and then we hide the cursor by making use of another function.Then for level 1,2 and 3 we set individual playfields through a 2D array and then we initialized the charaters and then made another function to make sure they moves and moves within the set boundary.Then we made 3 more functions for each level in which we call all te necessary functions fo game and then we called those 3 function and the starting function in the main and connect those three by scanf statemens, to make the code look more neat and easy to understand. The other challenging thing was making the gold coins appear only inside the limited boundary.This problem was solved by adding  numerous  conditions in the program. Additionally the functions with details are explained below:
DETAILS OF THE CODE:
The code uses the struct coord to define the position of an object. The structure has two integer variables x and y that hold the x and y coordinates respectively. The struct Player holds the player's position, velocity, lives, chasing status and gold. The position of the player is stored in a struct coord variable called position. The velocity of the player in the x and y directions is stored in the vx and vy variables respectively. The lives variable holds the number of lives the player has, chasing is a boolean variable that indicates whether the player is currently chasing a ghost, and the gold variable keeps track of the player's gold.
FUNCTIONALITIES:
•	The struct Ghost holds the position, velocity, and chasing status of the ghosts. The position of the ghosts is stored in a struct coord variable called position, the velocity of the ghosts in the x and y directions is stored in the vx and vy variables respectively, and the chasing variable is a boolean that indicates whether the ghost is currently chasing the player.
•	The code uses two constants H and W which are defined as 30 and 60 respectively. These constants are used to define the size of the 2D array playfield which is used as the game field. The size of the playfield is 30 rows and 60 columns.
•	The code uses rand() function to generate random numbers. These random numbers are used to randomly place the '$' in the playfield.
•	The code uses _kbhit() and _getch() functions to check for and handle user input, respectively. These functions are specific to the Windows operating system and are used to detect if a key has been pressed and to read the character of the key pressed.
•	The code uses set_cursor_position(int x, int y) function which set the cursor at the specified x and y coordinates.
•	The code uses hidecursor() function, this function is used to hide the cursor in the console.
•	check_for_collisions() function is used to check for collisions between the player and the ghosts, but it is not implemented in the provided code snippet.
•	user_input() function is used to handle the user input, it takes the input from the user and sets the velocity of the player accordingly.
•	initialize() function is used to initialize the game, it randomly places the '$' symbols in the playfield.
•	The play variable is an instance of the struct Player and it is used to store the player's information throughout the game.
•	The allGhosts variable is an array of struct Ghost and it is used to store the information of all the ghosts in the game.
•	The playfield 2D array is initialized with the layout of the game field. It is filled with "#" for walls and " " for the paths.
•	The NR_GHOSTS constant is defined as 70, this means that the game can have up to 70 ghosts.
•	The name variable is a character array and it's used to store the name of the player.
•	The exit1 variable is a character variable, which is used to check if the player wants to exit the game.
•	The score variable is an integer variable that keeps track of the player's score.
•	The code uses the conio.h and windows.h header files. conio.h is a C library primarily used for console input/output and windows.h is a header file of the Windows API.
•	The stdbool.h header file is used to define the bool data type in C.
•	The stdio.h and stdlib.h headers are used to perform input and output operations and to handle memory allocation and random number generation respectively.
•	The time.h header is used to seed the random number generator.
•	The game uses a while loop to run the game until the player wants to exit or the player's lives become zero.
•	The code uses the Sleep() function from the windows.h library to create a delay between each game iteration.
•	The code uses the system(“cls”) function to clear the console window before each iteration.
