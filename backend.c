#include <stdio.h>
#include <stdlib.h>

//backend of sdas

void install(char *pkg) {
    int returnCode = system("sudo emerge --ask %s", pkg); //hope this shi works!!!!!

    if (returnCode == 0) {
        printf("Installed! You may now close this window!"); //i think it opens a window atleast i hope it does!
    
    }

    else {
        printf("Install failed! Returned code:", returnCode); //hope this work frfr
    } 
}

void unstall(char *pkg) {
    int returnCode = system("sudo emerge --deselect --ask %s", pkg);

    if (returnCode == 0) {
        printf("Deselected! Going to part 2!"); 

        int returnCode = system("sudo emerge --ask --depclean %s", pkg);

        if (returnCode == 0) {
            printf("Uninstalled! You may now close this window!"); //i think it opens a window atleast i hope it does!
    
            }

        else {
            printf("Uninstalled failed! Returned code:", returnCode); //hope this work frfr
        } 
    }

    else {
        printf("Depclean failed! Returned code:", returnCode); //hope this work frfrfr
    } 
}

void cleanup() {
    //stuff 
}

void update() {
    //stuff
}