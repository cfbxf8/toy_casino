
#include <stdio.h>
#include <time.h>

// Function Prototypes
void display_menu();
int throw_dice();
int even_odd(int x, int option);
int lucky_seven(int x, int option);
int guess_number(int x, int guess);

//Main body of code
int main()
{
//Randomizes based on time as seed
srand(time (NULL));

//declare local variables
int selection, choice, diesum, bet;
int money= 100;

//Call function to display menu and then prompt user to enter an option and get their option
display_menu();
printf("Please select an option:");
scanf("%d", &selection);

//While statement to make program loop unless 4 is entered or money is no longer positive
while ((selection !=4) && (money > 0) )
{	
//Switch to find selection
	switch (selection)
	{	//Even/Odd selection
		case 1:
		{
		printf("\n\nTake a guess (1)Even (2)Odd:");
		scanf("%d", &choice);
		printf("\n\nHow much you want to bet:$ ");
		scanf("%d", &bet);
		diesum= throw_dice(); //Calls throw_dice function to simulate dice throw
		int eo= even_odd(diesum,choice); //Calls and gets return value from even_odd function
		if (eo==1) 
			money+= 2*bet; //Case in which the user wins, add 2 times bet to money total 
		if (eo==0) 
			money-= bet; //Case in which the user loses, subtract bet from money total
//Start again
		display_menu();
		printf("Please select an option:");
		scanf("%d", &selection);
//Break case 1		
		break;
		}
//Lucky seven selection		
		case 2:
		{
		printf("\n\n1) Lucky 7 (2) above 7 (3) below 7 Enter your game choice: ");
		scanf("%d", &choice);
		printf("\n\nHow much you want to bet:$ ");
		scanf("%d", &bet);
		diesum= throw_dice(); //Calls throw_dice function to simulate dice throw
		int seven= lucky_seven(diesum, choice); //Calls and gets return value from lucky_seven function
		if (choice==1) //If choice equals lucky 7
		{
			if (seven==1)
				money+= 7*bet; //Case in which the user wins, add 7 times bet to money total
			if (seven==0)
				money-= bet; //Case in which the user loses, subtract bet from money total
		}
		if ((choice==2) || (choice==3)) //If choice is greater or lower than 7
		{
			if (seven==1)
				money+= 2*bet; //Case in which the user wins, add 2 times bet to money total
			if (seven==0)
				money-= bet; //Case in which the user loses, subtract bet from money total
		}
//Start again		
		display_menu();
		printf("Please select an option:");
		scanf("%d", &selection);
//Break case 2		
		break;
		}
//Guess the number selection		
		case 3:
		{
		printf("\n\nHow much you want to bet:$ ");
		scanf("%d", &bet);
		printf("\n\nGuess a number: ");
		scanf("%d", &choice);		
		diesum= throw_dice(); //Calls throw_dice function to simulate dice throw
		int guess= guess_number(diesum, choice); //Calls and gets return value from guess_number function
		if (guess==1)
			money+= 5*bet; //Case in which the user wins, add 5 times bet to money total
		if (guess==0)
			money-= bet; //Case in which the user loses, subtract bet from money total
//Start again		
		display_menu();
		printf("Please select an option:");
		scanf("%d", &selection);
					
//Break case 3			
		break;
		}
//Check for invalid choice
		default:
		{
		printf("Invalid choice");
//Start Again
		display_menu();
		printf("Please select an option:");
		scanf("%d", &selection);
//Break default case		
		break;
		}
	}	
}
//If money is below 1, print this
	if (money <=0)
		printf("\n\nYou lost all the money in gambling");
//Prints total of all gambling
printf("\n\nYour total money after gambling is %d", money);

return 0;
}

//Function to display menu
void display_menu()
{
printf("\n\nWelcome to the casino\n");
printf("Games you can play 1)Even/Odd (2) Lucky seven (3) Guess the number (4)Exit\n");
}

//Function to simulate dice throw
int throw_dice()
{ //Get random numbers from 1 to 6, sum them and return it
int die1 = 1 + ( rand() % 6 ); 
int die2 = 1 + ( rand() % 6 );
int diesum = die1 + die2;
return diesum;
}

//Function to play even or odd game and return 1 or 0 for win or loss
int even_odd(int x, int option)
{
	int check= x % 2; //Check to see if even or odd
	if (option==1) //If picked even
	{
		if (check==0) //Win
		{
		printf("You win your guess is correct the dices sum is %d", x);
		return 1;
		}
		if (check==1) //Lose
		{
		printf("You lost your guess is incorrect the dices sum is %d", x);
		return 0;
		}		
	}
	if (option==2) //If picked odd
	{
		if (check==1) //Win
		{
		printf("You win your guess is correct the dices sum is %d", x);
		return 1;
		}
		if (check==0) //Lose
		{
		printf("You lost your guess is incorrect the dices sum is %d", x);
		return 0;
		}		
	}
}

//Function to play lucky_seven game and return 1 or 0 for win or loss
int lucky_seven(int x, int option) 
{
	if (option==1) //Lucky seven selection and return win or loss
	{
		if ((x>=2) && (x<=6))
		{
		printf("You lost your guess is incorrect the dices sum is %d", x);
		return 0;
		}
		if ((x>=8) && (x<=12))
		{
		printf("You lost your guess is incorrect the dices sum is %d", x);
		return 0;
		}
		if (x==7)
		{
		printf("You win your guess is correct the dices sum is %d", x);
		return 1;
		}
	}
	if (option==2) //Above seven selection and return win or loss
	{
		if ((x>=2) && (x<=6))
		{
		printf("You lost your guess is incorrect the dices sum is %d", x);
		return 0;
		}
		if ((x>=8) && (x<=12))
		{
		printf("You win your guess is correct the dices sum is %d", x);
		return 1;
		}
		if (x==7)
		{
		printf("You lost your guess is incorrect the dices sum is %d", x);
		return 0;
		}
	}
	if (option==3) //Below seven selection and return win or loss
	{
		if ((x>=2) && (x<=6))
		{
		printf("You win your guess is correct the dices sum is %d", x);
		return 1;
		}
		if ((x>=8) && (x<=12))
		{
		printf("You lost your guess is incorrect the dices sum is %d", x);
		return 0;
		}
		if (x==7)
		{
		printf("You lost your guess is incorrect the dices sum is %d", x);
		return 0;
		}
	}	
}

//Function to play guess_number game and return 1 or 0 for win or loss
int guess_number(int x, int guess)
{
	if (x==guess) //Win
	{
	printf("You win your guess is correct the dices sum is %d", x);
	return 1;
	}
	if (x != guess) //Loss
	{
	printf("You lost your guess is incorrect the dices sum is %d", x);
	return 0;
	}	
}