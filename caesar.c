#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // check to make sure theres exactly 2 arguments in command line
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // check to make sure it as an non negative int
    for(int i = 0; i < strlen(argv[1]); i++)
    {
        if(argv[1][i] < '0' || argv[1][i] > '9')
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    // turn the string thats a number into that number
    int key = atoi(argv[1]);
    // get the users text they want deciphered
    string phrase = get_string("Please enter your text: ");
    // we need a place to print our message or else it will print the letters only
    printf("Secret Message: ");
    //check if each character is in the alphabet and if it is add the key to each letter
    for(int i = 0, n = strlen(phrase); i < n; i++)
    {
        char c = phrase[i];
        if(isalpha(c) && isupper(c))
        {
            printf("%c", (c - 65 + key) % 26 + 65);
        }
        else if(isalpha(c) && islower(c))
        {
            printf("%c", (c - 97 + key) % 26 + 97);
        }
        else
        {
            printf("%c", c);
        }
    }
    printf("\n");
}