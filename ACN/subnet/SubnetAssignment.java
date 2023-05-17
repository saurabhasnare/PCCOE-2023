import java.io.*;
import java.net.*;
import java.util.*;

public class SubnetAssignment {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        String website, uip;
        int ibinaryArray[] = new int[4];
        String sbinaryArray[] = new String[4];
        String[] sipArr = new String[4];
        int ipArr[] = new int[4];

        System.out.println("Enter IP for getting subnet mask:");
        uip = sc.next();

        sipArr = uip.split("\\.");

        for (int i = 0; i < 4; i++) {
            ipArr[i] = Integer.parseInt(sipArr[i]);
            
        }
        
        for (int i = 0; i < 4; i++) {
           System.out.print(ipArr[i]+"."); 
        }


        for (int i = 0; i < 4; i++) {
            String binaryString = String.format("%8s", Integer.toBinaryString(ipArr[i])).replace(' ', '0');

            sbinaryArray[i] = binaryString;

            ibinaryArray[i] = Integer.parseInt(sbinaryArray[i]);

        }

        System.out.println("Enter number of subnets:");
        int nsubnets = sc.nextInt();
	int result=256/nsubnet;
	
	 int 
        
        System.out.println(result);
        
        f
        for(int i=0;i<4;i++){
        
        if(i==3){
        int temp=ipArr[i]+result-1;
       	System.out.print(temp); 
        
        }else{
         System.out.print(ipArr[i]+"."); 
       }
      }
        
	
    }
}
