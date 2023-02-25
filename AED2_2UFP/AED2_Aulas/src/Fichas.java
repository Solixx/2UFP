import edu.princeton.cs.algs4.BinarySearchST;
import edu.princeton.cs.algs4.SequentialSearchST;
import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.Out;

import javax.management.openmbean.ArrayType;
import java.lang.reflect.Array;
import java.util.Arrays;

public class Fichas {

    public static void main(String[] args) {
        Ficha1 f1 = new Ficha1();
        f1.ex10(5, 4, 6);
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