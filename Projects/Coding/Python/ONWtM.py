# #? Program Name: ONWtM.py
# #? Game Name: One Night With the Mathens!
# #? Game Bio: FNAF styled game ran on a CLI
# #? Creater Name: James Carlile
# #? Start Date: 08/11/2023 @ 10:54 PM

import time
from random import random
import math

# Base placement for enemies
todd_base_placement = -1
steven_base_placement = 0

# The two enemies
todd_placement = todd_base_placement
steven_placement = steven_base_placement

# Economy
battery_percentage = 100
game_time = 0

# Continuation condition
is_alive = True

# Door states
left_door_open = True
right_door_open = True

# Game explanations for player
intro = "\n\"Hey hey, welcome aboard to the Mathens Family! We're so happy to have you on our team. \n Now, being that it's your first night, there are some things I need to let you in on...\"\n"
tape = "\n\"Keep in mind:\n-You are working for 10 hours tonight, so when 10 hours have past, your shift is over.\n-Keep an eye on your battery, if it runs out, the place goes dark. That won't be good for anybody.\n-If, by any chance, Todd and/or Steve get to rooms 7 or 8, be sure to close your door; they get weird at night\"\n"

# Change game difficulty
while True:

    try:
        difficulty = int(input("\nHow hard do you want this game?\n\n(1) Easy\n(2) Standard\n(3) Hard\n\n> "))
    except:
        print("\n[Please input a number 1-3 based on the options provided]\n")
        time.sleep(1)
        continue
    
    if difficulty > 3 or difficulty < 1:
        print("\n[Please input a number 1-3 based on the options provided]\n")
        time.sleep(1)
        continue
        
    print("\n\n------------------------------------------------------------------------------------------------------------------------------------------------------------------")
    break

# #TODO: Have game difficulty affect time speed
#Determine how fast time passes per turn
time_speed = 1

# Determine the base battery cost dependent on the difficulty
if difficulty == 1:
    battery_cost = 1
    
elif difficulty == 2:
    battery_cost = 2.5
    
elif difficulty == 3:
    battery_cost = 5
    
# Introduce the game
print(intro + tape)
time.sleep(5)

# Game loop
while is_alive:

    print("\n\n------------------------------------------------------------------------------------------------------------------------------------------------------------------")

    # End game if power goes out
    if battery_percentage < 1:
        print("\n\n\nYOU RAN OUT OF POWER\n\n\nTODD AND STEVEN KILLED YOU\n\n\nGAME OVER\n\n\n")
        time.sleep(2)
    
    
    # Determine movement RNG based on difficulty
    def does_move():
        
        prob = random()
        
        if (difficulty == 1 and prob <= 0.4) or (difficulty == 2 and prob <= 0.6) or (difficulty == 3 and prob <= 0.8):
            return True
        else:
            return False
        
            
    def does_leave():
        
        prob = random()
        
        if (difficulty == 1 and prob <= 0.4) or (difficulty == 2 and prob <= 0.6) or (difficulty == 3 and prob <= 0.8):
            return False
        else:
            return True        
        
    def does_attack():
        
        prob = random()
        
        if (difficulty == 1 and prob <= 0.4) or (difficulty == 2 and prob <= 0.6) or (difficulty == 3 and prob <= 0.8):
            return True
        else:
            return False
    
  
    # Play loop
    if game_time < 10:
        
        while True:
            
            print("\n\n------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n")
            
            # Check door status for messages
            if right_door_open:
                right_message = "Close"
            else:
                right_message = "Open"
            if left_door_open:
                left_message = "Close"
            else:
                left_message = "Open"              
            
            # Print information
            print("\nTime: ", {game_time}, "\nBattery: ", {battery_percentage}, "\n")
            
            # Make sure player input is an integer and on the list
            try:
                player_choice = int(input(f"\nWould you like to:\n(1) Check map\n(2) {left_message} the left door\n(3) {right_message} the right door\n(4) Replay the tape\n(5) Continue\n\n> "))
            except:
                print("\n[Please input a number 1-5 based on the options provided]\n")
                continue
            if player_choice > 5 or player_choice < 1:
                print("\n[Please input a number 1-5 based on the options provided]\n")
                continue
                        
            if player_choice == 1:
                
                if todd_placement == todd_base_placement:
                    print("\nTodd has not moved from the stage\n")
                elif todd_placement == 7:
                    print("\nWARNING: TODD IS OUTSIDE YOUR OFFICE IN ROOM #7!\n")
                else:
                    print(f"\nTodd is in room #{todd_placement}\n")
                 
                if steven_placement == steven_base_placement:
                    print("\nSteven has not moved from the stage\n")   
                elif steven_placement == 8:
                    print("\nWARNING: STEVEN IS OUTSIDE YOUR OFFICE IN ROOM #8!\n")
                else:
                    print(f"\nSteven is in room #{steven_placement}\n")
                
                
                print (f"DB:  {does_move()}")
                time.sleep(3)
                        
            if player_choice == 2:
                left_door_open = not left_door_open
                        
            if player_choice == 3:
                right_door_open = not right_door_open           
                        
            # Play the explanation tape
            if player_choice == 4:
                print(tape)
                time.sleep(3)            
            
            # Break this iteration and continue on to the next hour
            if player_choice == 5:
                break
    
            # Todd movement
            if todd_placement != 7 and does_move():
                todd_placement += 2
            elif (todd_placement == 7 and not does_attack()) and does_leave():
                todd_placement == todd_base_placement
            elif (todd_placement == 7 and does_attack()) and (left_door_open == True):
                print("\n\n\nTODD KILLED YOU\n\n\nGAME OVER\n\n\n")
                time.sleep(1)
                is_alive = False
                break

            # Steven movement
            if steven_placement != 8 and does_move():
                todd_placement += 2
            elif (steven_placement == 8 and not does_attack()) and does_leave():
                steven_placement == steven_base_placement
            elif (steven_placement == 7 and does_attack()) and (right_door_open == True):
                print("\n\n\nSTEVEN KILLED YOU\n\n\nGAME OVER\n\n\n")
                time.sleep(1)
                is_alive = False
                break

            if left_door_open == False:
                battery_cost += 5
            if right_door_open == False:
                battery_cost += 5
            
        # Take away resources
        game_time += 1
        battery_percentage -= battery_cost
    
    elif game_time > 9:
        print("\n\n\nITS BEEN 10 HOURS!\n\n\nYOU WIN, WOOPIEEEEEEE\n\n\n")
        time.sleep(2)
        break
    
    else:
        print("\n\n\nERROR: ESCAPED GAME LOOP\n\n\n")
        break
                