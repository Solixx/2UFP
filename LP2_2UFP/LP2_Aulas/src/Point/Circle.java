package Point;

import Person.MyMath;
import _05_figgeo.FigGeo;
import edu.princeton.cs.algs4.StdOut;

import java.awt.*;
import java.io.Serializable;

public class Circle extends FigGeo implements Serializable {

    private Point center;
    private Point periferic;

    public Circle(Point center, Point periferic) {
        super();
        this.center = center;
        this.periferic = periferic;
    }
    public Point getCenter() {
        return center;
    }

    public void setCenter(Point center) {
        this.center = center;
    }

    public Point getPeriferic() {
        return periferic;
    }

    public void setPeriferic(Point periferic) {
        this.periferic = periferic;
    }

    public void move(float dx, float dy){
        center.move(dx, dy);
        periferic.move(dx, dy);
    }

    public double area(){
        return 3.14f * ( (float)Math.pow(Math.abs(periferic.dist(center)), 2));
    }

    public double perimeter(){
        return 2 * 3.14f * ( (float)Math.abs(periferic.dist(center)));
    }

    public float radius(){
        return (float)Math.abs(periferic.dist(center));
    }

    public boolean isInside(Point p){
        return this.radius() >= (Math.abs(p.dist(this.center)));
    }

    public boolean isOutside(Point p){
        return !(this.radius() >= (Math.abs(p.dist(this.center))));
    }

    @Override
    public String toString() {
        return "Circle{" +
                "center=" + center +
                ", periferic=" + periferic +
                '}';
    }

    public static void main(String[] args) {
        Point p1 = new Point(2.0f, 1.0f);
        Point p2 = new Point(1.0f, 1.0f);
        Point p3 = new Point(1.0f, 1.0f);
        Circle c = new Circle(p1,p2);

        StdOut.println(c.isOutside(p3));
    }

    @Override
    public void draw(Graphics g) {

    }

    @Override
    public boolean isInside(FigGeo f) {
        return false;
    }

    @Override
    public boolean isInterceptedBy(FigGeo f) {
        return false;
    }
}
