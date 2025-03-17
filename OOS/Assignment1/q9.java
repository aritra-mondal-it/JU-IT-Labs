import java.util.*;
class Person {
    private int age;
    private double weight;
    private double height;
    private String dateOfBirth;
    private String address;

    public Person(int age, double weight, double height, String dateOfBirth, String address) {
        this.age = age;
        this.weight = weight;
        this.height = height;
        this.dateOfBirth = dateOfBirth;
        this.address = address;
    }

    
    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public double getWeight() {
        return weight;
    }

    public void setWeight(double weight) {
        this.weight = weight;
    }

    public double getHeight() {
        return height;
    }

    public void setHeight(double height) {
        this.height = height;
    }

    public String getDateOfBirth() {
        return dateOfBirth;
    }

    public void setDateOfBirth(String dateOfBirth) {
        this.dateOfBirth = dateOfBirth;
    }

    public String getAddress() {
        return address;
    }

    public void setAddress(String address) {
        this.address = address;
    }
}


class Employee extends Person {
    private double salary;
    private String dateOfJoining;
    private int experience;

    public Employee(int age, double weight, double height, String dateOfBirth, String address, double salary, String dateOfJoining, int experience) {
        super(age, weight, height, dateOfBirth, address);
        this.salary = salary;
        this.dateOfJoining = dateOfJoining;
        this.experience = experience;
    }

  
    public double getSalary() {
        return salary;
    }

    public void setSalary(double salary) {
        this.salary = salary;
    }

    public String getDateOfJoining() {
        return dateOfJoining;
    }

    public void setDateOfJoining(String dateOfJoining) {
        this.dateOfJoining = dateOfJoining;
    }

    public int getExperience() {
        return experience;
    }

    public void setExperience(int experience) {
        this.experience = experience;
    }
}

 class Student extends Person {
    private int roll;
    private String[] listOfSubjects;
    private int[] marks;

    public Student(int age, double weight, double height, String dateOfBirth, String address, int roll, String[] listOfSubjects, int[] marks) {
        super(age, weight, height, dateOfBirth, address);
        this.roll = roll;
        this.listOfSubjects = listOfSubjects;
        this.marks = marks;
    }

    
    public int getRoll() {
        return roll;
    }

    public void setRoll(int roll) {
        this.roll = roll;
    }

    public String[] getListOfSubjects() {
        return listOfSubjects;
    }

    public void setListOfSubjects(String[] listOfSubjects) {
        this.listOfSubjects = listOfSubjects;
    }

    public int[] getMarks() {
        return marks;
    }

    public void setMarks(int[] marks) {
        this.marks = marks;
    }

   
    public String calculateGrade() {
        int totalMarks = 0;
        for (int mark : marks) {
            totalMarks += mark;
        }
        double average = totalMarks / (double) marks.length;

        if (average >= 90) return "A";
        else if (average >= 75) return "B";
        else if (average >= 50) return "C";
        else return "D";
    }
}


class Technician extends Employee {
    public Technician(int age, double weight, double height, String dateOfBirth, String address, double salary, String dateOfJoining, int experience) {
        super(age, weight, height, dateOfBirth, address, salary, dateOfJoining, experience);
    }
}


class Professor extends Employee {
    private String[] courses;
    private String[] listOfAdvisee;

    public Professor(int age, double weight, double height, String dateOfBirth, String address, double salary, String dateOfJoining, int experience, String[] courses, String[] listOfAdvisee) {
        super(age, weight, height, dateOfBirth, address, salary, dateOfJoining, experience);
        this.courses = courses;
        this.listOfAdvisee = listOfAdvisee;
    }

    
    public String[] getCourses() {
        return courses;
    }

    public void setCourses(String[] courses) {
        this.courses = courses;
    }

    public String[] getListOfAdvisee() {
        return listOfAdvisee;
    }

    public void setListOfAdvisee(String[] listOfAdvisee) {
        this.listOfAdvisee = listOfAdvisee;
    }

    
    public void addAdvisee(String advisee) {
        String[] newAdvisee = new String[listOfAdvisee.length + 1];
        System.arraycopy(listOfAdvisee, 0, newAdvisee, 0, listOfAdvisee.length);
        newAdvisee[listOfAdvisee.length] = advisee;
        listOfAdvisee = newAdvisee;
    }

    
    public void removeAdvisee(String advisee) {
        String[] newAdvisee = new String[listOfAdvisee.length - 1];
        int index = 0;
        for (String currentAdvisee : listOfAdvisee) {
            if (!currentAdvisee.equals(advisee)) {
                newAdvisee[index++] = currentAdvisee;
            }
        }
        listOfAdvisee = newAdvisee;
    }
}


 class q9 {
    public static void main(String[] args) {
        
        String[] subjects = {"Math", "Science", "History"};
        int[] marks = {85, 90, 78};
        Student student = new Student(20, 65.0, 5.8, "2005-04-10", "123 Street", 101, subjects, marks);
        System.out.println("Student Grade: " + student.calculateGrade());

        
        Technician technician = new Technician(30, 75.0, 6.0, "1993-03-15", "456 Avenue", 50000, "2020-01-15", 3);
        System.out.println("Technician Experience: " + technician.getExperience() + " years");

       
        String[] courses = {"Physics", "Quantum Mechanics"};
        String[] advisees = {"Alice", "Bob"};
        Professor professor = new Professor(45, 80.0, 5.9, "1978-07-20", "789 Boulevard", 120000, "2010-09-01", 15, courses, advisees);
        professor.addAdvisee("Charlie");
        System.out.println("Professor's Advisees: " + String.join(", ", professor.getListOfAdvisee()));
    }
}


