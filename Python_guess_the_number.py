import random

i = 0;
number = random.randint(1,9);
i= input("This is a random number guessing competition.\nEnter a random single digit number: ");
i =int(i);
if (i==number):print("You guessed correct number")
else :print("You guessed wrongly\nThe correct answer is ",number)
  
