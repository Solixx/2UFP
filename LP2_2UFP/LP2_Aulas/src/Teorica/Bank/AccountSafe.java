package Teorica.Bank;

public class AccountSafe extends Account{

    public AccountSafe(String accountNumber, double balance, Client owner) {
        super(accountNumber, balance, owner);
    }

    public double withdraw(double amount){
        if(super.getBalance()>=amount){
            super.setBalance(super.getBalance()-amount);
        }
        return super.getBalance();
    }
    public double deposit(double amount){
        if(amount>0){
            super.setBalance(super.getBalance()+amount);
        }
        return super.getBalance();
    }
    public double balance(){
        return getBalance();
    }
    public double transfer(AccountMoneyI destination,double amount){
        double prevBalance= getBalance();
        double b= withdraw(amount);
        if(prevBalance > b){
            destination.deposit(amount);
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
}
