import random
str_pass = input ("Enter Your guess: ")

if (len(str_pass) != 4) :
    print("Your guess is not 4 digits")
else :
    pass_word = str(random.randint(0, 9)) + str(random.randint(0, 9)) + str(random.randint(0, 9)) + str(random.randint(0, 9))

    if (int(str_pass) == int(pass_word)) :
        print("Your guess is correct")
        print(f"Computer's guess is {pass_word}")
    else :
        print("Your guess is incorrect")
        print(f"Computer's guess is {pass_word}")