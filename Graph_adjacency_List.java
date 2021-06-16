import java.util.*;
public class AdjacencyList {
    LinkedList<Integer> graph[];
    AdjacencyList(int n){
        graph=new LinkedList[n];
        for(int i=0;i<n;i++){
            graph[i]=new LinkedList<Integer>();
        }
    }
    boolean addEdge(int s,int d){
        graph[s].add(d);
        graph[d].add(s);
        return true;
    }
    void printGraph(){
        for(int i=0;i<graph.length;i++){
            System.out.println(graph[i]);
        }
    }
    void BFS(int s){
        Queue<Integer> q=new LinkedList<>();
        q.add(s);
        int count=0;
        Integer l;
        boolean visited[]=new boolean[graph.length];
        System.out.println("BFS of the graph : ");
        while(!q.isEmpty()){
            l=q.poll();
            visited[l]=true;
            System.out.print(l+" ");
            for(Integer i: graph[l]){
                if(!visited[i]){
                    q.add(i);
                    break;
                }
            }
        }
        System.out.println();
    }
    void DFS(int s){
        Stack<Integer> st=new Stack<>();
        st.add(s);
        boolean[] visited=new boolean[graph.length];
        int k;
        System.out.println("DFS of the graph : ");
        while(!st.isEmpty()){
            k=st.pop();
            System.out.print(k+" ");
            visited[k]=true;
            for(int i=0;i<graph.length;i++){
                if(!visited[i]){
                    st.push(i);
                    break;
                }
            }
        }
        System.out.println();
    }
    public static void main(String[] a){
        Scanner scanner=new Scanner(System.in);
        int n;
        System.out.println("Enter the number of nodes : ");
        n=scanner.nextInt();
        System.out.println("Enter the number of edges : ");
        int e=scanner.nextInt();
        AdjacencyList obj = new AdjacencyList(n);
        for(int i=0;i<e;i++){
            System.out.println("Enter the edge : ");
            obj.addEdge(scanner.nextInt(),scanner.nextInt());
        }
        obj.printGraph();
        obj.DFS(2);
    }
}
