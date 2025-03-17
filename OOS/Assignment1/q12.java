// Class to represent a Student
class Student {
    private String name;
    private int rollNo;
    private String[] subjects;

    // Constructor to initialize a student
    public Student(String name, int rollNo, String[] subjects) {
        this.name = name;
        this.rollNo = rollNo;
        this.subjects = subjects;
    }

    // Getter and Setter methods
    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getRollNo() {
        return rollNo;
    }

    public void setRollNo(int rollNo) {
        this.rollNo = rollNo;
    }

    public String[] getSubjects() {
        return subjects;
    }

    public void setSubjects(String[] subjects) {
        this.subjects = subjects;
    }
}

// Class to represent a Tabulation Sheet
class TabulationSheet {
    private String subjectName;
    private int[] marks;

    // Constructor to initialize a tabulation sheet
    public TabulationSheet(String subjectName) {
        this.subjectName = subjectName;
        this.marks = new int[3]; // Assuming there are 3 students
    }

    // Method to add marks for a specific student (by roll number)
    public void addMarks(int rollNo, int mark) {
        // Roll numbers are assumed to be between 101 to 103 for 3 students.
        // Mapping roll number to an index in marks array
        if (rollNo == 101) {
            marks[0] = mark;
        } else if (rollNo == 102) {
            marks[1] = mark;
        } else if (rollNo == 103) {
            marks[2] = mark;
        }
    }

    // Getter method for marks of a particular student
    public int getMarks(int rollNo) {
        if (rollNo == 101) {
            return marks[0];
        } else if (rollNo == 102) {
            return marks[1];
        } else if (rollNo == 103) {
            return marks[2];
        }
        return -1; // If invalid roll number
    }

    public String getSubjectName() {
        return subjectName;
    }
}

// Class to represent a Mark Sheet
class MarkSheet {
    private Student student;
    private int[] marks; // Array to store marks for all subjects

    // Constructor to initialize a mark sheet
    public MarkSheet(Student student) {
        this.student = student;
        this.marks = new int[5]; // 5 subjects
    }

    // Method to add marks for a student in each subject
    public void addMarks(TabulationSheet[] tabulationSheets) {
        String[] subjects = student.getSubjects();
        for (int i = 0; i < subjects.length; i++) {
            marks[i] = tabulationSheets[i].getMarks(student.getRollNo());
        }
    }

    // Method to print the marksheet
    public void printMarkSheet() {
        System.out.println("Mark Sheet for " + student.getName() + " (Roll No: " + student.getRollNo() + "):");
        String[] subjects = student.getSubjects();
        for (int i = 0; i < subjects.length; i++) {
            System.out.println(subjects[i] + ": " + marks[i]);
        }
        System.out.println("----------------------------------------");
    }
}

// Main function to create students and print their mark sheets
public class q12 {
    public static void main(String[] args) {
        // Create student objects
        String[] subjects = {"Math", "English", "Science", "History", "Art"};
        Student student1 = new Student("Alice", 101, subjects);
        Student student2 = new Student("Bob", 102, subjects);
        Student student3 = new Student("Charlie", 103, subjects);

        // Create TabulationSheet objects for each subject
        TabulationSheet tabulationMath = new TabulationSheet("Math");
        TabulationSheet tabulationEnglish = new TabulationSheet("English");
        TabulationSheet tabulationScience = new TabulationSheet("Science");
        TabulationSheet tabulationHistory = new TabulationSheet("History");
        TabulationSheet tabulationArt = new TabulationSheet("Art");

        // Add marks for each student in each subject
        tabulationMath.addMarks(101, 85);
        tabulationMath.addMarks(102, 78);
        tabulationMath.addMarks(103, 92);

        tabulationEnglish.addMarks(101, 88);
        tabulationEnglish.addMarks(102, 79);
        tabulationEnglish.addMarks(103, 84);

        tabulationScience.addMarks(101, 90);
        tabulationScience.addMarks(102, 85);
        tabulationScience.addMarks(103, 89);

        tabulationHistory.addMarks(101, 76);
        tabulationHistory.addMarks(102, 82);
        tabulationHistory.addMarks(103, 80);

        tabulationArt.addMarks(101, 95);
        tabulationArt.addMarks(102, 80);
        tabulationArt.addMarks(103, 91);

        // Create an array of TabulationSheets
        TabulationSheet[] tabulationSheets = {tabulationMath, tabulationEnglish, tabulationScience, tabulationHistory, tabulationArt};

        // Create MarkSheet objects for each student
        MarkSheet marksheet1 = new MarkSheet(student1);
        MarkSheet marksheet2 = new MarkSheet(student2);
        MarkSheet marksheet3 = new MarkSheet(student3);

        // Add marks to the mark sheets
        marksheet1.addMarks(tabulationSheets);
        marksheet2.addMarks(tabulationSheets);
        marksheet3.addMarks(tabulationSheets);

        // Print the mark sheets
        marksheet1.printMarkSheet();
        marksheet2.printMarkSheet();
        marksheet3.printMarkSheet();
    }
}

