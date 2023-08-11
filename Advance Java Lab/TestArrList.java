import java.util.*;
public class TestArrList
{
public static void main(String args[]){


	ArrayList<Integer> l=new ArrayList<>();
	l.add(10);
	l.add(20);
	l.add(30);
	l.add(40);
	
	for(int i=0;i<l.size();i++){
		System.out.println(l.get(i));
	}
	
	
	
	if(l.size()>=3){
	System.out.println("After removing element at position/index 2");
	l.remove(2);
	for(int i=0;i<l.size();i++){
		System.out.println(l.get(i));
	}
	
	}
	
	
	
	
}
}
