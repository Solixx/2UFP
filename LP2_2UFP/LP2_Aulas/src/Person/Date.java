package Person;

import java.io.Serializable;

public class Date implements Serializable {

  private short day;

  private short month;

  private int year;

  public short getDay() {
    return day;
  }

  public void setDay(short day) {
    this.day = day;
  }

  public void setMonth(short month) {
    this.month = month;
  }

  public void setYear(int year) {
    this.year = year;
  }

  public short getMonth() {
    return month;
  }

  public int getYear() {
    return year;
  }

  public Date(short day, short month, int year) {
    this.day = day;
    this.month = month;
    this.year = year;
  }

  @Override
  public String toString() {
    return "Date{" +
            "day=" + day +
            ", month=" + month +
            ", year=" + year +
            '}';
  }

  public boolean equals(Object o) {
  return false;
  }

  public int hashCode() {
  return 0;
  }

  public int compareTo(Date d) {
    if(d.getDay() == this.getDay() && d.getMonth() == this.getMonth() && d.getYear() == this.getYear()) return 0;
    else {
      if(this.afterDate(d)) return 1;
      else                  return -1;
    }
  }

  public boolean afterDate(Date d) {
    if(d.getYear() < this.getYear()) return true;
    else if (d.getYear() > this.getYear()) return false;
    else {
      if(d.getMonth() < this.getMonth()) return true;
      else if(d.getMonth() > this.getMonth()) return false;
      else{
        if(d.getDay() >= this.getDay()) return false;
        return d.getDay() < this.getDay();
      }
    }
  }

  public boolean beforeDate(Date d) {

    if(d.getYear() > this.getYear()) return true;
    else if (d.getYear() < this.getYear()) return false;
    else {
      if(d.getMonth() > this.getMonth()) return true;
      else if(d.getMonth() < this.getMonth()) return false;
      else{
        if(d.getDay() <= this.getDay()) return false;
        return d.getDay() > this.getDay();
      }
    }
  }

  public int differenceDays(Date d) {

    return d.getDay() - this.getDay();
  }

  public int differenceMounths(Date d) {

    return d.getMonth() - this.getMonth();
  }

  public int differenceYears(Date d) {

    return d.getYear() - this.getYear();
  }

  public void incrementDate() {
  }

  public long daysCrawlerRecursiveAux(Date begin, Date end) {
  return 0;
  }

  public int daysCrawlerRecursive(Date begin, Date end) {
  return 0;
  }

  public int daysCrawler(Date begin, Date end) {
  return 0;
  }

  public int mounthsCrawler(Date begin, Date end) {
  return 0;
  }

  public boolean isLeapYear(int year) {
  return false;
  }

  public int daysMounth(short mounth, int year) {
  return 0;
  }

  private int daysBetweenMounths(short beginDay, short beginMounth, short endDay, short endMounth, int year) {
  return 0;
  }

  public int mounthsBetweenMounths(short beginDay, short beginMounth, short endDay, short endMounth, int year) {
  return 0;
  }

  public static void main(String[] args) {
    Date Data = new Date((short) 12, (short) 1, (short) 2002);
    Date Data2 = new Date((short) 11, (short) 2, (short) 2002);

    System.out.println("Compare Datas: "+Data.compareTo(Data2));
    System.out.println("After Datas: "+Data.afterDate(Data2));
    System.out.println("Before Datas: "+Data.beforeDate(Data2));
  }

}