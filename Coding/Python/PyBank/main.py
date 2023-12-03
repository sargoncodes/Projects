
###TODO###
#Add method of checking if user information is already saved to info.txt
##########

#imports
import time

#introduction
print("Welcome to PyBank! Firstly, we have some quick questions, then our services are yours to use!\n")
time.sleep(1)

#getting user information
n = input("What is your full name?\n")
time.sleep(1)
a = input(f"Hello,{n} what is your age?\n")
time.sleep(1)
g = input("Aging well, I see. What is your gender?\n")

#parent class
class User():
    def __init__(self,name,age,gender):
        self.name = name
        self.age = age
        self.gender = gender
        
    def usr_info(self):
        print(
            f"""
            Name: {self.name}\n
            Age: {self.age}\n
            Gender: {self.gender}\n
            """)
        
#Child Class
class Bank(User):
    def __init__(self, name, age, gender):
        super().__init__(name, age, gender) #super() allows us to use the same variables defined in parent class without rewriting them
        self.balance = 0
    
    def deposit(self, amount):
        self.balance = self.balance + amount
        print(f"\nAccount balance updated: ${self.balance}\n")
        
    def withdrawl(self, amount):
        self.balance = self.balance - amount
        
        if self.balance < 0:
            print("\nTransaction cancelled: Insufficient funds\n")
            self.balance = self.balance + amount
        else:
            print(f"\nAccount balance updated: ${self.balance}\n")        
        
    def usr_balance(self):
        print(f"\nYour balance is: ${self.balance}\n")

user = Bank(n,a,g)
time.sleep(1)  
print(f"\nThank you for banking with us, {n}!\n")
time.sleep(1)

#main loop
while True:
    choice = int(input("What would you like to do?\n1. Deposit\n2. Withdrawl\n3. View Balance\n4. View Personal Information\n5. Finish\n"))
    if choice == 1:
        time.sleep(1)
        number = int(input("How much would you like to deposit?\n"))
        user.deposit(number)
        time.sleep(1)
    elif choice == 2:
        time.sleep(1)
        number = int(input("How much would you like to withdrawl?\n"))
        user.withdrawl(number)
        time.sleep(1)
    elif choice == 3:
        time.sleep(1)
        user.usr_balance()
        time.sleep(1)
    elif choice == 4:
        time.sleep(1)
        user.usr_info()
        time.sleep(1)
    elif choice == 5:
        time.sleep(1)
        print(f"\nThank you for banking with us, {n}, goodbye!")
        time.sleep(1)
        break
    else:
        time.sleep(1)
        "Sorry, your answer was not recognized, please enter a numeric value from the list:"
        time.sleep(1)
        continue

#Writing info to file
file = open('/home/fedoramain/Documents/Coding/Python/PyBank/info.txt', 'a')
data = ["Name:", str(user.name), "\n", "Age: ",str(user.age), "\n", "Gender: ", str(user.gender), "\n", "Balance: $", str(user.balance), "\n\n\n\n"]
file.writelines(data)
file.close()