package Point;

import _05_figgeo.FigGeo;

import java.awt.*;

public class Triangle extends FigGeo {

    private Point upperpt;
    private Point lowerleftpt;
    private Point lowerrightpt;

    public Triangle(Point upperpt, Point lowerleftpt, Point lowerrightpt) {
        super();
        this.upperpt = upperpt;
        this.lowerleftpt = lowerleftpt;
        this.lowerrightpt = lowerrightpt;
    }

    public Point getUpperpt() {
        return upperpt;
    }

    public void setUpperpt(Point upperpt) {
        this.upperpt = upperpt;
    }

    public Point getLowerleftpt() {
        return lowerleftpt;
    }

    public void setLowerleftpt(Point lowerleftpt) {
        this.lowerleftpt = lowerleftpt;
    }

    public Point getLowerrightpt() {
        return lowerrightpt;
    }

    public void setLowerrightpt(Point lowerrightpt) {
        this.lowerrightpt = lowerrightpt;
    }

    public void move(float dx, float dy, float dz){
        upperpt.move(dx, dy);
        lowerleftpt.move(dx, dy);
        lowerrightpt.move(dx, dy);
    }

    public double area(){
        return (Math.abs(lowerrightpt.getX() - lowerleftpt.getX()))/2;
    }

    @Override
    public double perimeter() {
        return 0;
    }

    public static void main(String[] args) {

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