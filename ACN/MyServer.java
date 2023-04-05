import java.net.*;  
import java.io.*;  
class MyServer{  
public static void main(String args[])throws Exception{  
		ServerSocket ss=new ServerSocket(3334);  
		Socket s=ss.accept();  
		System.out.println("Connected");
		
		DataInputStream din=new DataInputStream(s.getInputStream());  //Used to read the data sent from socket
		DataOutputStream dout=new DataOutputStream(s.getOutputStream()); //used to write message to client  
		
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));  //class like scanner class used to read input directly in form of stram[0,1]
		  
		String str="",str2="";  
		try{
		while(!str.equals("stop")){  
		
		
		str=din.readUTF();  //reading input from input stream
		System.out.println("client says: "+str);  
		str2=br.readLine();  //taking inpuit from console to send msg to clint
		dout.writeUTF(str2);  //writng msg in dataoutputstream using writeUTF method 
		dout.flush();  
		} 
		}catch(Exception e){
		}
		din.close();  //closing  data input stram
		s.close();   //closing  socket 
		ss.close();  //closing server socket
}}  
