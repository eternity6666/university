package unit10.example.out;

public class Example05 {

    public static void main(String[] args) {
        Example06 course1 = new Example06("Data Structures");

        Example06 course2 = new Example06("Database Systems");
        
        course1.addStudent("Peter Jones");
        course1.addStudent("Kim Smith");
        course1.addStudent("Anne Kennedy");

        course2.addStudent("Peter Jones");
        course2.addStudent("Steve Smith");

        System.out.println("Number of students in course1: " + course1.getNumberOfStudents());
        String[] students = course1.getStudents();

        for(int i = 0; i < course1.getNumberOfStudents(); i++)
            System.out.println(students[i] + ", ");
        System.out.println();
        System.out.println("Number of students in course2: " + course2.getNumberOfStudents());
    }
}

