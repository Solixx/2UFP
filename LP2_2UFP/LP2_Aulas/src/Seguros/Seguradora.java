package Seguros;

import GestaoLivros.Utilizador;
import Person.*;
import edu.princeton.cs.algs4.ST;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;

public class Seguradora {

    private String nome;

    private ST<Integer, Apolice> apolices;

    private ArrayList<Cliente> clientes;

    public Seguradora(String nome, ST<Integer, Apolice> apolices, ArrayList<Cliente> clientes) {
        this.nome = nome;
        this.apolices = apolices;
        this.clientes = clientes;
    }

    public ST<Integer, Apolice> getApolices() {
        return apolices;
    }

    public void setApolices(ST<Integer, Apolice> apolices) {
        this.apolices = apolices;
    }

    public ArrayList<Cliente> getClientes() {
        return clientes;
    }

    public void setClientes(ArrayList<Cliente> clientes) {
        this.clientes = clientes;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public void novoContrato(Apolice a, Cliente c){
        for (Cliente client: this.clientes) {
            if(client.getNif() == c.getNif())   return;
        }
        for (Integer i: this.apolices.keys()){
            if(a.getNumero() == i)  return;
        }

        c.novaApolice(a);
        this.clientes.add(c);
        this.apolices.put(a.getNumero(), a);
    }

    public Apolice procuraApolice(int num){
        for (Integer i: this.apolices.keys()) {
            if(i == num)    return this.apolices.get(i);
        }
        return null;
    }

    public ArrayList<Apolice> procuraApolices(Date data, Date df, int nif){
        ArrayList<Apolice> returnApolices = new ArrayList<>();

        for (Cliente util: this.clientes){
            if(util.getNif() == nif){
                for (Apolice apol: util.getArrApolices()){
                    if(apol.getDataInit().compareTo(data) >= 0 && apol.getDataFim().compareTo(df) <= 0){
                        returnApolices.add(apol);
                    }
                }
                break;
            }
        }

        return returnApolices;
    }

    public Cliente procuraCliente(int nif){
        for (Cliente util: this.clientes){
            if(util.getNif() == nif)    return util;
        }
        return null;
    }

    public Cliente procuraClienteApoliceNum(int apoliceNum){
        for (Cliente util: this.clientes){
            for (Apolice apol: util.getArrApolices()){
                if(apol.getNumero() == apoliceNum)  return util;
            }
        }
        return null;
    }

    public void eliminaContrato(Apolice a, Cliente c){
        c.getArrApolices().remove(a);
        this.apolices.remove(a.getNumero());
    }

    public void saveTxt(){

        PrintWriter pw = null;
        try {
            pw = new PrintWriter(new FileWriter(new File("../../data/Seguradora.txt")));

            pw.println("Apolices:\n");
            for (Integer i: this.apolices.keys()){
                pw.println(this.apolices.get(i));
            }
            for (Cliente client: this.clientes){
                pw.println(client);
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        } finally {
            try{
                if(pw == null){
                    pw.close();
                }
            } catch (Error e){
                throw new RuntimeException();
            }
        }
    }
}
