import commandLibrary as cl

command = input("root@PyTerminal~# ")

parsed_command = command.split()

cl.convert(parsed_command[0], parsed_command[1])