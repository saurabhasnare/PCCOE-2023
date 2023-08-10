// Online Java Compiler
// Use this editor to write, compile and run your Java code online
import java.util.*;
public class Main {
    
    
    public static void main(String[] args) { 
       Scanner sc=new Scanner(System.in);
       
       int arr[]=new int[100];
       
       System.out.println("Enter Number of element in arr:");
       
       int n=sc.nextInt();
             
       for(int i=0;i<n;i++){
           arr[i]=sc.nextInt();
           
       }
        System.out.println("Enter Number to search in arr:");
       int x=sc.nextInt();
       
      int temp=binarySearch(arr,0,n-1,x);
      
      if(temp==-1){
          System.out.println("not Found");
      }else{
             System.out.println("  Found");
      }
       
    }
    public static int binarySearch(int arr[],int i, int j,int target ){
        
        int mid=i+(j-i)/2;
        
        if(arr[mid]==target){
            return mid;    
        }
        else
        {
            if(arr[mid]>target){
                 binarySearch(arr,i,mid-1,target);
            }
            else{
                
                 binarySearch(arr,mid+1,j,target);
                 
            }
        }
       
        return -1;
    }
}
