package Seguros;

import Person.*;

public class Apolice {

    private int numero;
    private Date dataInit;
    private Date dataFim;
    private float cobertura;
    private float premioBase;
    private Cliente cliente;

    public float premio(){
        return this.premioBase;
    }
    public Apolice(int numero, Date dataInit, Date dataFim, float cobertura, float premioBase) {
        this.numero = numero;
        this.dataInit = dataInit;
        this.dataFim = dataFim;
        this.cobertura = cobertura;
        this.premioBase = premioBase;
    }

    public int getNumero() {
        return numero;
    }

    public void setNumero(int numero) {
        this.numero = numero;
    }

    public Date getDataInit() {
        return dataInit;
    }

    public void setDataInit(Date dataInit) {
        this.dataInit = dataInit;
    }

    public Date getDataFim() {
        return dataFim;
    }

    public void setDataFim(Date dataFim) {
        this.dataFim = dataFim;
    }

    public float getCobertura() {
        return cobertura;
    }

    public void setCobertura(float cobertura) {
        this.cobertura = cobertura;
    }

    public float getPremioBase() {
        return premioBase;
    }

    public void setPremioBase(float premioBase) {
        this.premioBase = premioBase;
    }
}
