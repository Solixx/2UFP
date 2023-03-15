package _05_figgeo;

import java.awt.*;
import java.util.ArrayList;

public abstract class FigGeo implements FigGeoDrawl, FigGeoDiml, FigGeoRelsl {

  public Color color;
  public ArrayList<Point> pontos;

    /**
   *
   * @element-type Point
   */
  public ArrayList<Point> points;

  public FigGeo() {
  }

  public FigGeo(Color c) {
  }

  public void addPoint(Point p) {
  }

  public Point getPoint(int index) {
  return null;
  }

  public Color getColor() {
  return null;
  }

  public void setColor(Color color) {
  }
}