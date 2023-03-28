package GestaoLivros;

public class UtilizadorInexistenteExecption extends Exception{

    public UtilizadorInexistenteExecption() {
    }

    public UtilizadorInexistenteExecption(String message) {
        super(message);
    }

    public UtilizadorInexistenteExecption(String message, Throwable cause) {
        super(message, cause);
    }

    public UtilizadorInexistenteExecption(Throwable cause) {
        super(cause);
    }

    public UtilizadorInexistenteExecption(String message, Throwable cause, boolean enableSuppression, boolean writableStackTrace) {
        super(message, cause, enableSuppression, writableStackTrace);
    }
}
