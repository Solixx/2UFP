package Point;

import Person.MyMath;
import edu.princeton.cs.algs4.StdOut;

public class Circle {

    private Point center;
    private Point periferic;

    public Circle(Point center, Point periferic) {
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

    public float area(){
        return 3.14f * ( (float)Math.pow(Math.abs(periferic.dist(center)), 2));
    }

    public float perimeter(){
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
}
