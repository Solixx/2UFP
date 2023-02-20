import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.Knuth;
import edu.princeton.cs.algs4.Out;
import edu.princeton.cs.algs4.Quick;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Random;

public class Ficha0 {

    public static void main(String[] args){
        //Ex1 ex1 = new Ex1();
        Ex2 ex2 = new Ex2();

        //ex1.ex1_6();
        ex2.ex3();
    }
}

class Ex1 {
    public void ex1_1(){
        In in = new In("./data/8ints.txt");
        int tamanho_lista = in.readInt();
        System.out.println("Tamanho da Lista de inteiros: "+tamanho_lista+"\nConteudo:");
        for (int i = 0; i < tamanho_lista; i++){
            int out = in.readInt();
            System.out.println(out);
        }
    }

    public void ex1_2(){
        In in = new In("./data/30ints.txt");
        int count = 0;
        while (in.hasNextLine()){
            int val = Integer.parseInt(in.readLine());
            System.out.println(val);
            count++;
        }
        System.out.println("Número de Ints: "+count);
    }

    public void ex1_3(){
        int x = 100;
        Out out = new Out("./data/8ints_out.txt");
        In in = new In("./data/8ints.txt");
        int tamanho_lista = in.readInt();
        System.out.println("Tamanho da Lista de inteiros: "+tamanho_lista+"\n");
        out.println(tamanho_lista);
        for(int i = 0; i < tamanho_lista; i++){
            int val = in.readInt();
            val += x;
            out.print(val);
            if(i == tamanho_lista-1) break;
            out.print(" ");
        }
    }

    public void ex1_4(int N){
        Random rand = new Random();
        int[] array = new int[N];
        for (int i = 0; i < N; i++){
            array[i] = rand.nextInt();
            System.out.println(array[i]);
        }
    }

    public void ex1_5(int N){
        Random rand = new Random();
        Comparable[] array = new Comparable[N];
        for (int i = 0; i < N; i++){
            array[i] = rand.nextInt();
            System.out.println(array[i]);
        }
        System.out.println("\n");
        Quick.sort(array);
        for (int i = 0; i < N; i++){
            System.out.println(array[i]);
        }
    }

    public void ex1_6(){
        In in = new In("./data/1Kints.txt");
        In in2 = new In("./data/2Kints.txt");
        In in3 = new In("./data/4Kints.txt");
        In in4 = new In("./data/8Kints.txt");

        int media = 0, soma = 0;

        for (int i = 0; i < 1000; i++){
            if(i == 499) {
                media = in.readInt();
                System.out.println(media);
            } else soma += in.readInt();

        }
        for (int i = 0; i < 2000; i++){
            if(i == 999){
                media = in2.readInt();
                System.out.println(media);
            } else{
                soma += in2.readInt();
            }
        }
        for (int i = 0; i < 4000; i++){
            if(i == 1999) {
                media = in3.readInt();
                System.out.println(media);
            } else{
                soma += in3.readInt();
            }
        }
        for (int i = 0; i < 8000; i++){
            if(i == 3999){
                media = in4.readInt();
                System.out.println(media);
            } else{
                soma += in4.readInt();
            }
        }
        media = soma/15000;
        System.out.println("Final: "+media);

    }
}

class Ex2 {

    public void ex1(){
        In in = new In("./data/250ints.txt");
        Integer[] array = new Integer[250];
        int soma = 0, max = 0;
        for(int i = 0; i < 250; i++){
            array[i] = in.readInt();
        }
        List<Integer> inList = Arrays.asList(array);
        Collections.shuffle(inList);
        //inList.toArray(array);

        for (int i = 0; i < 250; i++){
            soma += inList.get(i);
            if(soma > max) max = soma;
        }

        System.out.println("Max: "+max+"\n");
    }

    public void ex2(){
        In in = new In("./data/250ints.txt");
        Integer[] array = new Integer[250];
        int soma = 0, min = 0, minIndex = 0;
        for(int i = 0; i < 250; i++){
            array[i] = in.readInt();
        }
        List<Integer> inList = Arrays.asList(array);
        Collections.shuffle(inList);
        //inList.toArray(array);

        min = inList.get(0);
        for (int i = 1; i < 250; i++){
            soma += inList.get(i);
            if(soma < min){
                min = soma;
                minIndex = i;
            }
        }

        for (int i = 0; i < minIndex; i++){
            System.out.println("i: "+i+" N: "+inList.get(i));
        }
        System.out.println("\nMin: "+min+"\n");
    }

    public void ex3(){
        In in = new In("./data/250ints.txt");
        Out out = new Out("./data/250ints_max_out.txt");
        Integer[] array = new Integer[250];
        int soma = 0, min = 0, minIndex = 0;
        for(int i = 0; i < 250; i++){
            array[i] = in.readInt();
        }
        List<Integer> inList = Arrays.asList(array);
        Collections.shuffle(inList);
        //inList.toArray(array);

        min = inList.get(0);
        for (int i = 1; i < 250; i++){
            soma += inList.get(i);
            if(soma < min){
                min = soma;
                minIndex = i;
            }
        }
        for (int i = 0; i < minIndex; i++){
            out.println(inList.get(i));
        }

        In in2 = new In("./data/250ints_max_out.txt");
        while (in2.hasNextLine()){
            int val = Integer.parseInt(in2.readLine());
            System.out.println(val);
        }
    }
}
