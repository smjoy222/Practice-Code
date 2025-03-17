
"""num1 = float(input("Enter the first number: "))
num2 = float(input("Enter the second number: "))


sum_result = num1 + num2
difference_result = num1 - num2
product_result = num1 * num2
quotient_result = num1 / num2
remainder_result = num1 % num2
print("Sum:", sum_result)
print("Difference:", difference_result)
print("Product:", product_result)
print("Quotient:", quotient_result)
print("Remainder:", remainder_result)"""

"""

import math

def calculate_circle_area(radius):
    return math.pi * radius ** 2

def calculate_rectangle_area(length, width):
    return length * width

def calculate_triangle_area(base, height):
    return 0.5 * base * height


print("Choose a shape to calculate the area:")
print("1. Circle\n2. Rectangle\n3. Triangle")

choice = int(input("Enter your choice (1/2/3): "))

if choice == 1:
    radius = float(input("Enter the radius of the circle: "))
    area = calculate_circle_area(radius)
    print("Area of the circle:", area)
elif choice == 2:
    length = float(input("Enter the length of the rectangle: "))
    width = float(input("Enter the width of the rectangle: "))
    area = calculate_rectangle_area(length, width)
    print("Area of the rectangle:", int(area))
elif choice == 3:
    base = float(input("Enter the base length of the triangle: "))
    height = float(input("Enter the height of the triangle: "))
    area = calculate_triangle_area(base, height)
    print("Area of the triangle:", area)
else:
    print("Invalid choice.")
    
"""

"""
car = {'Brand' : 'Audi','Model': 'q7'}
car['type']='sports'
print(car.keys())
print(car)
print(car.items()) 

"""

