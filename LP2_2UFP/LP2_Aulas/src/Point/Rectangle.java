package Point;

import _05_figgeo.FigGeo;
import edu.princeton.cs.algs4.StdOut;

import java.awt.*;

public class Rectangle extends FigGeo {

    private Point ulc;
    private Point lrc;

    public Point getUlc() {
        return ulc;
    }

    public void setUlc(Point ulc) {
        this.ulc = ulc;
    }

    public Point getLrc() {
        return lrc;
    }

    public void setLrc(Point lrc) {
        this.lrc = lrc;
    }

    public void move(float dx, float dy){
        ulc.move(dx, dy);
        lrc.move(dx, dy);
    }

    public Rectangle(Point ulc, Point lrc) {
        super();
        this.ulc = ulc;
        this.lrc = lrc;
    }

    public double area(){
        return (Math.abs(ulc.getX() - lrc.getX())) * (Math.abs(ulc.getY() - lrc.getY()));
    }

    public double perimeter(){
        return (Math.abs(ulc.getX() - lrc.getX()) * 2) + (Math.abs(ulc.getY() - lrc.getY()) * 2);
    }

    public boolean isInside(Point p){
        if((p.getX() > ulc.getX() && p.getX() < lrc.getX())){
            return (p.getY() < ulc.getY() && p.getY() > lrc.getY());
        }   return false;
    }

    public boolean isOutside(Point p){
        if((p.getX() > ulc.getX() && p.getX() < lrc.getX())){
            return (!(p.getY() < ulc.getY()) || !(p.getY() > lrc.getY()));
        } return true;
    }

    @Override
    public String toString() {
        return "Rectangle{" +
                "ulc=" + ulc +
                ", lrc=" + lrc +
                '}';
    }

    public static void main(String[] args) {
        Point p1 = new Point(1.0f, 2.0f);
        Point p2 = new Point(2.0f, 1.0f);
        Point p3 = new Point(2.5f, 1.5f);
        Rectangle r = new Rectangle(p1, p2);

        StdOut.println(r.isInside(p3));
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
