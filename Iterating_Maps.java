import java.util.*;
public class Main
{
	public static void main(String[] args) {
	    Scanner scanner=new Scanner(System.in);
	    int n;
	    System.out.println("Enter the number of elements : ");
	    n=scanner.nextInt();
	    scanner.nextLine();
	    System.out.println("Enter the chacter along with values : ");
	    TreeMap<Character,Integer> dic=new TreeMap<>();
	    for(int i=0;i<n;i++){
	        dic.put(scanner.next().charAt(0),scanner.nextInt());
	        scanner.nextLine();
	    }
	    //1.Using EntrySet
	    Set<Map.Entry<Character,Integer>> eSet=dic.entrySet();
	    for(Map.Entry<Character,Integer> k:eSet){
	        System.out.println(k.getKey()+"--->"+k.getValue());
	    }
	    System.out.println("---------------------------");
	    //2.Using KeySet
	    Set<Character> kSet=dic.keySet();
	    for(Character c:kSet){
	        System.out.println(c+"--->"+dic.get(c));
	    }
	    System.out.println("----------------------------");
	    //3.values
	    Collection<Integer> values=dic.values();
	    for(Integer k:values){
	        System.out.println(k);
	    }
	}
}
