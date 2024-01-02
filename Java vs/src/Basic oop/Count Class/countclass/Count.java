package countclass;

public class Count {
    
     //int count = 0; 
    //here instance variable so,each new class will start from new count 0 
        
    static int flag =0;
    //static count 0 so, each object will count correctly

    public Count(){
      flag++;
    }

    public void counting(){
        System.out.println("Object Found: "+flag);
      }
}
