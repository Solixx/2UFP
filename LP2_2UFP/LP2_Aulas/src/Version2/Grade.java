package Version2;
import Person.*;

public class Grade {

  private float grade;

  private Date date;

  private Discipline discipline;

  private Student student;

  public Grade(float grade, Date date, Discipline discipline, Student student) {
    this.grade = grade;
    this.date = date;
    this.discipline = discipline;
    this.student = student;
  }

  @Override
  public String toString() {
    return "Grade{" +
            "grade=" + grade +
            ", date=" + date +
            ", discipline=" + discipline +
            ", student=" + student +
            '}';
  }

  public float getGrade() {
    return grade;
  }

  public void setGrade(float grade) {
    this.grade = grade;
  }

  public Date getDate() {
    return date;
  }

  public void setDate(Date date) {
    this.date = date;
  }

  public Discipline getDiscipline() {
    return discipline;
  }

  public void setDiscipline(Discipline discipline) {
    this.discipline = discipline;
  }

  public Student getStudent() {
    return student;
  }

  public void setStudent(Student student) {
    this.student = student;
  }

  public Discipline associateDiscipline() {
    return null;
  }

  public void associateDiscipline(Discipline discipline) {
  }

  public Student associateStudent() {
    return null;
  }

  public void associateStudent(Student student) {
  }


}