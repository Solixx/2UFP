package Teorica.Bank;

public interface AccountMoneyI {

    public double withdraw(double amount);
    public double deposit(double amount);
    public double transfer(AccountMoneyI destination, double amount);
    public double balance();
}
