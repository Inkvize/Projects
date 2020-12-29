public class Thread3 extends Thread {

    @Override
    public void run() {
        System.out.println("„исло в кубе - " + (int) Math.pow(Thread1.num, 3));
    }
}