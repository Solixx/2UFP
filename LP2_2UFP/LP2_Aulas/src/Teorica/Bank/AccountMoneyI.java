package Teorica.Bank;

import Teorica.Exceptions.IllicitDespositExecption;
import Teorica.Exceptions.OverWithdrawExecption;

public interface AccountMoneyI {

    public double withdraw(double amount) throws OverWithdrawExecption;
    public double deposit(double amount) throws IllicitDespositExecption;
    public double transfer(AccountMoneyI destination, double amount) throws OverWithdrawExecption, IllicitDespositExecption;
    public double balance();
}
