class tollboth{

void totalnumberofcars(int m,int n){

   System.out.println("total number of cars passed by are "+ m);
   System.out.println("total cash collected is "+ n);
   int s=n/50;
   System.out.println("total number of cars paying tax are "+ s);
int u=m-s;
   System.out.println("total number of cars that didnot pay tax were "+u); 
}

}
class q15{

public static void main(String args[]){

 tollboth gf=new tollboth();
 gf.totalnumberofcars(100,2500);


}

}
