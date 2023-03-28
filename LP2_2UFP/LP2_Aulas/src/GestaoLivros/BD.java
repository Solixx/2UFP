package GestaoLivros;

import java.util.ArrayList;

public class BD implements GestaoUtilizadores, GestaoLivros{

    private ArrayList<Utilizador> utilizadores;
    private ArrayList<Livro> livros;

    @Override
    public void add(Livro l) {
        this.livros.add(l);
    }

    @Override
    public Livro procuraLivro(String t) {
        for (Livro l: this.livros) {
            if(l.getTitulo().equals(t)) return l;
        }
        return null;
    }

    @Override
    public ArrayList<Livro> procuraLivros(String t, String a) {
        ArrayList<Livro> livros = new ArrayList<Livro>();
        for (Livro l: this.livros) {
            if(l.getTitulo().equals(t)){
                for (String autor: l.getAutores()) {
                    if(autor.equals(a)) livros.add(l);
                }
            }
        }
        if(livros.isEmpty()){
            return null;
        }
        return livros;
    }

    @Override
    public void regista(Utilizador u) {
        this.utilizadores.add(u);
    }

    @Override
    public boolean existe(Utilizador u) {
        if(this.utilizadores == null)   return false;
        for (Utilizador util: this.utilizadores) {
            if(util.equals(u))  return true;
        }
        return false;
    }

    public BD(ArrayList<Utilizador> utilizadores, ArrayList<Livro> livros) {
        this.utilizadores = utilizadores;
        this.livros = livros;
    }

    public ArrayList<Utilizador> getUtilizadores() {
        return utilizadores;
    }

    public void setUtilizadores(ArrayList<Utilizador> utilizadores) {
        this.utilizadores = utilizadores;
    }

    public ArrayList<Livro> getLivros() {
        return livros;
    }

    public void setLivros(ArrayList<Livro> livros) {
        this.livros = livros;
    }
}
