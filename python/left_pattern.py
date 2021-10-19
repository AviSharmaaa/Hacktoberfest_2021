# In this program i have to create a Pyramid same like Super Mario Brothers using hash(#).
# Mario must ascend right-aligned pyramid of blocks just like this.
'''
                #
               ##
              ###
             ####
            #####
'''

n = int(input("n: ")) # taking user input

# If the user doesn’t, input a positive integer greater than 1, inclusive, when prompted, 
# the program should re-prompt the user until they provide appropriate input.
while (n < 1):
    n = int(input("n: "))

# printing the right-aligned pattern.
for i in range(n):
    print(((n - i - 1) * " ") + ((i + 1) * "#"))
'''
I/P = Height: 4
O/P:
   #
  ##
 ###
####

I/P = Height: 1
O/P:
#

I/P:
Height: -1
Height: 0
Height: 8
O/P:
       #
      ##
     ###
    ####
   #####
  ######
 #######
########

'''

# Mohammad Modassir Iqbal
