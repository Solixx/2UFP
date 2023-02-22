package Person;

public class Main {

    public static void main(String[] args) {
        Date Data = new Date((short) 12, (short) 1, (short) 2002);
        Person Ps = new Person("1", "Manuel", "Espinho", Data);

        System.out.println(Ps.toString());

        System.out.println("Id: "+Ps.getIdNumber());
        System.out.println("\nNome: "+Ps.getName());
        System.out.println("\nBirth: "+Ps.getBirth());
        System.out.println("\nAddress: "+Ps.getAddress());
    }
}
