

# Files and Directories

Desktop = []

Downloads = []

Documents = [
    "Welcome"
]

Pictures = []

Music = []

Trash = []




def convert(command, target):
    
    if command == "ls":
        if isinstance(target, list):
            for file in target:
                print(file)
            
        else:
            print(f"\nERROR: {target} is not a directory\n")        
    
    elif command == "cd":
        return

# TODO   elif command == "mkdir":
# TODO       return
    
    elif command == "touch":
        return
    
    elif command == "cat":
        return
    
    elif command == "rm":
        return
    
# TODO    elif command == "rmdir":
# TODO        return
    
    elif command == "man":
        return
    
    else:
        return(f"\nERROR: {command} is an unknown or invalid command\n")
    



# Converts user input string to usable values
converted = {

    # Directories
    "Desktop": Desktop,
    "Downloads": Downloads,
    "Documents": Documents,
    "Pictures": Pictures,
    "Music": Music,
    "Trash": Trash
    
    # Files
    
}