package Person;

public class Main {

    public static void main(String[] args) {
        Date Data = new Date((short) 12, (short) 1, (short) 2002);
        Date Data2 = new Date((short) 11, (short) 2, (short) 2002);
        Person Ps = new Person("1", "Manuel", "Espinho", Data);

        System.out.println(Ps.toString());

        System.out.println("Id: "+Ps.getIdNumber());
        System.out.println("Nome: "+Ps.getName());
        System.out.println("Birth: "+Ps.getBirth());
        System.out.println("Address: "+Ps.getAddress());

        System.out.println("Compare Datas: "+Data.compareTo(Data2));
    }
}
