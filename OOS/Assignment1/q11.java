class Date{

  int date,month ,year;
  Date(){
   date=1;
   month=1;
   year=1970;
   }
  Date(int d){
     date=d;
     month=1;
     year=1970;

    }
  Date(int d,int m){

      date=d;
      month=m;
      year=1970;
    }

    Date(int d,int m,int y){
    date=d;
     month=m;
     year=y;
    } 
   void prevday(){
     if(date==1 && month==1){
      System.out.print("previous day is ");
     System.out.println(31+"/"+12+"/"+ (year-1));
     }
    else if( date==1){
      System.out.print("previous date is");
      System.out.println(30+"/"+(month-1)+"/"+ year);
   }
    else{

    System.out.print("prev date is");
    System.out.print((date-1)+"/"+ month +"/" + year);
   }
   System.out.print("\n");
   } 
  void nextday(){
     if(month==12 && date==31){
       System.out.print("next date is ");
       System.out.println(1+ " /" + 1 +"/ "+ (year+1));
     }
      else if(month==2 && date==28){
          
     System.out.print("next date is ");
     System.out.println(1+ "/" + 3 + "/ " + year); 
   }
   else if(date==30 || date==31){  
    System.out.print("next date is");
   System.out.println(1 +"/" + (month+1) + "/" + year);
   } 
  else{
    System.out.print("new date is ");
    System.out.println((date+1) + "/" + month +  "/" + year);
   }
  }
}
class q11{

   public static void main(String args[]){
    Date df=new Date(31,12,2011);
     df.prevday();
     df.nextday();
   }

}
