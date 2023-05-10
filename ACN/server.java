import java.net.*;
import java.util.Scanner;
import java.io.*; 
import java.lang.*; 


    class server{  
    public static void main(String args[])throws Exception{  
    Scanner sc = new Scanner(System.in);

    Socket s = new Socket("localhost",3334);

    int n, change_index;
    int frame_data[] = {50,100,40,15,85};


    DataInputStream din=new DataInputStream(s.getInputStream());  
    DataOutputStream dout=new DataOutputStream(s.getOutputStream());  

    BufferedReader br=new BufferedReader(new InputStreamReader(System.in));  
      

    System.out.println("How many frames do you want to send");
    n = sc.nextInt();

    dout.write(n);

    for(int i=0; i<n; i++){
        //Thread.sleep(1000);
        
        int x=i+1;
        if(i==2){
                System.out.println("Sending Frame no : "+i+ " Data is : "+i);
        }else{
        System.out.println("Sending Frame no : "+i+ " Data is : "+i);
        dout.write(i);
        if(i<2){
                System.out.println("recieved acknowledgement for frame no:"+x);
        }

        }
    }

    System.out.println("All frames are sent !");

    int xx=din.read();
	System.out.println(xx);
    dout.close();  
    s.close(); 
    din.close();  
    }}  
