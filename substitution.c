#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool validated(string key);

int main(int argc, string argv[])
{
    string key = argv[1];
    //make sure exactly 2 arguments on command line
    if(argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    else if(validated(key) != 0)
    {
        return 1;
    }
    //get plaintext from user
    string ptext = get_string("Enter your plaintext: ");
    //print out the cipher text
    printf("Secret code: ");

    for(int i = 0, n = strlen(ptext); i < n; i++)
    {
        char c = ptext[i];

        if(isupper(c))
        {
            int u = c - 'A';
            printf("%c", toupper(key[u]));
        }
        else if(islower(c))
        {
            int j = c - 'a';
            printf("%c", tolower(key[j]));
        }

        else
        {
            printf("%c", c);
        }
    }
    printf("\n");
}

bool validated(string key)
{
    // if the length of the string is not exactly 26, give error
    if(strlen(key) != 26)
    {
        printf("Key must contain 26 letters\n");
        return 1;
    }
    //make an array of all 0's
    int count[26] = {0};
    //check to make sure each character in string is in the alphabet and if not give error
    for(int i = 0, n = strlen(key); i < n; i++)
    {
        if(!isalpha(key[i]))
        {
            printf("Your key must only contain alphabetical characters\n");
            return 1;
        }
        count[toupper(key[i]) - 'A']++;
    }
    //check for duplicate letters
    for(int i = 0; i < 26; i++)
    {
        if(count[i] != 1)
        {
            printf("No duplicate letters allowed\n");
            return 1;
        }
    }
    return 0;
}