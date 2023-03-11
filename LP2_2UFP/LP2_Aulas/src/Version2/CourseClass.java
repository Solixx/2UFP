package Version2;
import Person.*;
import java.util.ArrayList;

public class CourseClass {

  private String name;
  private ArrayList  disciplines;

  private ArrayList students;

  public CourseClass(String name, ArrayList disciplines, ArrayList students) {
    this.name = name;
    this.disciplines = disciplines;
    this.students = students;
  }

  @Override
  public String toString() {
    return "CourseClass{" +
            "name='" + name + '\'' +
            ", disciplines=" + disciplines +
            ", students=" + students +
            '}';
  }

  public String getName() {
    return name;
  }

  public void setName(String name) {
    this.name = name;
  }

  public ArrayList getDisciplines() {
    return disciplines;
  }

  public void setDisciplines(ArrayList disciplines) {
    this.disciplines = disciplines;
  }

  public ArrayList getStudents() {
    return students;
  }

  public void setStudents(ArrayList students) {
    this.students = students;
  }

  public ArrayList searchStudent(String name) {
  return null;
  }

  public Student searchStudent(long number) {
  return null;
  }

  public Discipline searchDiscipline(String name) {
  return null;
  }

  public void registerStudent(Student s) {
  }

  public Student unregisterStudent(String sname) {
  return null;
  }

  public void associateDiscipline(Discipline d) {
  }

  public Discipline desassociateDiscipline(String dname) {
  return null;
  }

  public void launchGrade(String disciplineName, long studentNumber, float grade) {
  }

  public void associateGrade2Discipline(String disciplineName, long studentNumber, float grade) {
  }
}