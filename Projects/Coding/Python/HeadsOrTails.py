import random
import time

number = random.randint(1,2)

if number == 1:
    answer = "HEADS"
elif number == 2:
    answer = "TAILS"

guess = input("\nHeads or tails?\n")
usrGuess = guess.upper()

if usrGuess == answer:
    print("Winner\n")
    time.sleep(2)
    quit()
elif usrGuess != answer:
    print("Loser\n")
    time.sleep(2)
    quit()