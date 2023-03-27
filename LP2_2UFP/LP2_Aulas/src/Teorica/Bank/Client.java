package Teorica.Bank;

import Person.*;

import java.util.ArrayList;
import java.util.Objects;

public class Client extends Person implements ClientRelationshipsI {
    private String varNumber;
    private ArrayList<Account> accounts = new ArrayList();
    public void addAccount(Account newAccount){
        this.accounts.add(newAccount);
    }
    public void listAccounts(){
        for (Account a : this.accounts) {
            System.out.println(a);
        }
    }

    public Account getAccount(int index){return (Account) this.accounts.get(index);}

    public String getVarNumber() {
        return varNumber;
    }

    public void setVarNumber(String varNumber) {
        this.varNumber = varNumber;
    }

    public ArrayList getAccounts() {
        return accounts;
    }

    public void setAccounts(ArrayList accounts) {
        this.accounts = accounts;
    }

    public Client(String idNumber, String name, String address, Date birth, String varNumber, ArrayList accounts) {
        super(idNumber, name, address, birth);
        this.varNumber = varNumber;
        this.accounts = accounts;
    }

    @Override
    public String toString() {
        return "Client{" +
                "varNumber='" + varNumber + '\'' +
                ", accounts=" + accounts +
                '}';
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Client client)) return false;
        return Objects.equals(varNumber, client.varNumber) && Objects.equals(accounts, client.accounts);
    }

    @Override
    public int hashCode() {
        return Objects.hash(varNumber, accounts);
    }
}