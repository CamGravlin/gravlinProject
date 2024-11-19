# Prints the square of each number 0-19

# Without using a function

#for x in range(20):  # 0-19
#  sq = x**2
#  print(sq)

# Using a function

def sq(n):
  return n**2

for x in range(20):
  print(f"The square of {x} is {sq(x)}")
