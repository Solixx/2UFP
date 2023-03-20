package Teorica.Bank;

public class AccountSafe extends Account{

    protected AccountSafe(String accountNumber, double balance, Client owner) {
        super(accountNumber, balance, owner);
    }

    @Override
    public double withdraw(double amount) {
        return 0;
    }

    @Override
    public double deposit(double amount) {
        return 0;
    }

    @Override
    public double transfer(AccountMoneyI destination, double amount) {
        return 0;
    }

    @Override
    public double balance() {
        return 0;
    }

    @Override
    public Client getAccountOwner() {
        return null;
    }

    @Override
    public void setAccountOwner(Client owner) {

    }
}
