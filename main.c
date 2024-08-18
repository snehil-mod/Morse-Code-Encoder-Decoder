#include <stdio.h>
#include <string.h>
#include <ctype.h>

//To input multiple words, use slash instead of 'space' to get complete output

const char * morseCode[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
};

void textToMorse(const char *text) {
    for (int i = 0; text[i] != '\0'; i++) {
        char c = toupper(text[i]); 
        if (isalpha(c)) {
            printf("%s ", morseCode[c - 'A']);
        } else if (c == ' ') {
            printf(" / "); 
        } else {
            printf("?"); //unknown
        }
    }
    printf("\n");
}

void morseToText(const char * morse)
{
    char * token = strtok((char *)morse, " /"); 
    while (token != NULL) {
        for (int i = 0; i < 26; i++) {
            if (strcmp(token, morseCode[i]) == 0) {
                printf("%c", 'A' + i);
                break;
            }
        }
        token = strtok(NULL, " /");
    }
    printf("\n");
}

int main()
{
    char input[100];
    int choice;
    printf("Choose an option: \n");
    printf("1) Encode text into Morse code\n");
    printf("2) Decode Morse code into text\n");
    scanf("%d", &choice);
    printf("Enter your input: ");
    scanf("%s", input); 

    switch (choice) {
        case 1:
            textToMorse(input);
            break;
        case 2:
            morseToText(input);
            break;
        default:
            printf("Invalid Choice!\n");
    }
    return 0;
}