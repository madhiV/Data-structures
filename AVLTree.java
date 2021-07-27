/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    Map<TreeNode,Integer> map;
    public TreeNode sortedArrayToBST(int[] nums) {
        TreeNode p,root;
        Stack<TreeNode> s;
        root=new TreeNode(nums[0]);
        //AVL Insertion
        for(int i=1;i<nums.length;i++){
            s=new Stack<>();
            s.push(root);
            while(!s.isEmpty()){
                if(s.peek().val<nums[i]){
                    if(s.peek().right==null){
                        s.peek().right=new TreeNode(nums[i]);
                        s.push(s.peek().right);
                        break;
                    }
                    else{
                        s.push(s.peek().right);
                    }
                }
                else{
                    if(s.peek().left==null){
                        s.peek().left=new TreeNode(nums[i]);
                        s.push(s.peek().left);
                        break;
                    }
                    else{
                        s.push(s.peek().left);
                    }
                }
            }
            root=fixBalance(root,s);
        }
        return root;
    }
    public TreeNode LLRotation(TreeNode root){
        TreeNode temp;
        temp=root;
        root=root.right;
        temp.right=root.left;
        root.left=temp;
        return root;
    }
    public TreeNode RRRotation(TreeNode root){
        TreeNode temp;
        temp=root;
        root=root.left;
        temp.left=root.right;
        root.right=temp;
        return root;
    }
    public int findHeight(TreeNode temp){
        if(temp==null){
            return -1;
        }
        if(map.containsKey(temp)){
            return map.get(temp);
        }
        map.put(temp,1+Math.max(findHeight(temp.left),findHeight(temp.right)));
        return map.get(temp);
    }
    public TreeNode fixBalance(TreeNode root,Stack<TreeNode> s){
        int balFact,prev;
        TreeNode p;
        // System.out.println(root.val);
        //AVL Balancing balance factors of each node
        while(!s.isEmpty()){
            p=s.pop();
            map=new HashMap<>();
            balFact=findHeight(p.left)-findHeight(p.right);
            //Right
            if(balFact<-1){
                prev=findHeight(p.right.left)-findHeight(p.right.right);
                //Right
                if(prev==-1){
                    p=LLRotation(p);
                }
                //Left
                else{
                    p.right=RRRotation(p.right);
                    p=LLRotation(p);
                }
            }
            //Left
            else if(balFact>1){
                prev=findHeight(p.left.left)-findHeight(p.left.right);
                //Left
                if(prev==1){
                    p=RRRotation(p);
                }
                //Left
                else{
                    p.left=LLRotation(p.left);
                    p=RRRotation(p);
                }
            }
            if(!s.isEmpty()){
                root=s.pop();
                if(root.val>p.val){
                    root.left=p;
                }
                else{
                    root.right=p;
                }
            }
            else{
                root=p;
            }
        }
        return root;
    }
}
