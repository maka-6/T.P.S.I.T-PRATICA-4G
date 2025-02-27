import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        System.out.println("Hello, World!");
        Thread thread1 = new CountDown("Hello, World!", 15);
        Thread thread2 = new CountDown("GoodBye, World!", 10);
        thread1.setPriority(Thread.MIN_PRIORITY);
        thread2.setPriority(Thread.MAX_PRIORITY);
        thread1.start();
        thread2.start();

        ArrayList<CountDown> ilMakaoui = new ArrayList<CountDown>();
    }
}