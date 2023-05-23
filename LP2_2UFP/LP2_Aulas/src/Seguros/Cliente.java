package Seguros;

import Person.*;

import java.util.ArrayList;

public class Cliente {

    private int nif;
    private String nome;
    private Date nasceu;
    private int carta;
    private Date dataCarta;
    private ArrayList<Apolice> arrApolices;

    public ArrayList<Apolice> apolices(Date di, Date df){
        ArrayList<Apolice> apolics = new ArrayList<>();
        for (Apolice arrApolice : this.arrApolices) {
            if (arrApolice.getDataInit().compareTo(di) == 0 && arrApolice.getDataFim().compareTo(df) == 0)
                apolics.add(arrApolice);
        }
        return apolics;
    }

    //public ArrayList<Apolice> apolices(String type){}

    public Apolice apoliceMaisCara(){
        float max = 0;
        Apolice masCara = this.arrApolices.get(0);
        for (Apolice apol: this.arrApolices){
            if(apol.premio() > max){
                apol.premio();
                masCara = apol;
            }
        }
        return masCara;
    }

    public void novaApolice(Apolice a){
        this.arrApolices.add(a);
    }

    public void revogaApolice(Apolice a){
        this.arrApolices.remove(a);
    }

    public Cliente(int nif, String nome, Date nasceu, int carta, Date dataCarta, ArrayList<Apolice> arrApolices) {
        this.nif = nif;
        this.nome = nome;
        this.nasceu = nasceu;
        this.carta = carta;
        this.dataCarta = dataCarta;
        this.arrApolices = arrApolices;
    }

    public int getNif() {
        return nif;
    }

    public void setNif(int nif) {
        this.nif = nif;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public Date getNasceu() {
        return nasceu;
    }

    public void setNasceu(Date nasceu) {
        this.nasceu = nasceu;
    }

    public int getCarta() {
        return carta;
    }

    public void setCarta(int carta) {
        this.carta = carta;
    }

    public Date getDataCarta() {
        return dataCarta;
    }

    public void setDataCarta(Date dataCarta) {
        this.dataCarta = dataCarta;
    }

    public ArrayList<Apolice> getArrApolices() {
        return arrApolices;
    }

    public void setArrApolices(ArrayList<Apolice> arrApolices) {
        this.arrApolices = arrApolices;
    }
}
