#include <stdio.h> 
#include <conio.h> 
#include <windows.h>
#include <stdbool.h>
#include<stdlib.h>
#include<time.h>

#define H 30
#define W 60
#define NR_GHOSTS 70
char name[20],exit1;
int score=0;
struct coord
{
   int x;
   int y;
};

struct Player {
   struct coord position;
   int vx;
   int vy;
   int lives;
   bool chasing;
   int gold;
};


struct Ghost {
   struct coord position;
   int vx;
   int vy;
   bool chasing;
};


struct Ghost allGhosts[NR_GHOSTS];

struct Player play = {
                           {
                              .x = 1,
                              .y = 1,
                           },
                           .vx = 0,
                           .vy = 0,
                           .lives = 3,
                           .chasing = false,
                           .gold = 0
                         };
                        
						

void user_input()
{
   if (_kbhit())
   {
      char c1 = _getch();

      if (c1 == -32)
      {
         char c2 = _getch();

        play.vx = 0;
         play.vy = 0;

         switch (c2)
         {
            case 72: play.vy = -1; break; // cursor up
            case 80: play.vy = +1; break; // cursor down
            case 75: play.vx = -1; break; // cursor left
            case 77: play.vx = +1; break; // cursor right
         }
      }


      

   }
}
void set_cursor_position(int x, int y)
{
   
   COORD coord = { x, y };

     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

} 


void hidecursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}


//FOR LEVEL 1
char playfield[H][W] =
{ 
   { "############################################################" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "############################################################" }
}; 
void initialize()
{
	 int g11,g22;
g11=(rand()%25)+1;
g22=(rand()%40)+1;
if(playfield[g11][g22]!='#'){
playfield[g11][g22]='$';
}
else
{
	g11=(rand()%21)+1;
g22=(rand()%41)+1;
}
for (int i = 0; i < H; i++)
   {
      for (int j = 0; j < W; j++)
      {
         if (playfield[i][j]==' ')
            playfield[i][j] = ' ';
    
      }
   }


   for (int i = 0; i < NR_GHOSTS; i++)
   { int x,y;
      allGhosts[i].vx = 0;
      allGhosts[i].vy =  0;
      allGhosts[i].chasing = true;

    
      
      do
      {
         x = 1 + rand() % (W-1);
         y = 1 + rand() % (H-1);

      } while (playfield[y][x] != ' ');
      allGhosts[i].position.x = x;
      allGhosts[i].position.y = y;
      if(playfield[y][x]!='#'){
	  
      playfield[y][x] = 'Z';
}else
{
	 x = 1 + rand() % (W-3);
         y = 1 + rand() % (H-3);
}
   }


} 

void move_figures()
{
   
   playfield[play.position.y][play.position.x] = ' ';


   int nx = play.vx + play.position.x;
   int ny = play.vy + play.position.y;

  
   if (playfield[ny][nx] == '#')
   {
     
      play.vx = 0;
      play.vy = 0;
   }

  
  play.position.x += play.vx;
  play.position.y += play.vy;

  int g1,g2;
g1=(rand()%24)+1;
g2=(rand()%39)+1;
   
   if (playfield[ny][nx] == '$')
   { printf("\a");
      play.gold++;
   if(playfield[g1][g2]!='#'){
   
      playfield[g1][g2]='$';
   }
   else
   {
   	g1=(rand()%24)+2;
g2=(rand()%38)+2;
   }}
  
if (playfield[ny][nx] == 'Z')
{printf("\a");
play.lives--;
if(playfield[g1][g2]!='#'){

	playfield[rand()%29][rand()%59]='Z';}
	else
	{
			g1=(rand()%26)+2;
g2=(rand()%49)+2;
	}
}

   playfield[play.position.y][play.position.x] = '@';
   if( play.gold==5)
   {system("cls");
   
   }


}



void show_playfield()
{
   for (int i = 0; i < H; i++)
   {
      for (int j = 0; j < W; j++)
      {
         printf("%c", playfield[i][j]);
      }
      printf("\n");
       
   }
printf("Score: %d\n", play.gold);
   printf("Lives: %d\n", play.lives);
  
}
//FOR LEVEL 2
char playfield1[H][W] =
{
   { "############################################################" },
   { "#                                                #         #" },
   { "#                                                #         #" },
   { "#                         ########################         #" },
   { "###############           #                                #" },
   { "#             #           #                                #" },
   { "#             #           #                                #" },
   { "#             #           #                                #" },
   { "#             #           #                                #" },
   { "#             #           #                                #" },
   { "#             #           #        #############           #" },
   { "#             #           #                    #           #" },
   { "#             #           #                    #           #" },
   { "#             #           #                    #           #" },
   { "#                         #                    #           #" },
   { "#                         #                    #           #" },
   { "#######                   #                    #           #" },
   { "#     #                   #                    #           #" },
   { "#     #                   #                    #           #" },
   { "#     #                   #                    #           #" },
   { "#     #############       #                    #           #" },
   { "#                                              #           #" },
   { "#                                              #           #" },
   { "#                                              #           #" },
   { "############################################################" }
}; 
void initialize1()
{ int g11,g22;
g11=(rand()%23)+1;
g22=(rand()%38)+1;
if(playfield1[g11][g22]!='#'){
playfield1[g11][g22]='$';//The player have to collect the gold coins
}
else
{
	g11=(rand()%22)+1;
g22=(rand()%38)+1;
}
for (int i = 0; i < H; i++)
   {
      for (int j = 0; j < W; j++)
      {
         if (playfield1[i][j]==' ')
            playfield1[i][j] = ' ';
    
      }
   }

   // 2. initialize all ghosts
   for (int i = 0; i < NR_GHOSTS; i++)
   {
      allGhosts[i].vx = 0;
      allGhosts[i].vy = 0;
      allGhosts[i].chasing = true;

      // try to find a (x,y) coordinate randomly where a food piece is
      int x,y;
      do
      {
         x = 1 + rand() % (W-1);
         y = 1 + rand() % (H-1);

      } while (playfield1[y][x] != ' ');
      allGhosts[i].position.x = x;
      allGhosts[i].position.y = y;
      if(playfield1[y][x]!='#'){
      playfield1[y][x] = 'Z';}
      else
      {
      	 x = 1 + rand() % (W-4);
         y = 1 + rand() % (H-6);

	  }

   }


} // initialize




void move_figures1()
{ 
   
   playfield1[play.position.y][play.position.x] = ' ';


   int nx = play.vx + play.position.x;
   int ny = play.vy + play.position.y;

  
   if (playfield1[ny][nx] == '#')
   {
     
      play.vx = 0;
      play.vy = 0;
   }

  
  play.position.x += play.vx;
  play.position.y += play.vy;

int g1,g2,z1,z2;
g1=(rand()%23)+1;
g2=(rand()%41)+1;
   if (playfield1[ny][nx] == '$')
   {printf("\a");
      play.gold++;if(playfield[g1][g2]!='#'){
      playfield1[g1][g2]='$';
   }
   else
   {
   	g1=(rand()%22)+1;
g2=(rand()%39)+1;
   }}
 
z1=(rand()%23)+1;
z2=(rand()%41)+1;
if (playfield1[ny][nx] == 'Z')
{printf("\a");
play.lives--;
if (playfield1[z1][z2] == '$'){

	playfield1[rand()%21][rand()%38]='Z';}
	else
	{
		z1=(rand()%22)+1;
z2=(rand()%39)+1;
	}
}

   playfield1[play.position.y][play.position.x] = '@';
   if( play.gold==8)
   {system("cls");
   
   }


}




void show_playfield1()
{
   for (int i = 0; i < H; i++)
   {
      for (int j = 0; j < W; j++)
      {
         printf("%c", playfield1[i][j]);
      }
      printf("\n");
       
   }
printf("Score: %d\n", play.gold);
   printf("Lives: %d\n", play.lives);
  
}

//FOE LEVEL 3

char playfield2[H][W] =
{
   { "############################################################" },
   { "#                                         #                #" },
   { "########################                  #                #" },
   { "#                      #       ############                #" },
   { "#      #######         #       #          #                #" },
   { "#      #     #         #       #          #                #" },
   { "#      #     #         #            #######                #" },
   { "#            #         #            #                      #" },
   { "##############         #  #####     #                      #" },
   { "#                      #  #   #     #     #########        #" },
   { "#                      #      #     #     #       #        #" },
   { "#                      ########     #     ####    #        #" },
   { "##########                          #             #        #" },
   { "#        #                  #       ###############        #" },
   { "#        #                  #                              #" },
   { "#        #                  #                              #" },
   { "#        #        ###########       ########################" },
   { "#        #        #                                        #" },
   { "#    #####        #                                        #" },
   { "#                 #                 ############           #" },
   { "#                 #                 #          #           #" },
   { "#                 #                 #          #           #" },
   { "###################                 ######     #           #" },
   { "#                                              #           #" },
   { "############################################################" }
}; 

void initialize2()
{int g11,g22;
g11=(rand()%21)+1;
g22=(rand()%39)+1;
if(playfield2[g11][g22]!='#'){

playfield2[g11][g22]='$';//The player have to collect the gold coins
}
else
{
	g11=(rand()%24)+1;
g22=(rand()%36)+1;
}
for (int i = 0; i < H; i++)
   {
      for (int j = 0; j < W; j++)
      {
         if (playfield2[i][j]==' ')
            playfield2[i][j] = ' ';
    
      }
   }

   // 2. initialize all ghosts
   for (int i = 0; i < NR_GHOSTS; i++)
   {
      allGhosts[i].vx = 0;
      allGhosts[i].vy = 0;
      allGhosts[i].chasing = true;

      // try to find a (x,y) coordinate randomly where a food piece is
      int x,y;
      do
      {
         x = 1 + rand() % (W-1);
         y = 1 + rand() % (H-1);

      } while (playfield2[y][x]!= ' ');
      allGhosts[i].position.x = x;
      allGhosts[i].position.y = y;
      if(  playfield2[y][x]!='#'){
	  
      playfield2[y][x] = 'Z';
}
else
{
	
         x = 1 + rand() % (W-7);
         y = 1 + rand() % (H-7);
}
   }


} // initialize




void move_figures2()
{
   
   playfield2[play.position.y][play.position.x] = ' ';


   int nx = play.vx + play.position.x;
   int ny = play.vy + play.position.y;

  
   if (playfield2[ny][nx] == '#')
   {
     
      play.vx = 0;
      play.vy = 0;
   }

  
  play.position.x += play.vx;
  play.position.y += play.vy;
int g1,g2,z1,z2;
g1=(rand()%21)+1;
g2=(rand()%41)+1;
  
   
   if (playfield2[ny][nx] == '$')
   {printf("\a");
      play.gold++;
      
      if(playfield[g1][g2]!='#'){
	  
      playfield2[g1][g2]='$';}
      else
      {
      	g1=(rand()%20)+1;
g2=(rand()%35)+1;
	  }
   }
   z1=rand()%22+1;
   z2=rand()%39+1;
if (playfield2[ny][nx] == 'Z')
{printf("\a");
play.lives--;
if(playfield2[z1][z2]!='#'){

	playfield2[z1][z2]='Z';}
	else
	{
		  
   z1=rand()%23+1;
   z2=rand()%38+1;
	}
}


   playfield2[play.position.y][play.position.x] = '@';
   if( play.gold==12)
   {system("cls");
   
   }


}





void show_playfield2()
{
   for (int i = 0; i < H; i++)
   {
      for (int j = 0; j < W; j++)
      {
         printf("%c", playfield2[i][j]);
      }
      printf("\n");
       
   }
printf("Score: %d\n", play.gold);
   printf("Lives: %d\n", play.lives);
  
}
char start(void)
{
char start; 
system("color 5");
printf("\t\t\t   ************************************************\n\t\t\t   **************THE ASCII CHARACTER GAME**********\n\t\t\t   ************************************************\n");  
printf("\t\t\t\t\t   Enter Your Name\n");
printf("\t\t\t\t\t        ");
gets(name);
printf("\n\t\t\t\t\t    INSTRUCTIONS\n\t\"@\" is the player moving constantly and it will be controlled by the arrow keys to move direction\n      The player must save it from the scattered zombies\"Z\"and must collect the gold\"$\"to move on to the next levels\n      \t\t\t\t For Level 1 you have to collect 5 coins.\n");
printf("\n\n\t\t\t\t       Press S to start the game\n\t\t\t\t\t\t   ");
scanf("%c",& start );
system("cls");
system("color 6");
return start;
}
char level1(char start)
{char next;
system("cls");
if(start=='S' || start=='s')
{
	hidecursor();
   initialize();

   while (1)
   {  
      user_input();
     move_figures();
    
      
    show_playfield();
    
       
    
    
      set_cursor_position(0,0);
      if(play.gold==5)
      {
        system("cls");
        break;
	  }
	  if(play.lives==0){
	  	system("cls");
        break;
}
   } system("color 5");
   if(play.gold==5){switch(play.lives) 
   {
   	case 3:score=score+3+play.gold;
   	break;
   	case 2:score=score+2+play.gold;
   	break;
   	case 1:score=score+1+play.gold;
   	break;
   }
   printf("\n\n\n\n\n\n\n\t\t**************************************Level completed**************************************\n");
    printf("\n\t\t\t      *****************************SCORE*****************************\n\n\t\t\t\t\t\t\t   ");
    puts(name);
    printf("\t\t\t\t\t\t\t    %d",score);
   printf("\n\n\n\t\t\t\t\t         Press S to start the game\n\t\t\t\t\t\t\t     ");
   fflush(stdin);
   scanf("%c",& next);
   return next;}
   else if(play.lives==0)
   {score=play.gold+score;
   		printf("\n\n\n\n\n\n\n\t\t***********************************GAME OVER***********************************" );
    printf("\n\n\n\t\t       *******************************SCORE*******************************\n\n\t\t\t\t\t\t       ");
    puts(name);
    printf("\t\t\t\t\t\t\t%d",score);
    printf("\n\n\t\t\t\t\t\tPress enter to exit");
    scanf("%c",& exit);
   }}

}
char level2(char next)
{char next1;

system("cls");
system("color 4");
if(next=='S' || next=='s')
{play.gold=0;
play.lives=2;
	hidecursor();
   initialize1();

   while (1)
   { 
      user_input();
      move_figures1();
      
      show_playfield1();
      //Sleep(50);
      set_cursor_position(0,0);
      
      if(play.gold==8)
      {
        system("cls");
        break;
	  }
	  if(play.lives==0){
	  	system("cls");
        break;
}
   } system("color 5");
   if(play.gold==8){ 
   switch(play.lives) 
   {
   	case 3:score=score+3+play.gold;
   	break;
   	case 2:score=score+2+play.gold;
   	break;
   	case 1:score=score+1+play.gold;
   	break;
   }
printf("\n\n\n\n\n\n\n\t\t**************************************Level completed**************************************\n");
    printf("\n\t\t\t      *****************************SCORE*****************************\n\n\t\t\t\t\t\t\t   ");
    puts(name);
    printf("\t\t\t\t\t\t\t   %d",score);
   printf("\n\n\n\t\t\t\t\t         Press S to start the game\n\t\t\t\t\t\t   ");
   fflush(stdin);
   scanf("%c",& next1);
   return next1;}
   else if(play.lives==0)
   { 
   		printf("\n\n\n\n\n\n\n\t\t***********************************GAME OVER***********************************" );
    printf("\n\n\n\t\t       *******************************SCORE*******************************\n\n\t\t\t\t\t\t       ");
    puts(name);
    printf("\t\t\t\t\t\t\t%d",score);
    printf("\n\n\t\t\t\t\t\tPress enter to exit");
    scanf("%c",& exit1);
   }

}}
void level3(char next1)
{
system("color 9");
system("cls");
if(next1=='S' || next1=='s')
{play.gold=0;
play.lives=2;
	hidecursor();
   initialize2();

   while (1)
   { 
      user_input();
      move_figures2();
      
      show_playfield2();
     
      set_cursor_position(0,0);
      
      if(play.gold==12)
      {
        system("cls");
        break;
	  }
	  if(play.lives==0){
	  	system("cls");
        break;
}
   } if(play.gold==12){system("color 9");
   switch(play.lives) 
   {
   	case 3:score=score+3+play.gold;
   	break;
   	case 2:score=score+2+play.gold;
   	break;
   	case 1:score=score+1+play.gold;
   	break;
   }
  printf("\n\n\n\n\n\n\n\t\t**************************************Level completed**************************************\n");
    printf("\n\t\t\t      *****************************SCORE*****************************\n\n\t\t\t\t\t\t\t   ");
    puts(name);
    printf("\t\t\t\t\t\t\t     %d",score);
printf("\n\n\t\t\t\t\t\tPress enter to exit");
    scanf("%c",& exit1);
  }
   else
   {
   score=play.gold+score;
   		printf("\n\n\n\n\n\n\n\t\t***********************************GAME OVER***********************************" );
    printf("\n\n\n\t\t       *******************************SCORE*******************************\n\n\t\t\t\t\t\t       ");
    puts(name);
    printf("\t\t\t\t\t\t\t%d",score);
    printf("\n\n\t\t\t\t\t\tPress enter to exit");
    scanf("%c",& exit1);
   }

}}

int main()
{char lvl1,lvl2,lvl3;
lvl1=start();
lvl2=level1(lvl1);
lvl3=level2(lvl2);
level3(lvl3);

}