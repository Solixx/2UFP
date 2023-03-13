package Teorica._03_Collections;

import edu.princeton.cs.algs4.StdOut;

import java.util.ArrayList;
import java.util.Random;

public class LottoBagArrayList {

    public static final int MIN_NUM = 1;
    public static final int MAX_NUM = 90;
    private ArrayList<Integer> bagInts = new ArrayList<>();
    private final Random rand = new Random();

    public LottoBagArrayList(){
        rand.setSeed(System.currentTimeMillis());
        for (int i = 1; i <= MAX_NUM; i++){
            while (!this.addLottoNumber((rand.nextInt(MAX_NUM)+MIN_NUM))) continue;
        }
    }

    public boolean addLottoNumber(int n){
        if(!this.bagInts.contains(n)){
            this.bagInts.add(n);
            return true;
        }
        return false;
    }

    public int numberRemainingBalls(){
        return this.bagInts.size();
    }

    public int[] toIntArray(){
        int[] arrInt = new int[this.bagInts.size()];

        for (int i = 0; i < arrInt.length; i++){
            arrInt[i] = this.bagInts.get(i);
        }
        return arrInt;
    }

    public int removeLottoNumberAtIndex(int index){
        if(index >= 0 && index < this.numberRemainingBalls()) return this.bagInts.remove(index);
        return -1;
    }

    public int removeLottoNumberRandomly(){
        int index = rand.nextInt(this.numberRemainingBalls());
        return removeLottoNumberAtIndex(index);
    }

    public static void main(String[] args) {
        LottoBagArrayList lotto = new LottoBagArrayList();

        while (lotto.numberRemainingBalls() > 0){
            StdOut.println(lotto.removeLottoNumberRandomly());
        }
    }
}
