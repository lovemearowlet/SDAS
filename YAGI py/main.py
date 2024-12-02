import os
import config.py#config file

def install(pkgin):#install
  if sucmd == 1 :#doas
    if ld == 1 :
      os.system("doas emerge -a", pkgin)
    if ld == 2 :
      os.system("doas pacman -Sy", pkgin)
  if sucmd == 2 :#sudo
      if ld == 1 :
      os.system("sudo emerge -a", pkgin)
    if ld == 2 :
      os.system("sudo pacman -Sy", pkgin)
def update(pkgup):#update
  if sucmd == 1 :#doas
    if ld == 1 :
      os.system("doas emerge -a --update", pkgup)
    if ld == 2 :
      os.system("doas pacman -Syu", pkgup)
  if sucmd == 2 :#sudo
      if ld == 1 :
      os.system("sudo emerge -a --update", pkgup)
    if ld == 2 :
      os.system("sudo pacman -Syu", pkgup)
