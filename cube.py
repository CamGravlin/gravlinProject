# Prints the cube of every odd number and prints every even number as-is 0-19


def cb(n):
  return n**2

for x in range(20):   # 0-19
  if x % 2 == 1:
    print(f"{cb(x)}")
  else:
    print(f"{x}")
