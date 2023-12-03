# Program Name: Exam2.py
# Course: IT1114/Section W04
# Student Name: James Carlile
# Assignment Number: Exam2
# Due Date: 04/02/ 2023
# Purpose: Calculate the volume of a water tower
# Resources: pythonguides.com for naming conventions

#1. Imports
import time #For rest
import math #For pi

#2. Functions
def rest(): #Shortens time.sleep(1) down to rest()
    time.sleep(1)

def half_sphere_volume(r):
    volume = 4/3 * pi * r**3 #Stores the sphere volume formula as volume
    return volume * 0.5 #Returns half of the volume since the sphere is only half of a sphere

def cylinder_volume(r, h):
    volume = pi * r**2 * h #Stores the cylinder volume formula as volume
    return volume #Returns the volume

#3. Variables
pi = math.pi 
sphere_radius = float(input(f"\nWhat is the radius of the semi-sphere at the top of the water tower?\n")) #Gets the input for the sphere radius as a float in case the number is a decimal
rest()
cylinder_radius = float(input(f"\nWhat is the radius of the cylinder base of the water tower?\n"))
rest()
cylinder_height = float(input(f"\nWhat is the height of the cylinder base of the water tower?\n"))
rest()
volume = half_sphere_volume(sphere_radius) + cylinder_volume(cylinder_radius, cylinder_height) #Combines both functions filled with the previously user-defined variables to calculate the volume of the water tower

#4. Response
print(f"\nThe volume of your water tower is {volume}.\n") #Uses an f string to output the volume