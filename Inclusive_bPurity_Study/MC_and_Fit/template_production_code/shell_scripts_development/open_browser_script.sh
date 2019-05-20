
#!/bin/bash

xterm -e expect -c 'spawn -noecho  root -l 
           send "TBrowser a;\r"
           interact'
#xterm -e: open new terminal via shell script
#expect -c: command/program(?) that allows shell script to write and interact
#with a terminal interacting session.Here: ROOT's Cling interactive C++
# interpreter/compiler.

