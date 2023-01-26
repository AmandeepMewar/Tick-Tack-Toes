#include <stdio.h>
#define N 3

void display(char (*arr)[N]){
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			printf("| %c ",arr[i][j]);
		}            
		printf("|\n");
	}
}

//this function checks if the grid selected by user is valid or not
//if valid then changes its value to appropriate character and returns 1.
//if not valid returns 0.
int check(char (*arr)[N], int r, int c, char v){
	if (arr[r][c] == '-'){
		arr[r][c] = v;
		return 1;
	}
	else{
		printf("Invalid input! Try again\n");
		return 0;
	}
}

//checks if player 'X' is able to manage any winning combination.
int checkWinPlayer1(char (*arr)[N]){
	
	//for row check
    if ((arr[0][0] == 'X' && arr[0][1] == 'X' && arr[0][2] == 'X') || (arr[1][0] == 'X' && arr[1][1] == 'X' && arr[1][2] == 'X') || (arr[2][0] == 'X' && arr[2][1] == 'X' && arr[2][2] == 'X')){
    	return 1;
	}
	//for column check	
	else if ((arr[0][0] == 'X' && arr[1][0] == 'X' && arr[2][0] == 'X') || (arr[0][1] == 'X' && arr[1][1] == 'X' && arr[2][1] == 'X') || (arr[0][2] == 'X' && arr[1][2] == 'X' && arr[2][2] == 'X')){
		return 1;
	}
	//for diagonal check
	else if ((arr[0][0] == 'X' && arr[1][1] == 'X' && arr[2][2] == 'X') || (arr[0][2] == 'X' && arr[1][1] == 'X' && arr[2][0] == 'X')){
		return 1;
	}
	return 0;
}

//Player 'X' turn - 
int player1Chance(char (*arr)[N], int *count){
	display(arr);
	int r,c;
	do{
	printf("\nPlayer 'X'!\nEnter row and column:");
	scanf("%d%d",&r,&c);
	
	}while(!check(arr,r,c,'X'));
	*count = *count + 1;
	
	return checkWinPlayer1(arr);
}

//checks if player 'O' is able to manage any winning combination.
int checkWinPlayer2(char (*arr)[N]){
    if ((arr[0][0] == 'O' && arr[0][1] == 'O' && arr[0][2] == 'O') || (arr[1][0] == 'O' && arr[1][1] == 'O' && arr[1][2] == 'O') || (arr[2][0] == 'O' && arr[2][1] == 'O' && arr[2][2] == 'O')){
    	return 1;
	}	
	else if ((arr[0][0] == 'O' && arr[1][0] == 'O' && arr[2][0] == 'O') || (arr[0][1] == 'O' && arr[1][1] == 'O' && arr[2][1] == 'O') || (arr[0][2] == 'O' && arr[0][2] == 'O' && arr[0][3] == 'O')){
		return 1;
	}
	else if ((arr[0][0] == 'O' && arr[1][1] == 'O' && arr[2][2] == 'O') || (arr[0][2] == 'O' && arr[1][1] == 'O' && arr[2][0] == 'O')){
		return 1;
	}
	return 0;
}

//Player 'O' turn - 
int player2Chance(char (*arr)[N],int *count){
	display(arr);
	int r,c;
	do{
	printf("\nPlayer 'O'!\nEnter row and column:");
	scanf("%d%d",&r,&c);
	
	}while(!check(arr,r,c,'O'));
	*count = *count + 1;
	
	return checkWinPlayer2(arr);
}

int main(){
	char letsPlay;
	
	do{ 
	    char arr[N][N];
		
		//initializing every value of arr[N][N] with '-' 
		for (int i = 0; i < N; i++){
		    for (int j = 0; j < N; j++){
			    arr[i][j] = '-';
		    }        
		}
		
		printf("GAME STARTS..\n\n");
		
		int a, b;
		int count = 0; 
		
		do{
		    a = player1Chance(arr,&count);
			
			//checks if player 'X' satisfies any winning condition.
			if (a == 1){
			    display(arr);
			    printf("YEEE! PLAYER 'X' WON!!! CONGRATULATIONS\n");
			    break;
	   	    }
		
		    //checks if all boxes are filled.
		    if (count == 9){
		    		//if no one manages to win.
                    display(arr);
					printf("OHHH! IT'S A DRAW\n");
					break;
			}
		
		    //checks if player 'O' satisfies any winning condition.
		    b = player2Chance(arr,&count);
		    if(b == 1){
			    display(arr);
			    printf("YEEE! PLAYER 'O' WON!!! CONGRATULATIONS\n");
			    break;
		    }
        }while(1);

	    printf("\nDo you want to play again (Y OR N) ?: ");
	    scanf(" %c", &letsPlay);    

	}while(letsPlay == 'Y');
	
    printf("\nGAME OVER!!\n");
    printf("\nTHANK YOU\n");
	return 0;
		
}