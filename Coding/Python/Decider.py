import random
import time

List1 = []
List2 = []

while True:
    usrOptions = input('\nInput options you want me to choose from. Say "1" when ready to move on or "0" to quit.\n')
     
    if usrOptions != '1' and usrOptions != '0':
        List1.append(usrOptions)


    elif usrOptions == '1' and List1 != []:
        print("\nDeciding...\n")
        time.sleep(3)
        break
    
    elif usrOptions == '1' and List1 == []:
        print("\nI don't have any options to choose from, please input options\n")
        time.sleep(2)
        continue
    
    elif usrOptions == '0':
        quit()

while True:
    decision = random.choice(List1)
    
    try:
        for i in List2:
            if i != decision:
                break
            if i == decision:
                List1.pop(decision)
                continue
    except:
        print("\nYou have exhausted all of your options. Quitting...")
        time.sleep(2)
        quit()
  
        
    List2.append(decision)
    
    restart = input(f'\nI have chosen {decision}. Reply with "1" for me to choose again or "0" to quit\n')
    
    if restart == '1':
        continue
    
    if restart == '0':
        print("\nI hope my decision helped, goodbye!\n")
        time.sleep(2)
        quit()
