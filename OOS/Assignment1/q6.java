class Employee{
    static int roll=0;
    String name;
    int id;
    double salary;
    Employee(String n){
        name=n;
        id=roll++;
        salary=0;
    }

    void set_sal(double s){
        salary=s;
    }

    void print(){
        System.out.println("Name = "+name);
        System.out.println("ID = "+id);
        System.out.println("Salary = "+salary);
    }
}
class Dept{
    String name;
    String location;
    Employee[] emps=new Employee[50];
    int top=0;

    void add(String name,int sal){
        emps[top]=new Employee(name);
        emps[top++].set_sal(sal);
        emps[top-1].print();
    }

    void remove(int id){
        for(int i=0;i<top;i++){
            if(id==emps[i].id){
                emps[i].id=0;
                emps[i].name="";
                emps[i].salary=0;
                System.out.println("Successfully removed");
                return;
            }
        }
        System.out.println("Employee Not Found");
    }

    double totalexpense(){
        double total=0.0;
        for(int i=0;i<top;i++){
            total+=emps[i].salary;
        }
        return total;        
    }
}
 class q6 {            
    public static void main(String[] args) {
        Dept IT=new Dept();
        IT.add("Debasish", 25000);
        IT.add("Ansh", 40000);
        IT.add("Aritra", 22000);
        IT.add("Trisanjit", 30000);
        IT.add("Rishi", 30000);
        System.out.println("Total expenditure of the department = "+IT.totalexpense());
    }
}

