/*************************************************************************************************************************

A simple program to print the count of dictionary palindrome.

A dictionary palindrome is a type of palindrome such that a word and it's reversed string also exist in the same file.

Example,                                                                                            
If the word "adam" exist in a file.txt and a word "mada" exist in the same file.txt, then the word adam is a dictionary 
palindrome.

The below given code will work on sorted and "newline-seperated" files with designation such a words starting with 'A' 
are followed by a line 'A', an arbitary BIGNUMBER [1 Million] is provided and can be increased for further use

***************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BIGNUMBER 1000000

struct word{
    char words[BIGNUMBER][50];
    int begin[58];
    int end[58];
    int character;
    int numPali[58];
}instance;

/*************************************************************************************************************************
 * This naive implementation works by getting all the string of a particular character, reversing the string and then
 * comparing the search string with all the strings starting with the letter.
**************************************************************************************************************************/


void palindromeCheck(void *parameter)
{
    struct word *instance = (struct word *)parameter;
    for (int i = instance->begin[instance->character]; i < instance->end[instance->character]; i++)
    {
        char *tempString = (char*)malloc(50);
        memcpy(tempString, instance->words[i], sizeof(instance->words[i]));
        if (strlen(tempString) != 1)
        {
            int n = strlen(tempString);
            for (int i = 0; i < n / 2; i++)
            {
                char tempVar = tempString[i];
                tempString[i] = tempString[n - i - 1];
                tempString[n - i - 1] = tempVar;
            }
        }
        // WE HAVE THE TEMP STRING!
        for(int j=instance->begin[tempString[0]-65];j<instance->end[tempString[0]-65];j++){
            if(strcmp(instance->words[j],tempString)==0){
                instance->numPali[instance->character]++;
            }
        }
    }
}

int main(){
    FILE *file = fopen("file", "r");
    for (int i = 0; i < BIGNUMBER; i++)
    {
        fscanf(file,"%s",instance.words[i]);
        if(strlen(instance.words[i])==1){
            instance.begin[(char)instance.words[i][0] - 65] = i+1;
        }
    }
    for(int i=0;i<57;i++){
        if(!(i>90-65 && i<97-65)){
            instance.end[i] = instance.begin[i+1] - 1;
        }
    }
    instance.end[57] = BIGNUMBER;
    for(int i=0;i<58;i++){
        instance.character = i;
        palindromeCheck(&instance);
    }

    int totalPalindrome = 0;
    for (int i = 0; i < 58; i++)
    {
        if (!(i > 90 - 65 && i < 97 - 65))
        {
            printf("%c => %d\n", i+65, instance.numPali[i]);
            totalPalindrome += instance.numPali[i];
        }
    }
    printf("totalPalindrome is: %d\n", totalPalindrome);

    return 0;
}
