package Teorica.Bank;

import java.util.Objects;

public abstract class Account implements AccountMoneyI, AccountOwnershipsI {

    public final String accountNumber;
    private double balance;
    private Client owner;

    protected Account(String accountNumber, double balance, Client owner) {
        this.accountNumber = accountNumber;
        this.balance = balance;
        this.owner = owner;
        if(this.owner != null)  owner.addAccount(this);
    }

    public String getAccountNumber() {
        return accountNumber;
    }

    protected double getBalance() {
        return balance;
    }

    protected void setBalance(double balance) {
        this.balance = balance;
    }

    public Client getOwner() {
        return owner;
    }

    public void setOwner(Client owner) {
        this.owner = owner;
    }

    @Override
    public Client getAccountOwner(){
        if(this.owner != null)  return this.owner;
        return null;
    }

    public void setAccountOwner(Client owner){
        if(this.owner == null) {
            this.owner = owner;
            owner.addAccount(this);
        }
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Account account)) return false;
        return Double.compare(account.balance, balance) == 0 && Objects.equals(accountNumber, account.accountNumber) && Objects.equals(owner, account.owner);
    }

    @Override
    public int hashCode() {
        return Objects.hash(accountNumber, balance, owner);
    }

    @Override
    public String toString() {
        return "Account{" +
                "accountNumber='" + accountNumber + '\'' +
                ", balance=" + balance +
                ", owner=" + owner +
                '}';
    }

    public static void main(String[] args){

    }
}
