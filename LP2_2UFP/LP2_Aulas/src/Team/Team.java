package Team;

import Person.Date;
import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.StdOut;

import java.util.ArrayList;
import java.util.HashMap;

public class Team implements TeamManagementI{

    private String name;
    private ArrayList<Player> players;
    private ArrayList<GameCall> gameCalls;

    public GameCall createGameCall(Date d, Team team){
        ArrayList<Team> teams = new ArrayList<Team>(2);
        teams.add(this);
        teams.add(team);
        return new GameCall(d, teams, this.players, team.getPlayers());
    }
    public  void addGameCall(GameCall gc){
        for (GameCall g: this.getGameCalls()) {
            if(gc.getDate().equals(g.getDate()))  return;
        }
        this.getGameCalls().add(gc);
    }
    public GameCall findGame(Date d){
        for (GameCall g: this.getGameCalls()) {
            if(g.getDate().compareTo(d) == 1)  return g;
        }
        return null;
    }
    public ArrayList<Player> findPlayers(String position){
        ArrayList<Player> rP = new ArrayList<Player>();
        for (Player p: this.getPlayers()) {
            if(p.getPosition().equals(position))    rP.add(p);
        }
        return rP;
    }
    public Player findPlayerWithMoreGoals(){
        int max = 0;
        for (Player p: this.players) {
            if (p.getGoals() > max){
                max = p.getGoals();
            }
        }
        for (Player p: this.players) {
            if(p.getGoals() == max) return p;
        }
        return null;
    }
    public  Player findPlayer(int number){
        for (Player p: this.players) {
            if(p.getNumber() == number) return p;
        }
        return null;
    }

    public Team(String name, ArrayList<Player> players, ArrayList<GameCall> gameCalls) {
        this.name = name;
        this.players = players;
        this.gameCalls = gameCalls;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public ArrayList<Player> getPlayers() {
        return players;
    }

    public void setPlayers(ArrayList<Player> players) {
        this.players = players;
    }

    public ArrayList<GameCall> getGameCalls() {
        return gameCalls;
    }

    public void setGameCalls(ArrayList<GameCall> gameCalls) {
        this.gameCalls = gameCalls;
    }

    @Override
    public void hirePlayer(Player p) {
        this.players.add(p);
    }

    @Override
    public Player sellPlayer(int number) {
        Player p = this.findPlayer(number);
        this.players.remove(p);
        return p;
    }

    @Override
    public Player transferPlayer(int number, TeamManagementI team) {
        Player p = this.findPlayer(number);
        team.hirePlayer(p);
        this.players.remove(p);
        return p;
    }

    @Override
    public String toString() {
        return "Team{" +
                "name='" + name + '\'' +
                ", players=" + players +
                ", gameCalls=" + gameCalls +
                '}';
    }

    public static void main(String[] args) {
        ArrayList<Player> jogadoresP = new ArrayList<>();
        ArrayList<GameCall> gamesP = new ArrayList<>();
        Player p1 = new Player("1","Joao","nao sei",new Date((short) 1,(short) 1,(short)1),10,"Striker","9","nao joga","nao joga",false,5);
        Team t1 = new Team("Porto",jogadoresP, gamesP);
        t1.players.add(p1);
        ArrayList<Player> jogadoresB = new ArrayList<>();
        Player p2 = new Player("1","Andre","nao sei",new Date((short) 1,(short) 1,(short)1),20,"Midfielder","nao joga","10","nao joga",false,5);
        Team t2 = new Team("Boavista",jogadoresB, gamesP);
        t2.players.add(p2);
        GameCall g1 = t1.createGameCall(new Date((short) 10,(short) 10,(short)10),t2);
        t1.addGameCall(g1);
        t2.addGameCall(g1);
        for (int i = 0; i < g1.getTeams().size() ; i++) {
            StdOut.println(g1.getTeams().get(i).getName());
        }
        StdOut.println(t1.findGame(new Date((short) 10,(short) 10,(short)10)));
        StdOut.println(t1.findPlayers("Striker"));
        StdOut.println(g1.addPlayerGoal(10,"Porto"));
        t1.hirePlayer(p2);
        for (int i = 0; i < jogadoresP.size() ; i++) {
            StdOut.println(t1.players.get(i).toString());
        }
    }
}
