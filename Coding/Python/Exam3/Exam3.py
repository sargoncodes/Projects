# Program Name: Exam3.py
# Course: IT1114/Section W04
# Student Name: James Carlile
# Assignment Number: Exam3
# Due Date: 05/07/ 2023
# Purpose: Calculates Olympic diver results
# Resources: python.org, w3schools.com

# Print headers first so they're only printed once
print("Name\t|\tDD\t|\tScore")

# Open and read input.txt as f
with open("input.txt", "r") as f:

    # Read each line of the file
    for line in f:
        # Define the data in each line, using tab as what separates the types
        name, dd, *scores = line.strip().split("\t")
       
        # Turn each DD to a float
        dd = float(dd)
        
        # Turn scores to floats
        scores = [float(score) for score in scores]
        
        # Remove the highest and lowest scores
        scores.remove(max(scores))
        scores.remove(min(scores))
        
        # Calculate score
        score = (sum(scores) / len(scores)) * dd
       
        # Print the diver's results
        print(f"{name}\t|\t{dd}\t|\t{score}")