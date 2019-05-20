#!/bin/bash

#expect -c 'spawn -noecho  root -l 
#           send ".L btemplate_latest.cpp\r"
#           send "banalysis()\r"
#           interact'

gnome-terminal -e -working-directory=../
expect -c 'spawn -noecho root -l
           send ".L ctemplate.cpp\r"
           send "canalysis()\r"
           interact'

#expect -c 'spawn -noecho  root -l 
#                    
#                    send ".L btemplate_latest.cpp\r"
#                    send "banalysis()\r"
#                    interact'


#
#gnome-terminal -e || xterm -e: open new terminal via shell script
#expect -c: command/program(?) that allows shell script to write and interact
#with a terminal interacting session. Here: ROOT's Cling interactive C++
# interpreter/compiler.


