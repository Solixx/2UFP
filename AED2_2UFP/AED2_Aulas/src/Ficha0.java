import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.Out;

public class Ficha0 {

    public static void main(String[] args){
        Ex1 ex1 = new Ex1();
        ex1.ex1_3();
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
}
