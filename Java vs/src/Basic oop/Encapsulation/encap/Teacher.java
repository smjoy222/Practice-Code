
public class Teacher {
    private String name;
    private int age;

    public void setNamne(String name) {
        
        this.name = name;
        // to access the Private Variable only
    }

    public String getName() {
        // to get the Private Variable
        return name;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public int getAge() {
        return age;
    }

}