package unit10.example.out;

public class Example06 {

    private String courseName;
    private String[] students = new String[100];
    private int numberOfStudents;

    public Example06(String courseName) {
        this.courseName = courseName;
    }
    
    public void addStudent(String student) {
        students[numberOfStudents] = student;
        numberOfStudents++;
    }

    public String[] getStudents() {
        return students;
    }

    public int getNumberOfStudents() {
        return numberOfStudents;
    }

    public String getCourseName() {
        return courseName;
    }

    public void dropStudent(String student) {
        int j = 0;
        for(int i = 0; i < numberOfStudents; i++)
            if(students[i].equals(student)) {
                j = i;
                break;
            }

        for(; j < numberOfStudents - 1; j++)
            students[j] = students[j + 1];
        numberOfStudents--;
    }
}

