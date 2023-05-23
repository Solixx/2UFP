package com.example._06_gui_javafx.bt;

import java.util.ArrayList;

public class Driver {
    private String name;
    private int numPenalties;
    private String driverLicense;
    private boolean isLicenseApprehended;
    private int points;
    private ArrayList<PenaltyFee> Penaltys = new ArrayList<>();
    public Driver(String name,String licenseNumber){

    }
    public void addPoints(int points){

    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getNumPenalties() {
        return numPenalties;
    }

    public void setNumPenalties(int numPenalties) {
        this.numPenalties = numPenalties;
    }

    public String getDriverLicense() {
        return driverLicense;
    }

    public void setDriverLicense(String driverLicense) {
        this.driverLicense = driverLicense;
    }

    public boolean isLicenseApprehended() {
        return isLicenseApprehended;
    }

    public void setLicenseApprehended(boolean licenseApprehended) {
        isLicenseApprehended = licenseApprehended;
    }

    public int getPoints() {
        return points;
    }

    public void setPoints(int points) {
        this.points = points;
    }

    public ArrayList<PenaltyFee> getPenaltys() {
        return Penaltys;
    }

    public void setPenaltys(ArrayList<PenaltyFee> penaltys) {
        Penaltys = penaltys;
    }

    public String getDriversLicense() {
        return null;
    }
}
