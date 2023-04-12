package Teorica.Exceptions;

public class OverWithdrawExecption extends Exception {

    public OverWithdrawExecption() {
    }

    public OverWithdrawExecption(String message) {
        super(message);
    }

    public OverWithdrawExecption(String message, Throwable cause) {
        super(message, cause);
    }

    public OverWithdrawExecption(Throwable cause) {
        super(cause);
    }

    public OverWithdrawExecption(String message, Throwable cause, boolean enableSuppression, boolean writableStackTrace) {
        super(message, cause, enableSuppression, writableStackTrace);
    }
}
