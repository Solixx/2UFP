package com.example._06_gui_javafx.bt;

import java.util.Date;

public class SeverePenaltyFee extends PenaltyFee {
    private final String PARKING_VIOLATION;
    private final String PROHIBITION_ON_OVERTAKING;

    public SeverePenaltyFee(String motive, String local, float MIN_VALUE, float MIN_PUNISHMENT, Date date, String PARKING_VIOLATION, String PROHIBITION_ON_OVERTAKING) {
        super(motive, local, MIN_VALUE, MIN_PUNISHMENT, date);
        this.PARKING_VIOLATION = PARKING_VIOLATION;
        this.PROHIBITION_ON_OVERTAKING = PROHIBITION_ON_OVERTAKING;
    }

    @Override
    public void value() {

    }

    @Override
    public void punishment() {

    }
}
