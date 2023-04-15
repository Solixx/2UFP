import edu.princeton.cs.algs4.Queue;
import edu.princeton.cs.algs4.StdOut;

import java.security.Key;

public class Teste1_160407 {

    public BST_AED2_UFP<Integer, Integer> st;

    public Teste1_160407(BST_AED2_UFP<Integer, Integer> st) {
        this.st = st;
    }

    public static void main(String[] args) {
        int mykeys[] = new int[]{65, 34, 76, 21, 44, 90, 8, 81};
        BST_AED2_UFP<Integer, Integer> st = new BST_AED2_UFP<Integer, Integer>();
        Queue fila = new Queue();
        Teste1_160407 t = new Teste1_160407(st);

        for (int i = 0; i < mykeys.length; i++) {
            t.st.put(mykeys[i], i);
        }

        StdOut.println(t.alturaMedia());
        t.printLevelOrder();
    }

    public int alturaMedia(){
        return (this.st.contaNos()-this.st.contaFolhas())/2;
    }

    public void printLevelOrder(){
        Queue<Key> k = new Queue();
        Queue<BST_AED2_UFP.Node> q = new Queue<>();
        q.enqueue(this.st.root);
        while (!k.isEmpty()){
            BST_AED2_UFP.Node n = q.dequeue();
            if(n == null)   continue;
            k.enqueue((Key) n.key);
            StdOut.println(k);
            q.enqueue(n.left);
            q.enqueue(n.right);
        }
    }
}
