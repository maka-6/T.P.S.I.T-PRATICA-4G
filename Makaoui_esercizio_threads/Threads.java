package Makaoui_esercizio_threads;

public class Threads {
    public static void main(String[] args) {
        Thread t1 = new Thread(new Runnable() {
            @Override
            public void run() {
                System.out.println(Thread.currentThread().getName());
            }
        });
        t1.start();
        t1.setName("Thread 1");
        System.out.println(Thread.currentThread().getName());
        t1.setPriority(Thread.MAX_PRIORITY);
    }

    public void run() {

    }
}