#include<stdio.h>
int whowins(int board[9])
{
int wins[8][3]={{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
int i;
    	for(i = 0; i < 8; ++i) 
    	{
        		if(board[wins[i][0]] != 0 &&board[wins[i][0]] == board[wins[i][1]] &&board[wins[i][1]] == board[wins[i][2]])
           		 return board[wins[i][0]];
    	}
   	 return 0;
}


int minmax(int board[9], int player) 
{   
int move,score,i,thisScore;
int winner = whowins(board);
    	if(winner != 0)
    	{
        		return winner*player;
    	}
   	 move = -1;
    	score = -10;
    	for(i = 1; i < 10; ++i) 
    	{
        		if(board[i-1] == 0) 
        		{
            		board[i-1] = player;
            		thisScore = -minmax(board, player*-1);
            		if(thisScore > score)
            		{	
                			score = thisScore;
                			move = i-1;
            		}
            		board[i-1] = 0;
       		 }
    	}
    	if(move == -1) 
    	{
       		 return 0;
    	}
   	 return score;
}
void  computerchance(int board[9]) 
{
  	int move=-1;
    	int score = -10;
    	int i,tempScore;
    	for(i = 1; i < 10; ++i) 
    	{
        		if(board[i-1] == 0) 
        		{
            		board[i-1] = 1;
           			tempScore = -minmax(board, -1);
            		if(tempScore > score) 
            		{
                			score = tempScore;
                			move = i-1;
            		}
            		board[i-1]=0;
        		}
    	}
    	board[move] = 1;
}
void  playerchance(int board[9]) 
{
    	int move;
    	do{
        		again:
            	printf("\nPlease select a move between 1 to 9: ");
            	scanf("%d", &move);
            	if(board[move-1] != 0) 
            	{
                		printf("Its filled..Select again");
                		goto  again;
            	}
        
            	printf("\n");
    	} while (move >= 10 || move < 0 && board[move-1] == 0);
    	board[move-1] = -1;
}
char xo(int i)
{
 switch(i) {
       		 case -1:
            		return 'X';
        		case 0:
            		return ' ';
        		case 1:
            		return 'O';
    		}
}
void  print(int b[9])
{
    	printf("  %c  |  %c  |  %c \n",xo(b[0]),xo(b[1]),xo(b[2]));
    	printf("-----+-----+-----\n");
    	printf("  %c  |  %c  |  %c \n",xo(b[3]),xo(b[4]),xo(b[5]));
    	printf("-----+-----+-----\n");
    	printf("  %c  |  %c  |  %c \n",xo(b[6]),xo(b[7]),xo(b[8]));
}
int main()
{
   	 printf("Welcome to the game\n");
    	printf("I bet you cannot win me\n");
    	int playermove,turn;
    	int board[9] = {0,0,0,0,0,0,0,0,0};
    	printf("You are 'X'and I am'O'\n");
    	printf("You want to play (1)st or (2)nd:\n");
    	scanf("%d",&playermove);
    	printf("\n");
    	printf("The board before filling:\n");
    	for(turn = 0; turn < 9 && whowins(board) == 0; turn++)
 {
        		if((turn+playermove) % 2 == 0)
            		computerchance(board);
        		else 
        		{
           			 print(board);
            	 	playerchance(board);
        		}
    	}
    	switch(whowins(board)) 
{
        	case 0:
            	printf("It is a draw\n");
            	break;
        	case 1:
            	print(board);
            	printf("You lose.\n");
            	break;
        	case -1:
            	printf("You win. Impossible\n");
            	break;
    	}
}
    


