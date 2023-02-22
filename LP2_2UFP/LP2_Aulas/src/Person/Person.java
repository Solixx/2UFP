package Person;

public class Person {

  public String idNumber;

  public String name;

  public String address;

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

  public void setBirth(Person.Date birth) {
    this.birth = birth;
  }

  public String getName() {
    return name;
  }

  public String getAddress() {
    return address;
  }

  public Person.Date getBirth() {
    return birth;
  }

  public Date birth;

  public Person(String idNumber, String name, String address, Person.Date birth) {
    this.idNumber = idNumber;
    this.name = name;
    this.address = address;
    this.birth = birth;
  }

  public int age() {
  return 0;
  }

  public boolean olderThan(Person p) {
  return false;
  }

  public String toString() {
  return null;
  }

  public boolean equals(Object o) {
  return false;
  }

  public int hashCode() {
  return 0;
  }

}