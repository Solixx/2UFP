package com.example._06_gui_javafx.bt;

import java.util.ArrayList;

public class Vehicle {
    private String registration;
    private String brand;
    private String model;
    private int cilinders;
    private ArrayList<PenaltyFee> Penaltys = new ArrayList<>();

    public Vehicle(String registration, String brand, String model, int cilinders, ArrayList<PenaltyFee> penaltys) {
        this.registration = registration;
        this.brand = brand;
        this.model = model;
        this.cilinders = cilinders;
        Penaltys = penaltys;
    }

    public String getRegistration() {
        return registration;
    }

    public void setRegistration(String registration) {
        this.registration = registration;
    }

    public String getBrand() {
        return brand;
    }

    public void setBrand(String brand) {
        this.brand = brand;
    }

    public String getModel() {
        return model;
    }

    public void setModel(String model) {
        this.model = model;
    }

    public int getCilinders() {
        return cilinders;
    }

    public void setCilinders(int cilinders) {
        this.cilinders = cilinders;
    }

    public ArrayList<PenaltyFee> getPenaltys() {
        return Penaltys;
    }

    public void setPenaltys(ArrayList<PenaltyFee> penaltys) {
        Penaltys = penaltys;
    }

    public void setCylinders(Integer newValue) {
    }

    @Override
    public String toString() {
        return "Vehicle{" +
                "registration='" + registration + '\'' +
                ", brand='" + brand + '\'' +
                ", model='" + model + '\'' +
                ", cilinders=" + cilinders +
                ", Penaltys=" + Penaltys +
                '}';
    }
}
