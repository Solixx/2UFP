package Team;

public class InjuredPlayerExecption extends Exception{

    public InjuredPlayerExecption() {
    }

    public InjuredPlayerExecption(String message) {
        super(message);
    }

    public InjuredPlayerExecption(String message, Throwable cause) {
        super(message, cause);
    }

    public InjuredPlayerExecption(Throwable cause) {
        super(cause);
    }

    public InjuredPlayerExecption(String message, Throwable cause, boolean enableSuppression, boolean writableStackTrace) {
        super(message, cause, enableSuppression, writableStackTrace);
    }
}
