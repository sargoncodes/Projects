# Program Name: Lab7.py
# Course: IT1114/Section W04
# Student Name: James Carlile
# Assignment Number: Lab7
# Due Date: 03/19/ 2023
# Purpose: Update worker class to calculate pay

#Create Worker class
class Worker:
    #Define constructor and add attributes needed to be stored
    def __init__(self):
        self.e_number = 0
        self.o_number = 0
        self.name = ''
        self.bdate = 0
        self.hours = 0
        self.o_hours = 0
        self.salary = 0
        self.o_salary = 0
        self.pay = 0

    #Define get_employee_number() to return the employee's recorded number
    def get_employee_number(self):
        return self.e_number
    
    #Define set_employee_number() to change the employee's recorded number
    def set_employee_number(self, x):
        self.e_number = x

    #Define get_office_number() to return the employee's recorded office number
    def get_office_number(self):
        return self.o_number
    
    #Define set_office_number() to change the employee's recorded office number
    def set_office_number(self, x):
        if x in range(101,501):
            self.o_number = x
    
    #Define get_name() to return the employee's full name
    def get_name(self):
        return self.name

    #Define set_name() to change the employee's full name
    def set_name(self, x):
        self.name = x

    #Define get_birthdate() to return the employee's birthdate
    def get_birthdate(self, d, m, y):
        self.bdate = d, m, y
        return self.bdate

    #Define set_birthdate() to change the employee's birthdate
    def set_birthdate(self, d, m, y):
        if d in range(1, 31) and m in range(1, 12):
            self.bdate = d, m, y
            return True
        else:
            return False

    #Define get_hours_worked() to return the amount of recorded hours the employee worked
    def get_hours_worked(self):
        return self.hours

    #Define add_hours() to add to the amount of recorded hours the employee worked
    def add_hours(self, x):
        if x > 9:
            self.hours += 9
            self.o_hours += (x-9)
        elif x <= 9:
            self.hours += 9

    #Define get_hours_overtime() to return the amount of recorded hours the employee worked
    def get_hours_overtime(self):
        return self.o_hours
    
    #Define get_hourly_salary() to return the worker's hourly salary
    def get_hourly_salary(self):
        return self.salary
    
    #Define set_hourly_salary() to change the worker's hourly salary
    def set_hourly_salary(self, x):
        if x < 0:
            return False
        else:
            self.salary = x
            
    #Define get_overtime_salary() to return the worker's overtime salary
    def get_overtime_salary(self):
        return self.o_salary
    
    #Define set_overtime_salary() to change the worker's overtime salary
    def set_overtime_salary(self, x):
        if x < 0:
            return False
        else:
            self.o_salary = x
            
    #Define get_pay() to calculate and return the workers total pay
    def get_pay(self):
        self.pay = (self.hours * self.salary) + (self.o_hours * self.o_salary)
        return self.pay
