import random
import time


print("Welcome to the RNG Test! Let's see if you're lucky...")
time.sleep(2)

num = random.randrange(1,100)

if num == 1:
    print("You have been blessed by RNGesus, go buy a scratch off!")

elif num <= 10:
    print("You have very good luck!")

elif num <= 35:
    print("You are pretty lucky!")
    
elif num <= 85:
    print("You have moderate luck")
    
elif num <= 99:
    print("You're kinda unlucky")
    
elif num == 100:
    print("RNG hates you, stay away from online gambling")
    
time.sleep(10)