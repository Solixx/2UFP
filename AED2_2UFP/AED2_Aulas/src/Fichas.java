import edu.princeton.cs.algs4.*;

import javax.management.openmbean.ArrayType;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Hashtable;

public class Fichas {

    public static void main(String[] args) {
        //Ficha1 f1 = new Ficha1();
        //f1.ex10(5, 4, 6);

        //Ficha2.ex2();
    }
}

class Ficha1 {

    public void ex1(){
        SequentialSearchST<String,Integer> st= new SequentialSearchST<>();
        st.put("Excelente",20);
        st.put("Muito Bom",18);
        st.put("Bom",16);
        st.put("Suficiente",12);
        st.put("Insuficiente",7);
        st.put("Fraco",3);
        In in = new In("./data/aed2_aulas/notas_qualitativas2.txt");
        int soma=0,count=0;
        float media=0;
        while (in.hasNextLine()){
            String nota=in.readLine();
            soma+=st.get(nota);
            count++;
        }
        media=soma/count;
        System.out.println(media);
    }

    public void ex3(){
        SequentialSearchST<String,Integer> st= new SequentialSearchST<>();
        String teste="EASYQUESTION";
        for (int i=0 ; i < teste.length() ; i++){
            String chave = teste.substring(i,i+1);
            System.out.print(chave + ',' + i + ": ");
            st.put(chave,i);
            for (String k: st.keys()){
                System.out.print("[" + k + "," + st.get(k) + "]->");
            }
            System.out.println();
        }
    }
    public void ex6(){
        BinarySearchST<String,Integer> st= new BinarySearchST<>();
        String teste="EASYQUESTION";
        for (int i=0 ; i < teste.length() ; i++){
            String chave = teste.substring(i,i+1);
            System.out.print(chave + ',' + i + ": ");
            st.put(chave,i);
            for (String k: st.keys()){
                System.out.print("[" + k + "," + st.get(k) + "],");
            }
            System.out.println();
        }
        System.out.println(st.rank("B"));
        System.out.println(st.rank("S"));
        System.out.println(st.rank("U"));
        System.out.println("Maior letra -> " +st.max());
        System.out.println("Menor letra -> " +st.min());
        System.out.println("chaves entre B e P -> " +st.keys("B","P"));

    }

    public void ex10(int N, int c, int f){
        BinarySearchST<Integer,Integer> st = new BinarySearchST<>();
        for(int i = 0; i < N; i++){
            st.put(i, i+1);
        }
        for(Integer k: st.keys()){
            System.out.print("[" + k + "," + st.get(k) + "],");
        }
        System.out.println("\nCeiling de "+c+": "+st.ceiling(c));
        System.out.println("Floor de "+f+": "+st.floor(f));
    }
}

class  Ficha2 {

    public static void main(String[] args) {
        ex6();
    }

    public static void ex1(){
        int mykeys[] = new int[]{65,34,76,21,44,90,8,81};
        BST_AED2_UFP<Integer, Integer> st = new BST_AED2_UFP<Integer, Integer>();
        for (int i = 0; i<mykeys.length; i++) {
            st.put(mykeys[i], i);
        }

        StdOut.println("Numero de folhas da arvore: "+st.contaFolhas());
    }

    public static void ex2(){
        int mykeys[] = new int[]{65,34,76,21,44,90,8,81};
        BST_AED2_UFP<Integer, Integer> st = new BST_AED2_UFP<Integer, Integer>();
        for (int i = 0; i<mykeys.length; i++) {
            st.put(mykeys[i], i);
        }

        StdOut.println("Numero de nos da arvore: "+st.contaNos());
    }

    public static void ex6(){
        int mykeys[] = new int[]{65,34,76,21,44,90,8,81};
        BST_AED2_UFP<Integer, Integer> st = new BST_AED2_UFP<Integer, Integer>();
        for (int i = 0; i<mykeys.length; i++) {
            st.put(mykeys[i], i);
        }
        System.out.println("BST por niveis:");
        for (Integer s : st.levelOrder())
            StdOut.println("Key=" + s + ", Value = " + st.get(s));

        StdOut.println();
        System.out.println("BST inorder keys:");

        for (Integer s : st.inorder())
            StdOut.println("Key=" + s + ", Value = " + st.get(s));

        StdOut.println();
        System.out.println("BST preorder keys:");

        for (Integer s : st.preorder())
            StdOut.println("Key=" + s + ", Value = " + st.get(s));

        StdOut.println();
        System.out.println("BST posorder keys:");

        for (Integer s : st.posorder())
            StdOut.println("Key=" + s + ", Value = " + st.get(s));
    }
}

class Ficha6 {

    public static void main(String[] args) {
        //ex1_grafo3();
        //ex10_2();
    }

    public static void ex1_grafo3(){
        In in_file = new In("./data/grafo3Ex1.txt");
        Graph g = new Graph(in_file);
        System.out.println("Opção 1 de construção de grafos");
        System.out.println(g);

        int v = 5;
        Graph g2 = new Graph(v);
        System.out.println("Opção 2 de construção de grafos");
        g2.addEdge(0,2);
        g2.addEdge(0,3);
        g2.addEdge(0,4);
        g2.addEdge(1,2);
        g2.addEdge(1,4);
        g2.addEdge(4,3);
        g2.addEdge(1,3);
        System.out.println(g2);
    }

    public static void ex10_1(){
        In in_file = new In("./data/grafo3Ex1.txt");
        Graph_AED2_UFP g = new Graph_AED2_UFP(in_file);
        System.out.println(g);

        Graph_AED2_UFP g2 = new Graph_AED2_UFP(g);
        System.out.println(g2);
    }

    public static void ex10_2(){
        In in_file = new In("./data/grafo3Ex1.txt");
        Graph_AED2_UFP g = new Graph_AED2_UFP(in_file);
        System.out.println(g);

        int v = 2;
        Graph_AED2_UFP g2 = new Graph_AED2_UFP(g, v);
        System.out.println(g2);
    }

}

class Ficha4 {
    public static void main(String[] args) {
        ficha4_ex4();
    }
    public static void ficha4_ex4() {
        int mykeys[] = new int[]{1, 8, 27, 64, 125, 216, 343};
        int M=7;
        boolean test_resize = false;
        LinearProbingHashST_AED2_UFP<Integer, Integer> st = new
                LinearProbingHashST_AED2_UFP<>(M);
        for (int i = 0; i < mykeys.length; i++) {
            st.put(mykeys[i], i, test_resize);
        }
        for (int k: st.keys()) {
            System.out.println(k);
        }
    }
}

class Ficha7{
    public static void main(String[] args) {
        ex2();
    }

    public static void ex2(){
        In in = new In("./data/tinyDG.txt");
        Digraph d = new Digraph(in);
        ArrayList source = new ArrayList();
        source.add(2);
        source.add(6);
        source.add(10);
        BreadthFirstDirectedPaths bfsG = new BreadthFirstDirectedPaths(d, source);

        for (int v = 0; v < d.V(); v++){
            StdOut.print("\n"+v+": ");
            if(bfsG.hasPathTo(v)){
                for (int x: bfsG.pathTo(v)) {
                    StdOut.print(x+" ");
                }
            }
        }
    }
}

class Ficha8{
    public static void main(String[] args) {
        StdOut.println("Ficha8, 26abr2023");
        //ex1();
        test1_graph_wight();
        test1_graph_wight2();
        test1_graph_wight_file();
        teste_eulerian();
    }

    public static void ex1(){
        In in = new In("./data/aed2_aulas/ficha8_ex1_g2.txt");
        EdgeWeightedGraph g1 = new EdgeWeightedGraph(in);
        StdOut.println("Grafo Original:\n"+g1);
        KruskalMST kmst = new KruskalMST(g1);
        StdOut.println("MST (peso total ="+kmst.weight()+"):");
        for (Edge e: kmst.edges()){
            StdOut.println(e);
        }

        PrimMST pmst = new PrimMST(g1);
        StdOut.println("MST (peso total ="+pmst.weight()+"):");
        for (Edge e: pmst.edges()){
            StdOut.println(e);
        }

        LazyPrimMST lpmst = new LazyPrimMST(g1);
        StdOut.println("MST (peso total ="+lpmst.weight()+"):");
        for (Edge e: lpmst.edges()){
            StdOut.println(e);
        }
    }

    public static double exe7(EdgeWeightedGraph g){
        double pesoTotal = 0;
        for (Edge e : g.edges()){
            pesoTotal += e.weight();
        }
        return pesoTotal;
    }
    public static void test1_graph_wight(){
        double pesoTotal=0;
        EdgeWeightedGraph g = new EdgeWeightedGraph(5);
        Edge e1 = new Edge(0,1,2);
        Edge e2 = new Edge(1,2,4);
        Edge e3 = new Edge(2,3,6);
        Edge e4 = new Edge(3,4,8);
        g.addEdge(e1);
        g.addEdge(e2);
        g.addEdge(e3);
        g.addEdge(e4);
        pesoTotal=exe7(g);
        double pesoV1 = exe9(g, 1);
        StdOut.println("Soma do grafo : " + pesoTotal);
        StdOut.println("Soma do grafo no vertice 1 : " + pesoV1);
    }

    public static void test1_graph_wight2(){
        double pesoTotal=0;
        EdgeWeightedGraph g = new EdgeWeightedGraph(4);
        Edge e1 = new Edge(0,1,5);
        Edge e2 = new Edge(0,2,10);
        Edge e3 = new Edge(1,2,15);
        Edge e4 = new Edge(2,3,10);
        g.addEdge(e1);
        g.addEdge(e2);
        g.addEdge(e3);
        g.addEdge(e4);
        pesoTotal=exe7(g);
        StdOut.println("Soma do grafo : " + pesoTotal);
        double pesoV1 = exe9(g, 1);
        StdOut.println("Soma do grafo no vertice 1 : " + pesoV1);
    }

    public static void test1_graph_wight_file(){
        In in = new In("./data/aed2_aulas/wightGrafh.txt");
        EdgeWeightedGraph g = new EdgeWeightedGraph(in);
        double pesoTotal = exe7(g);
        StdOut.println("Soma do grafo: "+pesoTotal);
    }

    public static void teste_eulerian(){
        Graph g = new Graph(8);
        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(0, 3);
        g.addEdge(0, 4);
        g.addEdge(1, 2);
        g.addEdge(1, 3);
        g.addEdge(1, 4);
        g.addEdge(2, 3);
        EulerianPath eulerPath = new EulerianPath(g);
        if(eulerPath.hasEulerianPath()){
            for (Integer v : eulerPath.path()) {
                StdOut.println(v);
            }
        }
    }

    public static double ex8(EdgeWeightedGraph g, int pesoTotal){
        return (double) pesoTotal/g.V();
    }

    public static double exe9(EdgeWeightedGraph g, int v){
        double pesoTotal = 0;
        for (Edge e : g.adj(v)){
            pesoTotal += e.weight();
        }
        return pesoTotal;
    }
}