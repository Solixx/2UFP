package Teorica.Bank;

import Teorica.Exceptions.IllicitDespositExecption;
import Teorica.Exceptions.OverWithdrawExecption;

public class AccountUnsafe extends Account {

    protected AccountUnsafe(String accountNumber, double balance, Client owner) {
        super(accountNumber, balance, owner);
    }

    @Override
    public double withdraw(double amount) {
        super.setBalance(super.getBalance() - amount);
        return super.getBalance();
    }

    @Override
    public double deposit(double amount) {
        super.setBalance(super.getBalance() + amount);
        return super.getBalance();
    }

    @Override
    public double transfer(AccountMoneyI destination, double amount) throws OverWithdrawExecption, IllicitDespositExecption {
        double b = this.withdraw(amount);
        destination.deposit(amount);
        return b;
    }

    @Override
    public double balance() {
        return getBalance();
    }

    @Override
    public Client getAccountOwner() {
        return null;
    }

    @Override
    public void setAccountOwner(Client owner) {

    }
}
