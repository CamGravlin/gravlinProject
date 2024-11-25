# Filename: sumLines.py
# Reads each line of a txt file and computes the sum, number of integers, and
# finds the average of all numbers

def compute_file_stats(filename):
  with open(filename, 'r', encoding='utf-8') as file:
    total_sum = 0
    count = 0

    for line in file:
      numbers = [int(num) for num in line.split()]
      total_sum += sum(numbers)
      count += len(numbers)

  average = total_sum / count if count > 0 else 0

  print(f"Total Sum: {total_sum}")
  print(f"Number of Integers: {count}")
  print(f"Average: {average:.2f}")

if __name__ == "__main__":
  input_file = "dataInput.txt"
  compute_file_stats(input_file)
