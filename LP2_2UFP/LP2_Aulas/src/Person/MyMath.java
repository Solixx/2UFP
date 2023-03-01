package Person;

public class MyMath {

  public double fact_recursive(int n) {

    if(n == 0) return 1.0;
    return n * fact_recursive(n-1);
  }

  public double fact_for(int n) {

    double fact = 1.0;
    for (int i = n; i > 0; i--){
      fact *= i;
    }

    return fact;
  }

  public float fact_while(int n) {

    float fact = 1.0f;
    while (n != 0){
      fact *= n;
      n--;
    }

    return fact;
  }

  public float fact_do_while(int n) {

    float fact = 1.0f;
    do{
      fact *= n;
      n--;
    } while (n != 0);

    return fact;
  }

  public static void main(String[] args) {
    MyMath m = new MyMath();
    System.out.println("Fact: "+ m.fact_recursive(5));
  }

}