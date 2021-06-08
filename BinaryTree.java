import java.util.*;
public class BinaryTree {
    BNode temp,root,p;
    void insert(int data){
        temp=root;
        if(temp==null){
            root=new BNode(data);
        }
        else{
            Queue<BNode> q=new LinkedList<>();
            q.add(temp);
            while(q.size()>0){
                p=q.peek();
                q.remove();
                if(p.left!=null){
                    q.add(p.left);
                }
                else{
                    p.left=new BNode(data);
                    break;
                }
                if(p.right==null){
                    p.right=new BNode(data);
                    break;
                }
                else{
                    q.add(p.right);
                }
            }
        }
        System.out.println("Insertion success...");
    }
    void levelOrderTraverse(){
        BNode temp=root;
        if(temp==null){
            return;
        }
        Queue<BNode> q=new LinkedList<BNode>();
        q.add(temp);
        while(q.size()>0){
            p=q.peek();
            q.remove();
            System.out.print(p.data+" ");
            if(p.left!=null){
                q.add(p.left);
            }
            if(p.right!=null){
                q.add(p.right);
            }
        }
        System.out.println();
    }
    void DFS_rec(BNode temp){
        if(temp==null){
            return;
        }
        System.out.print(temp.data+" ");
        DFS_rec(temp.left);
        DFS_rec(temp.right);
    }
    void DFS_iterative(){
        temp=root;
        if(temp==null){
            System.out.println("Tree empty...");
            return;
        }
        Stack<BNode> s=new Stack<>();
        s.add(temp);
        while(s.size()>0){
            p=s.pop();
            System.out.print(p.data+" ");
            if(p.right!=null){
                s.push(p.right);
            }
            if(p.left!=null){
                s.push(p.left);
            }
        }
    }
    int leaf(BNode temp){
        if(temp==null){
            return 0;
        }
        if(temp.right==null && temp.left==null){
            return 1;
        }
        return leaf(temp.left)+leaf(temp.right);
    }
    int leaf_iterative(){
        if(root==null){
            return 0;
        }
        int count=0;
        Queue<BNode> q=new LinkedList<>();
        q.add(root);
        while(q.size()>0){
            p=q.peek();
            q.remove();
            if(p.left==null && p.right==null){
                count++;
                continue;
            }
            if(p.left!=null){
                q.add(p.left);
            }
            if(p.right!=null){
                q.add(p.right);
            }
        }
        return count;
    }
    void delete(int data){
        if(root.left==null && root.right==null){
            root=null;
            System.out.println(data+" deletion success...");
            return;
        }
        BNode keyNode=null,par=null;
        Queue<BNode> q=new LinkedList<>();
        q.add(root);
        while(q.size()>0){
            p=q.peek();
            q.remove();
            if(p.data==data){
                keyNode=p;
            }
            if(p.left!=null){
                par=p;
                q.add(p.left);
            }
            if(p.right!=null){
                par=p;
                q.add(p.right);
            }
        }
        if(keyNode==null){
            System.out.println("Node not present in the tree");
        }
        else{
            keyNode.data=p.data;
            if(p==par.right){
                par.right=null;
            }
            else{
                par.left=null;
            }
            System.out.println(data+" deletion sucess...");
        }
    }
int height(BNode temp){
        if(temp==null){
            return -1;
        }
        if(temp.right==null && temp.left==null){
            return 0;
        }
        return 1+Math.max(height(temp.left),height(temp.right));
}
int no(BNode temp){
        if(temp==null){
            return 0;
        }
        return 1+no(temp.right)+no(temp.left);
}
    public static void main(String[] args){
        Scanner scanner=new Scanner(System.in);
        BinaryTree obj=new BinaryTree();
        int flag=1,c,e;
        while(flag==1){
            System.out.println("-----MENU-----");
            System.out.println("1.Insert(Level order)\n2.Delete\n3.BFS\n4.DFS\n5.Number of leaf nodes\n6.Number of nodes\n7.Height of the tree\n0.Exit\nEnter a choice : ");
            c=scanner.nextInt();
            switch(c){
                case 1:
                    System.out.println("Enter the element : ");
                    e=scanner.nextInt();
                    obj.insert(e);
                    break;
                case 2:
                    System.out.println("Enter the element : ");
                    e=scanner.nextInt();
                    obj.delete(e);
                    break;
                case 3:
                    obj.levelOrderTraverse();
                    break;
                case 4:
                    obj.DFS_iterative();
                    System.out.println();
                    break;
                case 5:
                    System.out.println("No. of leaf nodes : "+obj.leaf_iterative());
                    break;
                case 6:
                    System.out.println("No. of nodes : "+obj.no(obj.root));
                    break;
                case 7:
                    System.out.println("The height of the tree is :"+obj.height(obj.root));
                    break;
                case 0:
                    flag=0;
                    System.out.println("Exit success...");
                    break;
                default:
                    System.out.println("Invalid choice...");
            }
        }
    }
}
