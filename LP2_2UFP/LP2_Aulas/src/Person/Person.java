package Person;

public class Person {

  private String idNumber;

  private String name;

  private String address;

  private Date birth;

  public String getIdNumber() {
    return idNumber;
  }

  public void setIdNumber(String idNumber) {
    this.idNumber = idNumber;
  }

  public void setName(String name) {
    this.name = name;
  }

  public void setAddress(String address) {
    this.address = address;
  }

  public void setBirth(Date birth) {
    this.birth = birth;
  }

  public String getName() {
    return name;
  }

  public String getAddress() {
    return address;
  }

  public Date getBirth() {
    return birth;
  }

  public Person(String idNumber, String name, String address, Date birth) {
    this.idNumber = idNumber;
    this.name = name;
    this.address = address;
    this.birth = birth;
  }

  public int age() {
    return 2023 - this.birth.getYear();
  }

  public boolean olderThan(Person p) {

    return this.birth.beforeDate(p.birth);
  }

  @Override
  public String toString() {
    return "Person{" +
            "idNumber='" + idNumber + '\'' +
            ", name='" + name + '\'' +
            ", address='" + address + '\'' +
            ", birth=" + birth +
            '}';
  }

  public boolean equals(Object o) {
  return false;
  }

  public int hashCode() {
  return 0;
  }

  public static void main(String[] args) {

  }
}