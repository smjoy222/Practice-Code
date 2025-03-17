##largest_number = max(4, 17, 9, 32)
##print(largest_number) 


#using loop
numbers = [5, 12, 8, 23, 1]
largest_number = numbers[0]  # Initialize with the first element
for num in numbers:
    if num > largest_number:
        largest_number = num
print(largest_number)  # Output: 23


