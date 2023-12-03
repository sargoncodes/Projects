# Program Name: Lab4.py
# Course: IT1114/Section W04
# Student Name: James Carlile
# Assignment Number: Lab4
# Due Date: 02/12/ 2023
# Purpose: Allows a user to calculate the cost of a vacation
# Resources: Time, my roomate gave me tips on how to clean up my code a bit and helped me resolve the problem in mealCost

import time

#Makes shortcut for time.sleep(1)
def rest():
    time.sleep(1)

#Calculates the cost of the rooms when it's passed values    
def roomCost(n,r):
    tr_cost = n * r
    return tr_cost

#Calculates the cost of the meals when it's passed values
def mealCost(b,d):
    b *= 25
    d *= 75
    tm_cost = b + d
    tm_cost += (tm_cost * 0.15)
    return tm_cost

#Calculates the cost of the excursions when passed values
def excursionCost(a,b,c,d,p):
    te_cost = 0
    
    if a == True:
        te_cost += 50
    if b == True:
        te_cost += (25 * p)
    if c == True:
        te_cost += (17 * p)
    if d == True:
        te_cost += 200
    
    return te_cost

#Introduction
print("""\n\n\n
      Welcome to the resort cost calculator!
      \n\n\n""")
rest()

#Defines variables to later be values for pre-defined functions later
nights = int(input("\nTo get started off, how many nights will you be staying?\n"))
rest()
people = int(input("\nAwesome, and how many people will be in your party?\n"))
rest()
#Takes stringed response 1-4 and converts it to an integer value for later calculations
room = input("\nWe have four room options:\n1: Two Queen Beds\n2: One King Bed\n3: Queen Suite\n4: King Suit\nWhich would you like to choose?\n(please answer with 1,2,3, or 4)\n")
if room == "1":
    room = 375
elif room == "2":
    room = 350
elif room == "3":
    room = 525
elif room == "4":
    room = 475
else:
    print("\nInvalid answer, quitting...")
    rest()
    quit()
rest()

brunches = int(input("\nAlright, how many brunches would you like to order?\n"))
rest()
dinners = int(input("\nAnd how many dinners?\n"))
rest()

print("""\nNow we are onto our excursion list! Bare with us, this is almost over.
      \nWe have 4 excursions, you can choose as many as you would like:
      \n-Picnic\n-Snorkeling\n-Guided Hike\n-Boat Dinner""")
rest()
#Converts each stringed response into a boolean value for later calculations 
picnic = input("\nWould you like to go on the picnic?\n(y/n)\n")
if picnic.upper() == "Y":
    picnic = True
elif picnic.upper() == "N":
    picnic = False
snorkeling = input("\nWould you like to go snorkeling?\n(y/n)\n")
if snorkeling.upper() == "Y":
    snorkeling = True
elif snorkeling.upper() == "N":
    snorkeling = False
hike = input("\nWould you like to go hiking?\n(y/n)\n")
if hike.upper() == "Y":
    hike = True
elif hike.upper() == "N":
    hike = False
dinner = input("\nWould you like to go on the boat dinner?\n(y/n)\n")
if dinner.upper() == "Y":
    dinner = True
elif dinner.upper() == "N":
    dinner = False
rest()

#Calls the cost functions and provides the values, adds all all of the functions together as t_cost, and finally prints out the results of each function along with the total cost
t_cost = roomCost(nights, room) + mealCost(brunches, dinners) + excursionCost(picnic, snorkeling, hike, dinner, people)
print(f"""\n\nAlright! Your reciept is as follows:
      \nRoom Cost: ${roomCost(nights, room)}\nMeal Cost: ${mealCost(brunches, dinners)}\nExcursion Cost: ${excursionCost(picnic, snorkeling, hike, dinner, people)}\nTotal Cost: ${t_cost}
      """)