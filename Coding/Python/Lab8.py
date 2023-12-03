# Program Name: Lab8.py
# Course: IT1114/Section W04
# Student Name: James Carlile
# Assignment Number: Lab8
# Due Date: 03/26/ 2023
# Purpose: This program will combine two integer arrays into one array and remove any duplicate values
# Resources: NumPy.org

#Imports
from numpy import random
import numpy as np

#Defines N with user input and ensures N is an intiger between 0 and 500, otherwise the user is informed the response is invalid and is prompted again until answer is correct
while True:
    try:
        N = int(input('\nChoose a positive number between 0 and 500 for array magic!\n'))
        if  N not in range(1, 501):
            print('\nInvalid response\n')
            continue
    except:
        print('\nInvalid Response\n')
        continue
    break

#Creates 2 1D NumPy arrays with N random intigers from 0 to 500 and combines them
ar1 = random.randint(500, size=(N))
ar2 = random.randint(500, size=(N))
ar3 = np.append(ar1, ar2)

#Uses NumPy's "unique" function to ensure no duplicates remain
ar3 = np.unique(ar3)

#Prints the final, cleaned array to the user
print(f"\n\n\nFinal array:\n\n{ar3}\n\n\n")