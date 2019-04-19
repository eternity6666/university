package unit11.exam.out;

public class Exam02 {
    public static void main(String[] args) {
        Person a = new Person("yzh", "China", "12343211234", "1233443321@gmail.com");
        Student b = new Student("xyf", "Japan", "45676544567", "4566776654@gmail.com", 2);
        Employee c = new Employee("hhh", "USA", "7899009987", "123456234@gmail.com", "room1", 12031);
        Faculty d = new Faculty("fad", "UK", "12345678901", "123121324@qq.com", "room2", 12311, "9:00-12:00", 5);
        Staff e = new Staff("abc", "UN", "12314123123", "654312134@qq.com", "room3", 12312, "monitor");
        System.out.println(a.toString());
        System.out.println(b.toString());
        System.out.println(c.toString());
        System.out.println(d.toString());
        System.out.println(e.toString());
    }
}

class Person {
    private String name;
    private String address;
    private String telephoneNumber;
    private String email;
    
    public Person() {
        this("Who am I?", "Where am I live in?", "What is my telephone number?", "What is my email address?");
    }

    public Person(String name, String address, String telephoneNumber, String email) {
        this.name = name;
        this.address = address;
        this.telephoneNumber = telephoneNumber;
        this.email = email;
    }

    public String getName() {
        return this.name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getAddress() {
        return this.address;
    }

    public void setAddress(String address) {
        this.address = address;
    }

    public String getTelephoneNumber() {
        return this.telephoneNumber;
    }

    public void setTelephoneNumber(String telephoneNumber) {
        this.telephoneNumber = telephoneNumber;
    }

    public String getEmail() {
        return this.email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    @Override
    public String toString() {
        return getName() + " is a person";
    }
}

class Student extends Person {
    private final int classStatus;

    public String getClassStatus() {
        switch(classStatus) {
            case 1:
                return "大一";
            case 2:
                return "大二";
            case 3:
                return "大三";
            case 4:
                return "大四";
            default:
                return "NULL";
        }
    }

    public Student() {
        this(1);
    }
    
    public Student(int classStatus) {
        this.classStatus = classStatus;
    }

    public Student(String name, String address, String telephoneNumber, String email, int classStatus) {
        super(name, address, telephoneNumber, email);
        this.classStatus = classStatus;
    }

    @Override
    public String toString() {
        return getName() + " is a student";
    }
}

class Employee extends Person {
    private String officeRoom;
    private double wage;//工资
    private java.util.Date offered;

    public Employee() {
        this("I don't have office room.", 1000);
        offered = new java.util.Date();
    }

    public Employee(String officeRoom, double wage) {
        this.officeRoom = officeRoom;
        this.wage = wage;
        offered = new java.util.Date();
    }

    public Employee(String name, String address, String telephoneNumber, String email, String officeRoom, double wage) {
        super(name, address, telephoneNumber, email);
        offered = new java.util.Date();
        this.officeRoom = officeRoom;
        this.wage = wage;
    }

    public String getOfficeRoom(){
        return this.officeRoom;
    }

    public void setOfficeRoom(String officeRoom) {
        this.officeRoom = officeRoom;
    }

    public double getWage() {
        return this.wage;
    }

    public void setWage(double wage) {
        this.wage = wage;
    }

    public java.util.Date getOffered() {
        return this.offered;
    }

    @Override
    public String toString() {
        return getName() + " is an employee";
    }
}

class Faculty extends Employee {
    private int level;
    private String workTime;

    public Faculty() {
        this(0, "8:00-17:00");
    }

    public Faculty(int level, String workTime) {
        this.level = level;
        this.workTime = workTime;
    }

    public Faculty(String name, String address, String telephoneNumber, String email, String officeRoom, double wage, String workTime, int level) {
        super(name, address, telephoneNumber, email, officeRoom, wage);
        this.level = level;
        this.workTime = workTime;
    }

    public int getLevel() {
        return this.level;
    }

    public void setLevel(int level) {
        this.level = level;
    }

    public String getWorkTime() {
        return this.workTime;
    }

    public void setWorkTime(String workTime) {
        this.workTime = workTime;
    }
    
    @Override
    public String toString() {
        return getName() + " is a faculty";
    }
}

class Staff extends Employee {
    private String jobTitle;

    public Staff() {
        this("What is my job title?");
    }

    public Staff(String jobTitle) {
        this.jobTitle = jobTitle;
    }

    public Staff(String name, String address, String telephoneNumber, String email,String officeRoom, double wage, String jobTitle) {
        super(name, address, telephoneNumber, email, officeRoom, wage);
        this.jobTitle = jobTitle;
    }

    public String getJobTitle() {
        return this.jobTitle;
    }

    public void setJobTitle(String jobTitle) {
        this.jobTitle = jobTitle;
    }

    @Override
    public String toString() {
        return getName() + " is a staff";
    }
}

