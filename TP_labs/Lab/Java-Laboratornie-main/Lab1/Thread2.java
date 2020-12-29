public class Thread2 extends Thread {

    @Override
    public void run() {
        System.out.println("Число в квадрате - " + (int)Math.pow(Thread1.num,2));
    }
}