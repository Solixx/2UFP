package GestaoLivros;

import Person.*;

import java.util.ArrayList;

public class Utilizador {

    private String uname;
    private String passwd;
    private ArrayList<Livro> livros;

    public void recebe(Livro l){
        this.livros.add(l);
    }

    public Livro devolve(String t){
        for (Livro l: this.livros) {
            if(l.getTitulo().equals(t)) {
                this.livros.remove(l);
                return l;
            }
        }
        return null;
    }

    public void empresta(Livro l, Utilizador u){
        u.livros.add(l);
        this.livros.remove(l);
    }

    public Utilizador(String uname, String passwd, ArrayList<Livro> livros) {
        this.uname = uname;
        this.passwd = passwd;
        this.livros = livros;
    }

    public String getUname() {
        return uname;
    }

    public void setUname(String uname) {
        this.uname = uname;
    }

    public String getPasswd() {
        return passwd;
    }

    public void setPasswd(String passwd) {
        this.passwd = passwd;
    }

    public ArrayList<Livro> getLivros() {
        return livros;
    }

    public void setLivros(ArrayList<Livro> livros) {
        this.livros = livros;
    }
}
