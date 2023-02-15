import java.util.Scanner;
import edu.princeton.cs.algs4.StdOut;

public class Main {
    public static void main(String[] args) {
        System.out.println("Hello world!");
        StdOut.println("kdjnhwakhdkadw");
        Person Manuel = new Person();
        Manuel.setName("Manuel");
        Manuel.setData(2002);
        System.out.println("Nome: "+Manuel.getName() + "\nData: "+Manuel.getData()+"\nIdade: "+Manuel.age(Manuel.getData()));

        Scanner myObj = new Scanner(System.in);
        System.out.println("Insira o Nome da Pessoa:");
        Person user = new Person();
        user.setName(myObj.nextLine());
        System.out.println("Insira o Ano da Pessoa:");
        user.setData(myObj.nextInt());
        System.out.println("Nome: "+user.getName() + "\nData: "+user.getData()+"\nIdade: "+user.age(user.getData()));

        Teacher t = new Teacher();
        t.setName("Jose");
        t.setData(1999);
        t.category = 2;
        System.out.println("Nome: "+t.getName() + "\nData: "+t.getData()+"\nIdade: "+t.age(t.getData())+"\nCategoria: "+t.getCategory());
    }
}

class Person {
    private String name;
    private int data;

    public int age(int data){
        return 2023-data;
    }

    public String getName(){
        return this.name;
    }

    public int getData(){
        return this.data;
    }

    public String setName(String name){
        return this.name = name;
    }

    public int setData(int data){
        return this.data = data;
    }
}

class Teacher extends Person {
    int category;

    public int getCategory(){
        return this.category;
    }
}