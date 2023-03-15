package Version2;
import Person.*;

import java.util.ArrayList;

public class Student extends Person{

  private long number;

  private Date registration;

  private String email;

  private String password;

    private CourseClass courseClass;

  private ArrayList grades;
    private ArrayList  has;


  public Student(String idNumber, String name, String address, Date birth, long number, Date registration, String email, String password, CourseClass courseClass, ArrayList grades, ArrayList has) {
    super(idNumber, name, address, birth);
    this.number = number;
    this.registration = registration;
    this.email = email;
    this.password = password;
    this.courseClass = courseClass;
    this.grades = grades;
    this.has = has;
  }

  @Override
  public String toString() {
    return "Student{" +
            "number=" + number +
            ", registration=" + registration +
            ", email='" + email + '\'' +
            ", password='" + password + '\'' +
            ", courseClass=" + courseClass +
            ", grades=" + grades +
            ", has=" + has +
            '}';
  }

  public String getEmail() {
    return email;
  }

  public void setEmail(String email) {
    this.email = email;
  }

  public String getPassword() {
    return password;
  }

  public void setPassword(String password) {
    this.password = password;
  }

  public CourseClass getCourseClass() {
    return courseClass;
  }

  public void setCourseClass(CourseClass courseClass) {
    this.courseClass = courseClass;
  }

  public ArrayList getGrades() {
    return grades;
  }

  public void setGrades(ArrayList grades) {
    this.grades = grades;
  }

  public ArrayList getHas() {
    return has;
  }

  public void setHas(ArrayList has) {
    this.has = has;
  }

  public void addGrade(Grade g) {
  }

  public Grade removeGrade(float g, String nd, Date d) {

    int i = 0;
    for (Object grades:
         this.grades) {
          Grade grade = (Grade) grades;
          if(grade.getGrade() == g && grade.getDiscipline().getName().equals(nd) && grade.getDate().equals(d)) this.grades.remove(i);
          i++;
    }

    return null;
  }

  public Grade changeGrade(float ng, float g, String nd, Date d) {
  return null;
  }

  public Grade searchGrade(float g, String nd, Date d) {
  return null;
  }

  public float averageGrades() {
  return 0.0f;
  }

  public Grade maxGrade() {
  return null;
  }

  public Grade minGrade() {
  return null;
  }

  public void registerInCourseClass(CourseClass cc) {
  }

  public CourseClass unregisterFromCourseClass() {
  return null;
  }

  public long getNumber() {
    return number;
  }

  public void setNumber(long number) {
    this.number = number;
  }

  public Date getRegistration() {
    return registration;
  }

  public void setRegistration(Date registration) {
    this.registration = registration;
  }
}