package GestaoLivros;

import java.util.ArrayList;

public class Sessao {

    private BD gl;

    public void adicionaLivro(Livro b){
        this.gl.add(b);
    }

    public ArrayList<Livro> procuraLivros(String t, String a){
        return this.gl.procuraLivros(t,a);
    }

    public void requisitaLivro(Livro l, String u){
        if(!l.requisitado()){
            for (Utilizador util: this.gl.getUtilizadores()) {
                if(util.getUname().equals(u)){
                    util.recebe(l);
                    l.setUtilizador(util);
                }
            }
        }
    }

    public void esprestaLivro(Livro l, String u1, String u2){
        if(l.requisitado()){
            for (Utilizador util1: this.gl.getUtilizadores()) {
                if(util1.getUname().equals(u1)){
                    for (Utilizador util2: this.gl.getUtilizadores()) {
                        if(util2.getUname().equals(u2)){
                            util1.empresta(l, util2);
                        }
                    }
                }
            }
        }
    }

    public Sessao(BD gl) {
        this.gl = gl;
    }
}
