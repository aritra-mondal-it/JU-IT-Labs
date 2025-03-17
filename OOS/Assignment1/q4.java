
class Account{
    static int Number=100000;
    int ACnum;
    double balance;
    String owner_name;
    Account(String name){
        ACnum=Number++;
        balance=0;
        owner_name=name;
    }

    void get_bal(){
        System.out.println("Balance = "+balance);
    }

    void add(float money){
        balance+=money;
    }

    void subtract(float money){
        balance-=money;
    }

    void print(){
        System.out.println("Owner Name : "+owner_name);
        System.out.println("Account Number : "+ACnum);
        System.out.println("Balance : "+balance);
    }
}

class AccountManager{
    Account[] Accs;
    int size;
    int top=-1;
    AccountManager(int s){
        size=s;
        Accs=new Account[s];
    }

    void CreateAccount(String s){
        top++;
        Accs[top] = new Account(s);
        Accs[top].print();
    }

    void DeleteAccount(int Number){
        for(int i=0;i<top+1;i++){
            if(Number==Accs[i].ACnum){
                Accs[i].ACnum=0;
                Accs[i].owner_name="";
                Accs[i].balance=0.0;
                System.out.println("Successfully deleted");
                return;
            }
        }
        System.out.println("Account Not Found");
    }

    void deposit(int AC, int money){
        for(int i=0;i<top+1;i++){
            if(AC==Accs[i].ACnum){
                Accs[i].add(money);
                System.out.println("Successfully deposited");
                return;
            }
        }
        System.out.println("Account Not Found");
    }

    void withdraw(int AC, int money){
        for(int i=0;i<top+1;i++){
            if(AC==Accs[i].ACnum){
                Accs[i].add(money);
                System.out.println("Successfully deposited");
                return;
            }
        }
        System.out.println("Account Not Found");
    }
}

   class q4 {
    public static void main(String[] args) {
        AccountManager acm=new AccountManager(40);
        acm.CreateAccount("Debasish");
        acm.CreateAccount("rishi");
        acm.CreateAccount("Trisanjit");
        acm.CreateAccount("Ansh");
        acm.CreateAccount("aritra");

        acm.deposit(100000, 60000);
        acm.deposit(100001,70000);
        acm.deposit(100003, 90000);
        acm.deposit(100004, 10000000);
        System.out.println("ALL ACCOUNTS: ");
        for(int i=0;i<5;i++){
            acm.Accs[i].print();
        }
    }
}
