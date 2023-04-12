package Teorica.Bank;

import Person.Date;
import Teorica.Exceptions.IllicitDespositExecption;
import Teorica.Exceptions.OverWithdrawExecption;

import edu.princeton.cs.algs4.*;

import java.util.*;

public class AccountSafe extends Account implements AccountMoneyI{

    public AccountSafe(String accountNumber, double balance, Client owner) {
        super(accountNumber, balance, owner);
    }

    public double withdraw(double amount) throws OverWithdrawExecption {
        if(super.getBalance()>=amount){
            super.setBalance(super.getBalance()-amount);
            return super.getBalance();
        } else{
            throw new OverWithdrawExecption("Nao tem dinheiro suficiente para levantar\n");
        }
    }
    public double deposit(double amount) throws IllicitDespositExecption {
        if(amount>0){
            super.setBalance(super.getBalance()+amount);
        }
        return super.getBalance();
    }
    public double balance(){
        return getBalance();
    }
    public double transfer(AccountMoneyI destination,double amount) throws OverWithdrawExecption, IllicitDespositExecption{
        double prevBalance= getBalance();
        double b = withdraw(amount);
        if(prevBalance > b){
            try {
                destination.deposit(amount);
            } catch (IllicitDespositExecption e) {
                throw new RuntimeException(e);
            }
        }
        return this.balance();
    }

    @Override
    public Client getAccountOwner() {
        return null;
    }

    @Override
    public void setAccountOwner(Client owner) {

    }

    public static void main(String[] args){
        ArrayList<Account> arr1 = new ArrayList();
        Client p1= new Client("1","Rui","Rua",new Date((short)1,(short)1,(short)1),"32",arr1);
        AccountSafe a1 = new AccountSafe("Rui",10000,p1);
        try{
            a1.withdraw(100.0);
            a1.deposit(10.0);
        }catch (OverWithdrawExecption owe){
            StdOut.println(owe);
        }
        catch (IllicitDespositExecption ide){
            StdOut.println(ide);
        }
        catch (Exception e){
            StdOut.println(e);
        }
        finally {

        }
    }
}
