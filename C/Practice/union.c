#include <stdio.h>
union student {
int age;
char marks;
} s;

// Driver code
int main() {
s.age = 15;
s.marks = 56; // use s.marks = 'h'
printf("age = %d", s.age);
printf("\nmarks = %d", s.marks);
}
