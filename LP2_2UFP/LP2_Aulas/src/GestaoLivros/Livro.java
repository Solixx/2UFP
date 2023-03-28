package GestaoLivros;

import Person.*;

import java.util.ArrayList;

public class Livro {

    private String titulo;
    private ArrayList<String> autores;
    private Date publicacao;
    private Utilizador utilizador;

    public boolean requisitado(){
        return this.getUtilizador() != null;
    }

    public Livro(String titulo, ArrayList<String> autores, Date publicacao) {
        this.titulo = titulo;
        this.autores = autores;
        this.publicacao = publicacao;
    }

    public String getTitulo() {
        return titulo;
    }

    public void setTitulo(String titulo) {
        this.titulo = titulo;
    }

    public ArrayList<String> getAutores() {
        return autores;
    }

    public void setAutores(ArrayList<String> autores) {
        this.autores = autores;
    }

    public Date getPublicacao() {
        return publicacao;
    }

    public void setPublicacao(Date publicacao) {
        this.publicacao = publicacao;
    }

    public Utilizador getUtilizador() {
        return utilizador;
    }

    public void setUtilizador(Utilizador utilizador) {
        this.utilizador = utilizador;
    }
}
