#!/usr/bin/expect
spawn ssh fzcsyglq@192.168.1.104
expect "*password*"
send "misakamikoto\r"
send "cd /home/fzcsyglq/Desktop/work"
send "./main"
send "exit"

