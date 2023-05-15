package Teorica.Files;

import Person.*;
import Point.Point;
import Point.*;

import java.awt.*;
import java.io.*;


public class FileObjectOutputStream {

    public static void main(String[] args) {
        try(ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream("data/Data.bin"))) {

            String msg = "Todays Date";
            Date today = new Date((short) 15, (short) 5, 2023);
            Point p = new Point(10f, 10f);
            Circle c = new Circle(p, p);

            oos.writeObject(msg);
            oos.writeObject(today);
            oos.writeObject(p);
            oos.writeObject(c);

        } catch (IOException e){

        }
    }
}
