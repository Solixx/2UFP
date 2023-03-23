package Version2;
import Person.Date;

import java.util.ArrayList;

public class CourseClass {

  private String name;
  private ArrayList<Discipline> disciplines;

  private ArrayList<Student> students;

  public CourseClass(String name, ArrayList<Discipline> disciplines, ArrayList<Student> students) {
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
    this.students.add(s);
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


  public static void main(String[] args) {

    ArrayList<Grade> arrGrade = new ArrayList<>();
    ArrayList<Discipline> arrDisciplinas = new ArrayList<>();
    ArrayList<Student> arrStudents = new ArrayList<>();
    //ArrayList<CourseClass> arrCC = new ArrayList<>();
    Date data0 = new Date((short) 0, (short) 0, (short) 0);
    CourseClass CC = new CourseClass("Engenharia", arrDisciplinas, arrStudents);
    Student s0 = new Student("1", "Manuel", "Espinho", data0, 647816, data0, "m@gmail.com", "1234556", CC, arrGrade);
    Discipline disciplina = new Discipline("LP2", 7, (short) 2, (short) 2, arrGrade);
    Grade grade0 = new Grade(20f, data0, disciplina, s0);

    CC.registerStudent(s0);

    for (Object obj : CC.getStudents()) {
      Student s = (Student) obj;
      // print the information of the Student object
      System.out.println("Student Name: " + s.getName());
      System.out.println("Registration Date: " + s.getRegistration());
      System.out.println("Email: " + s.getEmail());
      System.out.println("CourseClass: " + s.getCourseClass().getName());
      System.out.println("Number of Grades: " + s.getGrades().size());
    }
  }
}