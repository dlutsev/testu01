import re
import csv

input_file = "in.txt"
output_file = "out.csv"

test_name_pattern = re.compile(r"(.+?) test:")
pvalue_pattern = re.compile(r"p-value of test\s*:\s*([0-9]\.\d+(?:e[-+]?\d+)?)")

with open(input_file, 'r') as infile, open(output_file, 'w', newline='') as csvfile:
    csv_writer = csv.writer(csvfile)
    csv_writer.writerow(["Test Name", "Min p-value"]) 

    current_test_name = None 
    min_p_value = None        
    for line in infile:
        test_name_match = test_name_pattern.search(line)
        if test_name_match:
            if current_test_name and min_p_value is not None:
                csv_writer.writerow([current_test_name, min_p_value])
            current_test_name = test_name_match.group(1)
            min_p_value = None
        pvalue_match = pvalue_pattern.search(line)
        if pvalue_match:
            p_value = float(pvalue_match.group(1))
            if min_p_value is None or p_value < min_p_value:
                min_p_value = p_value
    if current_test_name and min_p_value is not None:
        csv_writer.writerow([current_test_name, min_p_value])

print(f"Результаты с минимальными p-value извлечены в {output_file}")
