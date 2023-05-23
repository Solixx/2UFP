package Seguros;

import Person.*;
public class ApoliceCasa extends Apolice{

    private String endreco;
    private Date construcao;
    private float area;

    public ApoliceCasa(int numero, Date dataInit, Date dataFim, float cobertura, float premioBase) {
        super(numero, dataInit, dataFim, cobertura, premioBase);
    }

    public String getEndreco() {
        return endreco;
    }

    public void setEndreco(String endreco) {
        this.endreco = endreco;
    }

    public Date getConbstrucao() {
        return construcao;
    }

    public void setConbstrucao(Date conbstrucao) {
        this.construcao = conbstrucao;
    }

    public float getArea() {
        return area;
    }

    public void setArea(float area) {
        this.area = area;
    }

    @Override
    public float premio() {
        return (super.premio()+(this.area*0.05f+(super.getDataInit().getYear()-super.getDataFim().getYear())*0.1f));
    }
}
