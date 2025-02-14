import pygame
import random

bg_color = ("white")
colors = [("red"), ("blue"), ("green"), ("yellow"), ("orange")]
rect_color = (0, 0, 0)
screen_width, screen_height = 600, 400
go_right,go_down = True,True
buffer = 5
rect_x, rect_y = buffer,buffer
rect_width, rect_height = 90, 60

speed = 2
  
screen = pygame.display.set_mode((screen_width, screen_height)) 
clock = pygame.time.Clock()

pygame.display.set_caption('Plants vs Zombies') 

running = True

def change_color():
    global bg_color
    old_color = bg_color
    while True:
        index = random.randint(0,(len(colors) - 1))
        bg_color = colors[index]
        if bg_color != old_color:
            break

while running:
    clock.tick(60)
    screen.fill(bg_color)
    
    pygame.draw.rect(screen, rect_color, pygame.Rect(rect_x, rect_y, rect_width, rect_height))
    
    if ((rect_x + rect_width) >= (screen_width - buffer)):
        go_right = False
        change_color()
    elif (rect_x <= buffer):
        go_right = True
        change_color()
        
    if ((rect_y + rect_height) >= (screen_height - buffer) ):
        go_down = False
        change_color()
    elif (rect_y <= buffer):
        go_down = True
        change_color()
    
    if (go_right):
        rect_x += speed
    else:
        rect_x -= speed
        
    if (go_down):
        rect_y += speed
    else:
        rect_y -= speed
    
    # keys = pygame.key.get_pressed()  

    # if keys[pygame.K_LEFT]:
    #     rect_x -= speed

    # if keys[pygame.K_RIGHT]:
    #     rect_x += speed

    # if keys[pygame.K_UP]:
    #     rect_y -= speed

    # if keys[pygame.K_DOWN]:
    #     rect_y += speed
    
    pygame.display.flip()
    
    print(f"{rect_x} | {rect_y}\n{go_right} | {go_down}\n{screen_width} | {screen_height}\n==============")
    
    for event in pygame.event.get(): 
          
        if event.type == pygame.QUIT: 
            running = False