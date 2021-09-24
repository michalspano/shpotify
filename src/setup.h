/* 
Michal Spano
Shpotify Add-ons
GitHub: https://github.com/michalspano
*/

// Header file for setup.c

// Include libs
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// Set up function prototypes
int parseInput(char const *PATH);

// Define macros
#define OK_STATUS "[    OK    ]"
#define FILE_ERROR "Error: Make sure '.shpotify.cfg' file exists.\n"

// Define constant size of secrets
#define SIZE 32
