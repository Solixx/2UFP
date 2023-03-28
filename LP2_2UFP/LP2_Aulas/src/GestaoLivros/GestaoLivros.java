package GestaoLivros;

import java.util.ArrayList;

public interface GestaoLivros {

    public void add(Livro l);
    public Livro procuraLivro(String  t);
    public ArrayList<Livro> procuraLivros(String t, String a);
}
