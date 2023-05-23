package com.example._06_gui_javafx.bt;

import java.util.Date;

public class VerySeverePenaltyFee extends PenaltyFee{
    private final String SPEEDING;

    private final String DRIVING_UNDER_LICENCE;


    public VerySeverePenaltyFee(String motive, String local, float MIN_VALUE, float MIN_PUNISHMENT, Date date, String SPEEDING, String DRIVING_UNDER_LICENCE) {
        super(motive, local, MIN_VALUE, MIN_PUNISHMENT, date);
        this.SPEEDING = SPEEDING;
        this.DRIVING_UNDER_LICENCE = DRIVING_UNDER_LICENCE;
    }

    @Override
    public void value() {

    }

    @Override
    public void punishment() {

    }

    public String getSPEEDING() {
        return SPEEDING;
    }

    public String getDRIVING_UNDER_LICENCE() {
        return DRIVING_UNDER_LICENCE;
    }
}
