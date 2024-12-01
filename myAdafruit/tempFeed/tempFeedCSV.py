file_path = 'feed_data_test.csv'

with open(file_path, 'r') as file:
  lines = file.readlines()

header = lines[0].strip().split(',')
temperature_index = header.index("value")

temperatures = []

for line in lines[1:]:
  values = line.strip().split(',')
  temperature = float(values[temperature_index])
  temperatures.append(temperature)

minimum_temp = min(temperatures)
maximum_temp = max(temperatures)
average_temp = sum(temperatures) /len(temperatures)

print("Temperature Report")
print(f"Minimum Temperature: {minimum_temp}")
print(f"Maximum Temperature: {maximum_temp}")
print(f"Average Temperature: {average_temp:.2f}")
