package Team;

import Person.*;

public class Player extends Person {

    private int number;
    private String position;
    private final String FORWARDER;
    private final String MIDFIELDER;
    private final String DEFENSER;
    private boolean injured;
    private int goals;

    public Player(String idNumber, String name, String address, Date birth, int number, String position, String FORWARDER, String MIDFIELDER, String DEFENSER, boolean injured, int goals) {
        super(idNumber, name, address, birth);
        this.number = number;
        this.position = position;
        this.FORWARDER = FORWARDER;
        this.MIDFIELDER = MIDFIELDER;
        this.DEFENSER = DEFENSER;
        this.injured = injured;
        this.goals = goals;
    }

    public int getNumber() {
        return number;
    }

    public void setNumber(int number) {
        this.number = number;
    }

    public String getPosition() {
        return position;
    }

    public void setPosition(String position) {
        this.position = position;
    }

    public String getFORWARDER() {
        return FORWARDER;
    }

    public String getMIDFIELDER() {
        return MIDFIELDER;
    }

    public String getDEFENSER() {
        return DEFENSER;
    }

    public boolean isInjured() {
        return injured;
    }

    public void setInjured(boolean injured) {
        this.injured = injured;
    }

    public int getGoals() {
        return goals;
    }

    public void setGoals(int goals) {
        this.goals = goals;
    }

    @Override
    public String toString() {
        return "Player{" +
                "number=" + number +
                ", position='" + position + '\'' +
                ", FORWARDER='" + FORWARDER + '\'' +
                ", MIDFIELDER='" + MIDFIELDER + '\'' +
                ", DEFENSER='" + DEFENSER + '\'' +
                ", injured=" + injured +
                ", goals=" + goals +
                '}';
    }
}
