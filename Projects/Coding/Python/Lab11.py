# Program Name: Lab11.py
# Course: IT1114/Section W04
# Student Name: James Carlile
# Assignment Number: Lab11
# Due Date: 04/23/ 2023
# Purpose: Creates and edits a text file
# Resources: realpython.com, w3schools.com, python.org

#Creates empty txt file
def create_file():
    open('users.txt', 'x')

#Appends user to text file, uses with statement to close file when finished
def add_user(u):
    with open('users.txt', 'a') as f:
        f.write(u + '\n')

#Reads file, loops through lines to find o argument to replace it with n argument, bringing file pointer back to top, and 
def update_user(o, n):
    with open('users.txt', 'r+') as f:
        lines = f.readlines()
        f.seek(0)
        for line in lines:
            if o in line:
                line = line.replace(o, n)
            f.write(line)

#Same logic as update_user(), but checks if the u argument is in lines, if not, then it writes that line to the file, finally uses truncate to make sure file is at correct length
def remove_user(u):
    with open('users.txt', 'r+') as f:
        lines = f.readlines()
        f.seek(0)
        for line in lines:
            if u not in line:
                f.write(line)
        f.truncate()