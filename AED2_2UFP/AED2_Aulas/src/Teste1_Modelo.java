import edu.princeton.cs.algs4.BinarySearchST;
import edu.princeton.cs.algs4.StdOut;

public class Teste1_Modelo {

    public BST_AED2_UFP<Integer, Integer> st;

    public Teste1_Modelo(BST_AED2_UFP<Integer, Integer> st) {
        this.st = st;
    }

    public static void main(String[] args) {
        int mykeys[] = new int[]{65,34,76,21,44,90,8,81};
        BST_AED2_UFP<Integer, Integer> st = new BST_AED2_UFP<Integer, Integer>();
        Teste1_Modelo t = new Teste1_Modelo(st);

        for (int i = 0; i<mykeys.length; i++) {
            t.st.put(mykeys[i], i);
        }

        StdOut.println("Folhas: "+t.contaFolhas());
        StdOut.println("Nos: "+t.contaNos());
        t.printNodes(t.st.root, 34, 76);
    }

    public int contaFolhas(){
        return contaFolhas(this.st.root);
    }

    public int contaFolhas(BST_AED2_UFP.Node n){
        if(n == null)   return 0;
        if(n.left == null && n.right == null)   return 1;
        else return contaFolhas(n.left) + contaFolhas(n.right);
    }

    public int contaNos(){
        return contaNos(this.st.root);
    }

    public int contaNos(BST_AED2_UFP.Node n){
        if(n == null)   return 0;
        return 1 + contaNos(n.left) + contaNos(n.right);
    }

    public void printNodes(BST_AED2_UFP.Node n, int low, int high){
        if(n == null)   return;
        printNodes(n.left, low, high);
        printNodes(n.right, low, high);
        if(n.key.compareTo(low) >= 0 && n.key.compareTo(high) <= 0){
            StdOut.println(n.key);
        }
    }
}