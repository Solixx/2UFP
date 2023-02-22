package Person;

public class Date {

  public short day;

  public short month;

  public int year;

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

  public String toString() { return null;}

  public boolean equals(Object o) {
  return false;
  }

  public int hashCode() {
  return 0;
  }

  public int compareTo(Date d) {
  return 0;
  }

  public boolean afterDate(Date d) {
  return false;
  }

  public boolean beforeDate(Date d) {
  return false;
  }

  public int differenceDays(Date d) {
  return 0;
  }

  public int differenceMounths(Date d) {
  return 0;
  }

  public int differenceYears(Date d) {
  return 0;
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

  public void main(String[] args) {
  }

}