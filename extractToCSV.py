import json
import csv

# Function to flatten the nested dictionaries
def flatten_json(y):
    out = {}

    def flatten(x, name=''):
        if isinstance(x, dict):
            for a in x:
                flatten(x[a], name + a + '_')
        elif isinstance(x, list):
            i = 0
            for a in x:
                flatten(a, name + str(i) + '_')
                i += 1
        else:
            out[name[:-1]] = x

    flatten(y)
    return out

path = './json/P01_2024-03-15_AMD'

# Load the JSON file
with open(path + '.json', 'r') as json_file:
    data = json.load(json_file)

# Flatten each entry in the data
flat_data = [flatten_json(entry) for entry in data]

# Write the flattened data to a CSV file
keys = flat_data[0].keys()
with open(path + '.csv', 'w', newline='') as output_file:
    dict_writer = csv.DictWriter(output_file, keys)
    dict_writer.writeheader()
    dict_writer.writerows(flat_data)