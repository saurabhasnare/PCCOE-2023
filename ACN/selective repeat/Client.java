import java.net.*;
import java.util.Scanner;
import java.io.*; 
import java.lang.*; 


    class Client{  
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
        System.out.println("Sending Frame no : "+i+ " Data is : "+frame_data[i]);
        dout.write(frame_data[i]);
    }

    System.out.println("All frames are sent !");

    System.out.println("Enter frame no to change data ");
    change_index = sc.nextInt();


    frame_data[change_index] = 0;
    // dout.write(change_index);
    // dout.write(frame_data[change_index]);


    for(int j=0; j<n; j++){
        // Thread.sleep(1000);
        System.out.println("Sending Frame no : "+j+ " Data is : "+frame_data[j]);
        dout.write(frame_data[j]);
    }

    dout.close();  
    s.close();  
    }}  
