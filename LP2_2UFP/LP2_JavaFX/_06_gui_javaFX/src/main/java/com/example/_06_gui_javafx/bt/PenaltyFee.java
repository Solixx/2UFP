package com.example._06_gui_javafx.bt;

import java.util.*;

public abstract class PenaltyFee implements Offense {
    private String  motive;
    private String  local;
    private final float MIN_VALUE;
    private final float MIN_PUNISHMENT;
    private Date date;

    private Driver driver;

    private Vehicle vehicle;

    public PenaltyFee(String motive, String local, float MIN_VALUE, float MIN_PUNISHMENT, Date date) {
        this.motive = motive;
        this.local = local;
        this.MIN_VALUE = MIN_VALUE;
        this.MIN_PUNISHMENT = MIN_PUNISHMENT;
        this.date = date;
    }

    public String getMotive() {
        return motive;
    }

    public void setMotive(String motive) {
        this.motive = motive;
    }

    public String getLocal() {
        return local;
    }

    public void setLocal(String local) {
        this.local = local;
    }

    public float getMIN_VALUE() {
        return MIN_VALUE;
    }

    public float getMIN_PUNISHMENT() {
        return MIN_PUNISHMENT;
    }

    public Date getDate() {
        return date;
    }

    public void setDate(Date date) {
        this.date = date;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        PenaltyFee that = (PenaltyFee) o;
        return Float.compare(that.MIN_VALUE, MIN_VALUE) == 0 && Float.compare(that.MIN_PUNISHMENT, MIN_PUNISHMENT) == 0 && motive.equals(that.motive) && local.equals(that.local) && date.equals(that.date);
    }

    @Override
    public int hashCode() {
        return Objects.hash(motive, local, MIN_VALUE, MIN_PUNISHMENT, date);
    }

    @Override
    public String toString() {
        return "PenaltyFee{" +
                "motive='" + motive + '\'' +
                ", local='" + local + '\'' +
                ", MIN_VALUE=" + MIN_VALUE +
                ", MIN_PUNISHMENT=" + MIN_PUNISHMENT +
                ", date=" + date +
                '}';
    }

    public Driver getDriver() {
        return driver;
    }

    public void setDriver(Driver driver) {
        this.driver = driver;
    }

    public Vehicle getVehicle() {
        return vehicle;
    }

    public void setVehicle(Vehicle vehicle) {
        this.vehicle = vehicle;
    }
}
