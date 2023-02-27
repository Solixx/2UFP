package Point;
import java.util.*;

public class Point {
    private float x;
    private float y;

    public Point(float x, float y) {
        this.x = x;
        this.y = y;
    }

    public float getX() {
        return x;
    }

    public void setX(float x) {
        this.x = x;
    }

    public float getY() {
        return y;
    }

    public void setY(float y) {
        this.y = y;
    }

    @Override
    public String toString() {
        return "Point{" +
                "x=" + x +
                ", y=" + y +
                '}';
    }

    public float distX(Point p){
        return this.x - p.x;
    }

    public float distY(Point p){
        return this.y - p.y;
    }

    public float dist(Point p){
        float dx = this.distX(p);
        float dy = this.distY(p);

        return (float) Math.sqrt(dx*dx + dy*dy);
    }

    public void moveX(float dx){
        this.x += dx;
    }

    public void moveY(float dy){
        this.y += dy;
    }

    public void move(float dx, float dy){
        this.moveX(dx);
        this.moveY(dy);
    }

    public void printPoint(){
        System.out.println("x: "+this.x+" y: "+this.y);
    }

    public boolean betweenPointX(Point leftPt, Point rightPt){
        return this.x > leftPt.x && this.x < rightPt.x;
    }

    public boolean betweenPointY(Point leftPt, Point rightPt){
        return this.y > leftPt.y && this.y < rightPt.y;
    }

    public boolean betweenPoint(Point leftPt, Point rightPt){
        return this.betweenPointX(leftPt, rightPt) && this.betweenPointY(leftPt, rightPt);
    }
    public static void main(String[] args) {
        Point p1 = new Point(1.0f, 2.0f);
        Point p2 = new Point(2.0f, 1.0f);
        Point p3 = new Point(1.5f, 1.5f);

        System.out.println(p3.betweenPoint(p1, p2));
    }
}
