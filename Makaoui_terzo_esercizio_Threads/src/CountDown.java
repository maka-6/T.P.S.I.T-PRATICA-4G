public class CountDown extends Thread {
    private int count;

    CountDown(String threadName, int count) {
        super(threadName);
        this.count = count;
    }

    public void run() {
        for (int i = 0; i < count; i++) {
            try{
                System.out.println(count-i);
                Thread.sleep(1000);

            } catch (InterruptedException e) {
                System.out.println(Thread.currentThread().getName() + ": " + i);
            }
        }
    }

    @Override
    public String toString() {
        return "CountDown [count=" + count + "]";
    }
}