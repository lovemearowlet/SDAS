#include <stdio.h>
#include <stdlib.h>

#include "config.c"

int update(char **pkg) {//update
	if (dis == 0) {//gentoo
		if (sod == 0) {
			system("sudo emerge emerge --update --deep --newuse --ask @world");
		}
		if (sod == 1) {
			system("doas emerge emerge --update --deep --newuse --ask @world");
		}
	}
	if (dis == 1) {//arch
		if (sod == 0) {
			system("sudo pacman -Syu");
		}
		if (sod == 1) {
			system("doas pacman -Syu");
		}
	}
}

int install(char **pkg[]) {//install
	if (dis == 0) {//gentoo
		if (sod == 0) {
			system("sudo emerge -a %s", pkg);
		}
		if (sod == 1) {
			system("doas emerge -a %s", pkg);
		}
	}
	if (dis == 1) {//arch
		if (sod == 0) {
			system("sudo pacman -Sy %s", pkg);
		}
		if (sod == 1) {
			system("doas pacman -Sy %s", pkg);
		}
	}
}

int uninstall(char **pkg) {//uninstall
	if (dis == 0) {//gentoo
		if (sod == 0) {
			system("sudo emerge -a --deselect --depclean %s", pkg);
		}
		if (sod == 1) {
			system("doas emerge -a --deselect --depclean %s", pkg);
		}
	}
	if (dis == 1) {//arch
		if (sod == 0) {
			system("sudo pacman -R %s", pkg);
		}
		if (sod == 1) {
			system("doas pacman -R %s", pkg);
		}
	}
}
