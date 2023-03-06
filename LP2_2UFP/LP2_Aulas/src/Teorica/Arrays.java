package Teorica;

import Person.MyMath;
import Point.Point;
import edu.princeton.cs.algs4.StdOut;

import java.util.ArrayList;

public class Arrays {

    public static void main(String[] args) {
        //testArrayPrimitive();
        //testArrayObjects();
        testRawArrayLists();
    }

    public static void testArrayPrimitive(){
        int[] arrayInt = new int[10];

        arrayInt[0] = 5;
        for (int i = 0; i < 10; i++){
            arrayInt[i] = i;
            StdOut.println(arrayInt[i]);
        }
        for (int i: arrayInt){
            StdOut.println(i);
        }
    }

    public static void testArrayObjects(){
        Point[] arrayPts = new Point[10];

        arrayPts[0] = new Point(0.0f, 0.0f);
        for (int i = 0; i < arrayPts.length; i++){
            arrayPts[i] = new Point((float) i, (float) i);
            StdOut.println(arrayPts[i].toString());
        }
        for (Point i: arrayPts){
            StdOut.println(i.toString());
        }
    }

    public static void testRawArrayLists(){
        ArrayList arrList = new ArrayList(4);

        arrList.add(new Object());
        arrList.add("ola");
        arrList.add(2, new Point(1.0f, 1.0f));
        arrList.add(3, "ola mundo");
        arrList.set(2, "test");

        for (int i = 0; i < arrList.size(); i++){
            StdOut.println(arrList.get(i));
        }

        for (Object o: arrList){
            StdOut.println(o);
        }
    }
}
