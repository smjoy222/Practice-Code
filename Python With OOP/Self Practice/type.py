'''
x = 40
x = "joy"
print(x)
print(type(x))
'''
#Normal Input
"""
name = input("what is your name:")
print(name)
"""
#input().split()  for more input
"""
name = input("what is your name:") .split()
print(name)
"""
#tyoe casting otherwhise all will be string
"""
value1 = input("Enter the 1st number:")
value2= input("Enter the 2nd number:")
#add = value1 + value2 need type casting
add = int(value1)+int(value2)
print(add)
"""
#if elif else
"""
grade=40 
if grade>= 90:
    print("A")
elif grade>=80:print('B+')
elif grade>=70:print('B')
else:
    print("Fail")    
"""
#while
"""
product=3
while product <=50:
    product=product*3
print(product)
"""
#for
"""
total=0
for number in [2,-3,0,17,9]:
    total=total +number
print(total)
"""
'''
i=1
while i<=100:
    if(i%2==0):
        print(i)
    i+=1
'''
#list
'''
#usingwhile
data = [2,5,87,5,7,6,2,74]
i=0
while i<=7:
   # print(data[6])
    print(data[i])
    i+=1
    
# usingfor  
data = [2, 5, 87, 5, 7, 6, 2, 74]
              #for i in range(len(data)):  # Use the length of the data list to avoid IndexError
    #print(data[6])
    print(data[i])
    
 data = [2, 5, 87, 5, 7, 6, 2, 74]
              #for i in range(len(data)):  # Use the length of the data list to avoid IndexError
for in in data
    #print(data[6])
    print(data[i])   
'''
    
    