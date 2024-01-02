
import encapsulation_basic.Teacher;

public class Test {
    public static void main(String[] args) {
        Teacher t = new Teacher();

        t.setNamne("Joy");
        // to the value of the variable
        t.setAge(22);

        System.out.println("Teacher Name: " + t.getName());
        System.out.println("Teacher Age: " + t.getAge());
        // and use(object.getFunction)to print the private value

    }

}