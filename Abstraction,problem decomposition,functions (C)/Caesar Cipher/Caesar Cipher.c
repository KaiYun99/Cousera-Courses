#include <stdio.h>
#include <string.h>  // want to encrypt words numbers , lower case , uppercase //
#include <ctype.h>
#include <stdlib.h>

int main()
{
    int shift;         // Shift left will have value of 0 , Shift right will have value of 1 //
    printf("Please choose a direction to encrypt (Enter 0 for Left shift and 1 for Right shift): ");
    scanf("%d", &shift);
    printf("\n");

    while ( shift != 0 && shift != 1 )
    {
        printf("Please select a valid direction (Enter 0 for Left shift and 1 for Right shift): ");
        scanf("%d", &shift);
        printf("\n");
    }

    printf("Enter the number to shift by: ");
    int shiftby;
    scanf("%d", &shiftby);
    while ( shiftby <= 0)
    {
        printf("Input a positive number to shift by: ");
        scanf("%d", &shiftby);
    }

    char OriginalText[100];
    char *p;
    printf("Enter text to encrypt: ");
    scanf("\n");
    //getchar();                                              // need to get char() or scanf("\n") to get rid of buffer) if use fgets
    fgets(OriginalText, sizeof(OriginalText), stdin);
    if (p=strchr(OriginalText, '\n')) *p='\0';

    int validtext = 0;
    while ( validtext  == 0 )
    {
        validtext = 1;
        for ( int i = 0 ; i < strlen(OriginalText) ; i++ )
        {
            if (  isalnum(OriginalText[i]) )
            {
                validtext = 1;
            }
            else
            {
                validtext = 0;
                break;
            }

        }
        if (validtext == 0)
        {
            printf("Enter text to encrypt: ");
            getchar();
            fgets(OriginalText, sizeof(OriginalText), stdin);
            if (p=strchr(OriginalText, '\n')) *p='\0';
        }

    }


    char *EncryptedText = malloc((strlen(OriginalText) + 1 ) * sizeof(char) );
    int shiftdigit;
    for ( int i = 0 ; i < strlen(OriginalText) ; i++ )
    {
        if ( shift == 0 )
        {
            if (isdigit(OriginalText[i]) != 0)
            {

                shiftdigit = 0;
                shiftdigit = shiftby %10;
                *(EncryptedText+i) = OriginalText[i] - shiftdigit;
                if ( EncryptedText[i] < '0' )
                {
                    EncryptedText[i] += 10;
                }
            }

            if ( isupper(OriginalText[i]) != 0)
            {
                EncryptedText[i] = OriginalText[i] - shiftby;
                if (EncryptedText[i] < 'A' )
                {
                    EncryptedText[i] += 26;
                }
            }
            if ( islower(OriginalText[i]) != 0 )
            {
                EncryptedText[i] = OriginalText[i] - shiftby;
                if (EncryptedText[i] < 'a' )
                {
                    EncryptedText[i] += 26;
                }
            }



        }
        if ( shift == 1)   //right shift //
        {
            if (isdigit(OriginalText[i]) != 0)
            {

                shiftdigit = 0;
                shiftdigit = shiftby %10;
                *(EncryptedText+i) = OriginalText[i] + shiftdigit;
                if ( EncryptedText[i] > '9' )
                {
                    EncryptedText[i] -= 10;
                }
            }

            if ( isupper(OriginalText[i]) != 0)
            {
                EncryptedText[i] = OriginalText[i] + shiftby;
                if (EncryptedText[i] > 'Z' )
                {
                    EncryptedText[i] -= 26;
                }
            }
            if ( islower(OriginalText[i]) != 0 )
            {
                EncryptedText[i] = OriginalText[i] + shiftby;
                if (EncryptedText[i] > 'z' )
                {
                    EncryptedText[i] -= 26;
                }
            }
        }
    }
    EncryptedText[strlen(OriginalText)] = '\0';
    printf("%s", EncryptedText);

    return 0;
}
