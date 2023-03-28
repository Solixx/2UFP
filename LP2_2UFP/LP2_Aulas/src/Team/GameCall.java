package Team;

import Person.Date;

import java.util.ArrayList;
import java.util.HashMap;

public class GameCall {

    private Date date;
    private HashMap playerGoals;
    private ArrayList<Team> teams =  new ArrayList<Team>(2);
    private ArrayList<Player> callHomeTeam;
    private ArrayList<Player> callVisitingTeam;

    public Player joinPlayer(int number, String Team){
        if(this.teams.get(0).equals(Team)){
            for (Player p: this.teams.get(0).getPlayers()) {
                if(p.getNumber() == number) return p;
            }
        } else{
            for (Player p: this.teams.get(1).getPlayers()) {
                if(p.getNumber() == number) return p;
            }
        }
        return null;
    }

    public boolean addPlayerGoal(int number, String team){
        Player p = joinPlayer(number, team);
        if(p == null)   return false;
        else{
            p.setGoals(p.getGoals()+1);
            return true;
        }
    }

    public ArrayList findPlayerScoredMoreGoals(){
        return null;
    }

    public GameCall(Date date, ArrayList<Team> teams, ArrayList<Player> callHomeTeam, ArrayList<Player> callVisitingTeam) {
        this.date = date;
        this.teams = teams;
        this.callHomeTeam = callHomeTeam;
        this.callVisitingTeam = callVisitingTeam;
    }

    public Date getDate() {
        return date;
    }

    public void setDate(Date date) {
        this.date = date;
    }

    public HashMap getPlayerGoals() {
        return playerGoals;
    }

    public void setPlayerGoals(HashMap playerGoals) {
        this.playerGoals = playerGoals;
    }

    public ArrayList<Team> getTeams() {
        return teams;
    }

    public void setTeams(ArrayList<Team> teams) {
        this.teams = teams;
    }

    public ArrayList<Player> getCallHomeTeam() {
        return callHomeTeam;
    }

    public void setCallHomeTeam(ArrayList<Player> callHomeTeam) {
        this.callHomeTeam = callHomeTeam;
    }

    public ArrayList<Player> getCallVisitingTeam() {
        return callVisitingTeam;
    }

    public void setCallVisitingTeam(ArrayList<Player> callVisitingTeam) {
        this.callVisitingTeam = callVisitingTeam;
    }

    @Override
    public String toString() {
        return "GameCall{" +
                "date=" + date +
                ", playerGoals=" + playerGoals +
                ", teams=" + teams +
                ", callHomeTeam=" + callHomeTeam +
                ", callVisitingTeam=" + callVisitingTeam +
                '}';
    }
}
