package Version2;
import Person.*;

import java.util.ArrayList;

public class Discipline {

  private String name;

  private int ects;

  private short courseSemester;

  private short courseYear;

  private ArrayList<Grade> grade;

  public Discipline(String name, int ects, short courseSemester, short courseYear, ArrayList<Grade> grade) {
    this.name = name;
    this.ects = ects;
    this.courseSemester = courseSemester;
    this.courseYear = courseYear;
    this.grade = grade;
  }

  @Override
  public String toString() {
    return "Discipline{" +
            "name='" + name + '\'' +
            ", ects=" + ects +
            ", courseSemester=" + courseSemester +
            ", courseYear=" + courseYear +
            ", grade=" + grade +
            '}';
  }

  public String getName() {
    return name;
  }

  public void setName(String name) {
    this.name = name;
  }

  public int getEcts() {
    return ects;
  }

  public void setEcts(int ects) {
    this.ects = ects;
  }

  public short getCourseSemester() {
    return courseSemester;
  }

  public void setCourseSemester(short courseSemester) {
    this.courseSemester = courseSemester;
  }

  public short getCourseYear() {
    return courseYear;
  }

  public void setCourseYear(short courseYear) {
    this.courseYear = courseYear;
  }

  public ArrayList getGrade() {
    return grade;
  }

  public void setGrade(ArrayList grade) {
    this.grade = grade;
  }


  public void associateGrade(Grade g) {
  }
}