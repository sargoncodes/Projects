# Program Name: Lab12.py
# Course: IT1114/Section W04
# Student Name: James Carlile
# Assignment Number: Lab12
# Due Date: 04/30/ 2023
# Purpose: Calculates the average grade of each section
# realpython.com, w3schools.com, python.org


# open grades.txt
with open("grades.txt", "r") as f:
    # makes dictionary to keep track of scores and counts for each section
    totals = {"1": [0, 0], "2": [0, 0], "3": [0, 0], "4": [0, 0], "5": [0, 0]}
    # read each line of grades.txt
    for line in f:
        number, section, grade = line.strip().split("\t")
        # determine the grade
        grade = 100 if grade == "A" else 89 if grade == "B" else 79 if grade == "C" else 74 if grade == "D" else 69
        totals[section][0] += grade
        totals[section][1] += 1
    # calculate average scores then print them
    for section in totals:
        score, count = totals[section]
        score = score / count
        print(f"Section {section}: {score}")
