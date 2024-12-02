#include <stdio.h>
#include <alloca.h>
#include <stdlib.h>
#include <string.h>

#include "config.h"

int __process_pkg(char *flags, char *pkg) {
    if(flags == NULL) {
        flags = "";
    }
    if(pkg == NULL) {
        pkg = "";
    }
    char *cmd = NULL;
    size_t cmd_size = (strlen(privilege_cmd) + strlen(pkg_mananger) + strlen(flags) + strlen(pkg) + 4) * sizeof(char);
    cmd = alloca(cmd_size + 1);
    snprintf(cmd, cmd_size, "%s %s %s %s", privilege_cmd, pkg_mananger, flags, pkg);
    return puts(cmd);
}

int updatesys() {//update sys
    if(!strncmp(pkg_mananger, "emerge", 6)) {
        __process_pkg("--update --deep --newuse @world", NULL);
    }
    if(!strncmp(pkg_mananger, "pacman", 6)) {
        __process_pkg("-Syu --noconfirm", NULL);
    }
    return 1;
}

int install(char *pkg) {//install
    if(!strncmp(pkg_mananger, "emerge", 6)) {
        __process_pkg(NULL, pkg);
    }
    if(!strncmp(pkg_mananger, "pacman", 6)) {
        __process_pkg("-S --noconfirm", pkg);
    }
    return 1;
}

int uninstall(char *pkg) {//uninstall
    if(!strncmp(pkg_mananger, "emerge", 6)) {
        __process_pkg("--deselect --depclean", pkg);
    }
    if(!strncmp(pkg_mananger, "pacman", 6)) {
        __process_pkg("-Rncs --noconfirm", pkg);
    }
    return 1;
}

int main() {
    updatesys();
    install("firefox");
    uninstall("chrome");
}
