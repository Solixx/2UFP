import edu.princeton.cs.algs4.Queue;
import edu.princeton.cs.algs4.StdOut;

import java.security.Key;
import java.util.ArrayList;

public class Teste1_170321 {

    public BST_AED2_UFP<Integer, Integer> st;

    public Teste1_170321(BST_AED2_UFP<Integer, Integer> st) {
        this.st = st;
    }

    public static void main(String[] args) {
        int mykeys[] = new int[]{65, 34, 76, 21, 44, 90, 8, 81};
        BST_AED2_UFP<Integer, Integer> st = new BST_AED2_UFP<Integer, Integer>();
        Queue fila = new Queue();
        Teste1_170321 t = new Teste1_170321(st);

        for (int i = 0; i < mykeys.length; i++) {
            t.st.put(mykeys[i], i);
        }

        t.printLvl(t.st, 3);
        StdOut.println(t.isSimetric());
    }


    public void printLvl(BST_AED2_UFP st, int L){
        printLvl(st.root, L, 1);
    }
    private void printLvl(BST_AED2_UFP.Node n, int L, int countL){
        if(n == null)   return;
        printLvl(n.right, L, countL+1);
        printLvl(n.left, L,countL+1);
        if(countL == L){
            StdOut.println(n.key);
        }
    }

    public boolean isSimetric(){
        ArrayList<Integer> q = new ArrayList<>();
        inOrder(this.st.root, q);
        for (int i = 0; i < q.size(); i++){
            if(q.get(i) < q.get(i+1)){
                return false;
            }
        }
        return true;
    }
    private void inOrder(BST_AED2_UFP.Node n, ArrayList<Integer> q){
        if (n == null)  return;
        inOrder(n.left, q);
        q.add((Integer) n.val);
        inOrder(n.right, q);
    }
}
