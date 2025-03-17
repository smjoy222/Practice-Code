'''


country = ['india','thailand','bhutan','china','nepal','myanmer']
for c in country:
    if 'myanmer' in c:
        continue
    print(c)
        
 #or
        
countries = ['India', 'Thailand', 'Bhutan', 'China', 'Nepal', 'Myanmar']
countries.remove('Myanmar')
for country in countries:=
    print(country)
        
        
list1 = [1,2,3]
list2 = [2,4,5]
common = []
for i in list1:
    if i in list2:
        common.append(i)
               
if common:
    print(common) 
else:
    print('no common elements') 
    
odd = []
for i in range(1,101):
   if i %2 != 0:
       odd.append(i)
print(odd)     

fee = float(input("Enter semester fee :"))
cgpa = float(input('enter cgpa'))
if cgpa > 3.50:
    weiver = 10
elif cgpa <=3.50:
    weiver = 10
else:
    weiver = 0    
print('Weiver ammount:',weiver)             
         
value = [1,2,3,4,5,6,7,8,91]
value2 =[1,2,3]
for item in value:
    if item == 5: 
      continue
    print ("break")
     for item2 in value2:
        print(item,item2)         
        
## spiring 2022
    
def cheakday(i):
    if i == 'friday':
        print("Today is hollyday")
    else:
        print("working day")
                
day = ['saturday','sunday','teusday','thursday','friday']
day.insert(2,'monday')
day.insert(4,'wednesday')

for i in day:
   cheakday(i)

#OR
def cheakday(i):
    if i == 'friday':
        print('Today is Holyday')
    else:
        print('working day')    
day = ['satuday','sunday','teusday','thurday','friday']
day.append('monday')
day.append('wednesday')
#orUse
#day.extend(['monday',wednesday])
for i in day:
    cheakday(i)   
    
personal_info = ['Name - jdkj','father name - fiufg','Mother name - usebf','phone number - 5585255266']
num_vowel =0
for info in personal_info:
    num_charector = len(info)
    
    if personal_info == 'aeiou':
        num_vowel= num_vowel+1
        print(info)
        print(num_charector)
        print(num_vowel)
        print()
        '''

def list(lst):
    for i in lst:       
        if i % 2 == 0:          
            print("The list of even numbers are:", i)
        else:          
            print("The list of odd numbers are:", i)
L = [12, 15, 33, 7, 1, 92, 53, 4, 0]
print("The list is:")
print(L)
list(L)
      