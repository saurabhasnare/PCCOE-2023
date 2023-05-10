
import java.net.*;
import java.io.*;  
import java.lang.*;

class client{  
public static void main(String args[])throws Exception{ 
    
int n;
int rec_frame_data[] = new int[5];

ServerSocket ss=new ServerSocket(3334);  
Socket s=ss.accept();  

System.out.println("Client connected!");

DataInputStream din=new DataInputStream(s.getInputStream());  
DataOutputStream dout=new DataOutputStream(s.getOutputStream());  
BufferedReader br=new BufferedReader(new InputStreamReader(System.in));  

n  = din.read();
System.out.println("No of frames you will be recieving from client are : "+n);
System.out.println("---------------Ready to receive frames------------\n");
int check=0;
int flag=0;
int x=0;
int gvar=0;
for(int i=0; i<n; i++){
    int data  = din.read();
    if(check==data){

   // Thread.sleep(1200);
    x=i+1;
    System.out.println("received Frame no : "+ i + " Received data : "+ i);
    System.out.println("Sending acknowledgement for frame no:"+x);
    check++;
    }else{
    int tmp2=i+1;
    	if(flag==0){
    	flag=data;
    	int tmp=flag-1;
    	 gvar=tmp;
    	System.out.println("\nERROR .. FRAME NO :"+tmp+"Not received");
    	}
    	 System.out.println("Frame no : "+ tmp2 + "recieved and DISCARDED.. ");
    	
    	check++;
    }
}

dout.write(gvar);


// if(i==(n-1)){
//     System.out.println("-----All frames are received!-----");
// }
// else{
//     System.out.println("May one or more frames are list");
// }


// int changed_add = din.read();
// System.out.println(changed_add);

// int changed_val = din.read();
// System.out.println("Changed to : "+changed_val);

din.close(); 
dout.close(); 
s.close();  
ss.close();  
}}  
