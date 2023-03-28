package Team;

public interface TeamManagementI {

    public void hirePlayer(Player p);
    public Player sellPlayer(int number);
    public Player transferPlayer(int number, TeamManagementI team);
}
