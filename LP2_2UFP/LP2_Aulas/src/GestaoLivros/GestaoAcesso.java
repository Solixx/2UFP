package GestaoLivros;

import Person.Date;
import edu.princeton.cs.algs4.StdOut;

import java.util.ArrayList;

public class GestaoAcesso {
    private BD gu;

    public boolean registo(Utilizador u){
        this.gu.regista(u);
        return true;
    }

    public Sessao login(Utilizador u){
        if(this.gu.existe(u)){
            return new Sessao(gu);
        }
        return null;
    }

    public GestaoAcesso(BD gu) {
        this.gu = gu;
    }

    public static void main(String[] args) {
        Date d = new Date((short) 1, (short) 1, (short)1);
        BD bd = new BD(new ArrayList<Utilizador>(), new ArrayList<Livro>());
        Utilizador u1 = new Utilizador("t", "t", new ArrayList<Livro>());
        Utilizador u2 = new Utilizador("a", "a", new ArrayList<Livro>());
        bd.regista(u1);
        bd.regista(u2);
        GestaoAcesso ga = new GestaoAcesso(bd);
        Sessao s1 = ga.login(u1);

        ArrayList<String> autores = new ArrayList<>(2);
        autores.add("Jose");
        autores.add("dhaiujdhawoi");
        Livro l1 = new Livro("a1", autores, d);
        Livro l2 = new Livro("b1", autores, d);
        Livro l3 = new Livro("c1", autores, d);
        ArrayList<Livro> arrL = new ArrayList<Livro>();
        arrL.add(l1);
        arrL.add(l2);
        arrL.add(l3);

        for (int i = 0; i < arrL.size(); i++){
            s1.adicionaLivro(l1);
        }
        s1.procuraLivros(l1.getTitulo(), l1.getAutores().get(0));
        s1.requisitaLivro(l1, u1.getUname());

        StdOut.println(s1.procuraLivros(l1.getTitulo(), l1.getAutores().get(0)));
        s1.esprestaLivro(l1, u1.getUname(), u2.getUname());
    }
}
