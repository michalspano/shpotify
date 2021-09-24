/* 
Michal Spano
Shpotify Add-ons
GitHub: https://github.com/michalspano
*/

// This Extensions enables to set up the Spotify client directly from command line!

// Include local header
#include "setup.h"

int main(void) {
    // Define default file path
    char const *cfg_path = ".shpotify.cfg";

    // Check for valid file path
    if (access(cfg_path, F_OK) == 0) {
        // Display macros
        printf("%s  File exists\n", OK_STATUS);
    }
    else {
        // Quit thread
        fprintf(stderr, FILE_ERROR);
        return 1;
    }

    // Return int type
    return parseInput(cfg_path);
}

int parseInput(char const *PATH) {

    // Open path
    FILE *config_file = fopen(PATH, "w");

    // Receive secrets
    char *clientID = malloc(sizeof(char) * SIZE);
    char *clientSecret = malloc(sizeof(char) * SIZE);

    // Check for valid memory use
    if (clientID == NULL || clientID == NULL) {
        fprintf(stderr, FILE_ERROR);
        return 2;
    }

    printf("Client ID: ");
    scanf("%s", clientID);

    printf("Client Secret: ");
    scanf("%s", clientSecret);

    // Format strings
    char tempBuf1[SIZE * 2];
    snprintf(tempBuf1, sizeof(tempBuf1), "CLIENT_ID=\"%s\"\n", clientID);

    char tempBuf2[SIZE * 2];
    snprintf(tempBuf2, sizeof(tempBuf2), "CLIENT_SECRET=\"%s\"\n", clientSecret);

    // Write to text file
    fputs(tempBuf1, config_file);
    fputs(tempBuf2, config_file);

    // Free memory
    free(clientID);
    free(clientSecret);

    fclose(config_file);
    return 0;
}