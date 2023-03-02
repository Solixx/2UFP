package Point;

public class Triangle {

    private Point upperpt;
    private Point lowerleftpt;
    private Point lowerrightpt;

    public Triangle(Point upperpt, Point lowerleftpt, Point lowerrightpt) {
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

    public static void main(String[] args) {

    }
}