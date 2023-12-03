# Program Name: Lab3.py
# Course: IT1114/Section W04
# Student Name: James Carlile
# Assignment Number: Lab3
# Due Date: 02/05/ 2023
# Purpose: This will allow a user to calculate the total monthly sales for their department
# Resources: time

#imports
import time

#Uses rest() as an alias for time.sleep(1)
def rest():
    time.sleep(1)

#Creates variables for later use
employees = 0
sales = 0

#Creates function to calculate manager bonus
def bonus_calc(x,y):
    if x > y:
        z = 0.05
    elif x < y:
        z = 0.02
    bonus = x * z
    return bonus

#Introduces user to the purpose of the program and defines the sells goal
print("\nWelcome to the Sales Calculator!\n\n\n")
goal = float(
    input("What is the sales goal of the month?\n$")
    )
rest()

#Main loop
while True:
    #Determines if loop continues
    cont = input("\nWould you like to add a person?(Y/N)\n")
    rest()
    if cont.upper() == "Y":
        pass
    elif cont.upper() == "N":
        break
    else:
        print(f'\nUnkown input: "{cont}"\nPlease answer with either "Y" or "y" for "yes" or answer with "N" or "n" for "no"\n')
        rest()
        continue
  
    #Defines employee name adds to employee amount
    person = input("\nWho is the salesperson?\n")
    employees += 1
    rest()
    
    #Defines sells for each of the 4 weeks
    for week in range(4):
        wsales = float(
            input(f"\nHow much money in sells did {person} make in week {week + 1}?\n$")
            )
        sales = sales + wsales
        rest()


#Prints results
print(
    f"\n\n\nThe results are as follows:\nNumber of employees: {employees}\nSales goal: ${goal}\nTotal sales: ${sales}\nManager Bonus: ${bonus_calc(sales,goal)}"
    )
