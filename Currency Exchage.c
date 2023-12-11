/* Program which displays a menu with 3 options, the first allows the user to convert euro to US Dollars,
    the second allows the user to convert dollars to euro and the last allows the user to quit the program.
    If the user wants to convert money they are prompted for 3 values in either euro or US Dollars
    depending on what they are converting. Those 3 values are displayed next to their equivalent in
    the currency they want to exchange to and the average of those 3 values in the other currence
    is displayed. the exchange rate is 1 euro is quivalent to 1.19 US Dollars and 1 US Dollar is 
    0.84 euros.
  
*/

//header files
#include <stdio.h>

//symbolic names
#define SIZE 3

//function signatures
float change_to_Euro(float[]); //function which  allows user to convert from US Dollars to Euro
float change_to_Dollar(float[]); //function which allows user to convert from Euro to US Dollars

int main()
{
    int option; //used to take input for what option the user wants to choose
    float original_amount[SIZE]; //used to take input for the 3 amounts of money the user wants to convert
    int i; //index variable
    float average; //variable used to store average of exchanged amounts of money
    
    do
    {
        //menu
        printf("choose one of the following options \n");
        printf("1.Convert Euro to US Dollars \n");
        printf("2.Convert US Dollars to Euro \n");
        printf("3.Exit program \n");
        //take input for the option the user wants to use
        scanf("%d", &option);
        flushall();
        
        //if user chooses option number 1
        if(option == 1)
        {
            //taking input from user for amount of money in euro
            printf("Enter three amounts of money in Euro \n");
            //storing the input in array
            for(i = 0; i < SIZE; i++)
            {
                scanf("%f", &original_amount[i]);
                flushall();
            }
            //printing out the equivalent of the numbers entered in dollars 
            average = change_to_Dollar(original_amount);
            //printing out the average in exchanged currency
            printf("\n the average of the values entered if converted to dollar is %.2f \n\n", average);
        }
        
        //if user chooses option number 2
        if(option == 2)
        {
            //taking input from user for amount of money in Dollar
            printf("Enter three amounts of money in Dollar\n");
            //storing the input in array
            for(i = 0; i < SIZE; i++)
            {
                scanf("%f", &original_amount[i]);
                flushall();
            }
            //printing out the equivalent of the numbers entered in euros 
            average = change_to_Euro(original_amount);
            //printing out the average in exchanged currency
            printf("\n the average of the values entered if converted to euro is %.2f \n\n", average);
        }
        
    }
    while(option !=3);
    printf("hit the enter key to quit \n");
    
    getchar();
    return 0;
}

// implementing the function change_to_Euro() which converts dollars to euro
float change_to_Euro(float dollar_amount[])
{
    int i;//index variable
    float euro_amount[SIZE] = {0.0};//array to store converted money
    float exchange = 0.84;//exchange rate
    float average1 = 0.0;//variable used to stora average
    
    for(i = 0; i < SIZE; i++)
    {
        euro_amount[i] = dollar_amount[i] * exchange;//exchanging the money
        printf("amount in dollars is %.2f, the equivalent of that in euros is %.2f \n", dollar_amount[i], euro_amount[i]);//printing out the numbers side by side
        average1 = average1 + euro_amount[i];//tallying the total
    }
    average1 = (float) average1 / SIZE;//storing average in average variable
    
    
    return average1;//returning average
}

//implementing the function change_to_Dollar() which converts euro to dollar
float change_to_Dollar(float euro_amount[])
{
    int i;//index variable
    float dollar_amount[SIZE] = {0.0};//array to store converted amounts
    float exchange2 = 1.19;//exchange rate
    float average2 = 0.0;//average stored in variable
    
    for(i = 0; i <SIZE; i++)
    {
        dollar_amount[i] = euro_amount[i] * exchange2;
        printf("amount in euro is %.2f, the equivalent of that in dollars is %.2f \n", euro_amount[i], dollar_amount[i]);
        average2 = average2 + dollar_amount[i];
    }
    average2 = (float) average2 / SIZE;
    
    
    return average2;
}