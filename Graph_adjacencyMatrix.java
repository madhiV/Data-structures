import java.util.*;
public class AdjacencyMatrix {
    int[][] graph;
    int n;
    AdjacencyMatrix(int a){
        n=a;
        graph=new int[a][a];
    }
    void addEdge(int s,int d){
        graph[s][d]=1;
        graph[d][s]=1;
    }
    void printGraph(){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                System.out.print(graph[i][j]+" ");
            }
            System.out.println();
        }
    }
    public static void main(String[] ar){
        Scanner scanner=new Scanner(System.in);
        System.out.println("Enter the number of nodes : ");
        int n=scanner.nextInt();
        AdjacencyMatrix obj =new AdjacencyMatrix(n);
        System.out.println("Enter the number of edges : ");
        int e=scanner.nextInt();
        for(int i=0;i<e;i++){
            System.out.println("Enter the edge "+(i+1)+" : ");
            obj.addEdge(scanner.nextInt(),scanner.nextInt());
        }
        obj.printGraph();
    }
}
