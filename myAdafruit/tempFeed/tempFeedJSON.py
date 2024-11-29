import json

file_path = 'feed_data_JSON.csv'

with open(file_path, 'r') as file:
  data = json.load(file)

temperatures = []

for entry in data:
  temperature = float(entry["value"])
  temperatures.append(temperature)

minimum_temp = min(temperatures)
maximum_temp = max(temperatures)
average_temp = sum(temperatures) /len(temperatures)

print("Temperature Report")
print(f"Minimum Temperature: {minimum_temp}")
print(f"Maximum Temperature: {maximum_temp}")
print(f"Average Temperature: {average_temp:.2f}")
