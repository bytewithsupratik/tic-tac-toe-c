#include<stdio.h>
#include<stdlib.h>

int checkwinner (char grid[3][3])
{
    int i,j;
    for ( i = 0; i < 3; i++)
    {
        if ((grid[i][0]==grid[i][1]&&grid[i][1]==grid[i][2])&&(grid[i][0]=='X'||grid[i][0]=='O'))// check rows
        return 1;
    }   
        for (j = 0; j < 3; j++)
        {
        if ((grid[0][j]==grid[1][j]&&grid[1][j]==grid[2][j])&&(grid[0][j]=='X'||grid[0][j]=='O'))  // check column
        return 1;
        }
        
        // diagonal
        if ((grid[0][0]==grid[1][1] && grid[1][1]==grid[2][2]) && (grid[0][0]=='X' || grid[0][0]=='O'))// check diagonal
        return 1;
        if ((grid[0][2]==grid[1][1] && grid[1][1]==grid[2][0]) && (grid[0][2]=='X' || grid[0][2]=='O'))// check diagonal
        return 1;
    
        // IF NO WINNER
        return 0;
    
    }

int main()
{
    printf("TIC TAC TOE\n");
    char grid[3][3];
    int m; 
    int row,col,i,j;
    
    // initializing grid

    for(i = 0; i < 3; i++)
    {
        for ( j = 0; j <3; j++)
        {
            grid[i][j]= '_';
        }
    }

    // CHOICE FOR MODE

        int ch;
        printf("PRESS 1 TO PLAY PLAYER VS PLAYER");
        printf("\nPRESS 2 TO PLAY PLAYER VS AI (COMMING SOON!)\n");
        scanf("%d",&ch);

        if(ch==1)
        {
            
            char player1='X';
            char player2='O';
            char currentplayer = player1; // set starting player

            printf("\n %c WILL START THE GAME\n",currentplayer);

                        // Display board

                        printf("\t   1|2|3\n");
                        for(i = 0; i < 3; i++)
                        {
                        printf("\t%d |", i + 1);
                        for ( j = 0; j <3; j++)
                        {
                            printf("%c ", grid[i][j]);
                        }
                        printf("\n");
                        }
                        
                        // move counter 

                        for (m=1; m<=9;m++)
                        {
                            printf("ENTER YOUR MOVE %c between 1-3 PLAYER X (X-Y)\n",currentplayer);
                            scanf("%d%d",&row,&col);  

                                // checking range of input 
                            
                                if (row>=1 && row<=3   && col >=1 && col<=3)
                                {
                                    row--; col--;
                                        if (grid[row][col]=='_')
                                        {
                                            grid[row][col]= currentplayer;

                                            // UPDATED GRID
            
                                        system("clear || cls");
                                        printf("\t   1|2|3\n");
                                            for(i = 0; i < 3; i++)
                                            {
                                            printf("\t%d |", i + 1);
                                            for ( j = 0; j <3; j++)
                                            {
                                                printf("%c ", grid[i][j]);
                                            }
                                            printf("\n");
                                            }
                                            if (checkwinner(grid))
                                              {
                                              printf("\nPLAYER %c WINS!\n", currentplayer);
                                              break; // exit the move loop
                                              }
                                        }
                                        else
                                        {
                                            printf("\nOOPS TOO LATE FOR THE SPACE\n");
                                            m--;
                                            continue;
                                        }
                                }            
                                else
                                {
                                    printf("\nPLEASE ENTER VALID POSITION...! Try again\n");
                                    m--;
                                    continue;
                                }  
                                if (currentplayer==player1){
                                        currentplayer=player2;}
                                    else{
                                    currentplayer=player1;}
                        if(m==9)
                        {
                            printf("ITS A DRAW !!!!");
                        } 
                    }
                            
         }      
    return 0;
}