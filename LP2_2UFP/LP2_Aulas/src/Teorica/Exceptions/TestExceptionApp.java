package Teorica.Exceptions;

import edu.princeton.cs.algs4.StdOut;

public class TestExceptionApp {

    public static void main(String[] args) {
        String[] astr = {"um", "dois", "tres"};
        try {
            for (int i = 0; i < 4; i++){
                StdOut.println(astr[i]);
            }
        } catch (Exception e){
            e.printStackTrace();
            StdOut.println(e.toString());
        } finally {

        }
    }
}
