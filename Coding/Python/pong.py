import pygame
import random

# choose_directionize Pygame
pygame.init()

# Setup FPS
clock = pygame.time.Clock()
FPS = 60

# Define gamestate variables
wait = True
running = True

# Keep score
left_score = 0
right_score = 0

# Create window object
class Window():
    color = ("black")
    w = 800
    h = 400
window = Window()

# Create text object
class Text():
    def __init__(self, surface, location):
        self.location = location
        self.surface = surface
    fg = ("black")
    bg = ("white")
    size = 50
    font = pygame.font.SysFont('Arial', size)
pause = Text(Text.font.render('Click space to start', True, Text.fg, Text.bg), (window.w // 4, window.h // 2))

# Create paddle object
class Paddle():
    def __init__(self, x, y):
        self.x = x
        self.y = y
    
    buffer = 10
    w = 15
    h = 150
    speed = 5
    color = ("white")
    
lPaddle = Paddle(Paddle.buffer, Paddle.buffer)
rPaddle = Paddle(window.w - (Paddle.buffer + Paddle.w), Paddle.buffer)

# Create ball object
class Ball():
    def __init__(self, x, y):
        self.p = (x,y)
        
    r = 10
    speed = 3
    color = ("white")
    choose_direction = True
    go_right = True
    go_down = True

ball = Ball(window.w // 2, window.h // 2)

# Display window
screen = pygame.display.set_mode((window.w, window.h))
pygame.display.set_caption('Pong')

# Check if window is closed
def check_event():

    global running
    global wait
    
    for event in pygame.event.get(): 
        if event.type == pygame.QUIT: 
            running = False
        
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_SPACE:
                wait = not wait
    return False

# Paddle controls
def check_keys():
    
    keys = pygame.key.get_pressed()
    if keys[pygame.K_w] and (lPaddle.y > Paddle.buffer):
        lPaddle.y -= Paddle.speed
    if keys[pygame.K_UP] and (rPaddle.y > Paddle.buffer):
        rPaddle.y -= Paddle.speed
    if keys[pygame.K_s] and (lPaddle.y < ((window.h - Paddle.h) - Paddle.buffer)):
        lPaddle.y += Paddle.speed
    if keys[pygame.K_DOWN] and (rPaddle.y < ((window.h - Paddle.h) - Paddle.buffer)):
        rPaddle.y += Paddle.speed

while running:
    # Defined above
    check_event()
    
    # Set FPS
    clock.tick(FPS)
    
    # Set draw order
    screen.fill(window.color)
    
    # Create score object
    score = Text(Text.font.render(f"{left_score} {right_score}", True, ("white")), (window.w // 2 - Text.size // 2, Text.size))
        
    # Draw objects
    screen.blit(score.surface, score.location)
    pygame.draw.rect(screen, Paddle.color, pygame.Rect(lPaddle.x, lPaddle.y, lPaddle.w, lPaddle.h))
    pygame.draw.rect(screen, Paddle.color, pygame.Rect(rPaddle.x, rPaddle.y, rPaddle.w, rPaddle.h))
    pygame.draw.line(screen, ("white"), (window.w // 2, 0), (window.w // 2, window.h))
    pygame.draw.circle(screen, ball.color, ball.p, ball.r)

    # Handle gamestates
    if not wait:
        check_keys()

        # Hacky BS required to change tuple values
        # Start ball position updates
        pList = list(ball.p)

        if ball.choose_direction: # Choose a random ball direction on first start
            moe = random.randint(0,1)
            if moe:
                ball.go_right = True
            elif not moe:
                ball.go_right = False
            ball.choose_direction = False

        elif not ball.choose_direction:
            
            if pList[0] == (lPaddle.x + lPaddle.w):
                if (pList[1] >= lPaddle.y and pList[1] <= (lPaddle.y + lPaddle.h)):
                    ball.go_right = True
            elif pList[0] == rPaddle.x:
                if (pList[1] >= rPaddle.y and pList[1] <= (rPaddle.y + rPaddle.h)):
                    ball.go_right = False
            

            elif ((pList[0] >= window.w) or (pList[0] <= 0)):
                if pList[0] >= window.w:
                    left_score += 1
                elif pList[0] <= 0:
                    right_score += 1
                del ball
                ball = Ball(window.w // 2, window.h // 2)
                print(f"\nLeft: {left_score} | Right: {right_score}\n")
                continue

            if ((pList[1] >= window.h) or (pList[1] <= 0)):
                ball.go_down = not ball.go_down

        if ball.go_right:
            pList[0] += ball.speed
        elif not ball.go_right:
            pList[0] -= ball.speed

        if ball.go_down:
            pList[1] += ball.speed
        elif not ball.go_down:
            pList[1] -= ball.speed


        ball.p = tuple(pList)
        # End ball position updates
    else:
        screen.blit(pause.surface, pause.location)

    # Update display
    pygame.display.flip()
    
    # Dont ask
    del score

# Clean exit
pygame.quit()